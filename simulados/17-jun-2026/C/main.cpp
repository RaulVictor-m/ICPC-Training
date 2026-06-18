/*
 * LINK: https://codeforces.com/gym/104555/problem/C
 * NAME: Caminhada na Montanha
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        1: take all nodes in the graph
        2: take weights and coord compress them to fit the segtree
        3: dfs all paths in the graph and do a LIS on every node on the way
           obs: the LIS needs to be backtracked, so before returning the
                recursion put the old result back so that it does not 
                impact the future paths that dont include that node

        be happy after that ;)

*/
namespace seg {
    long t[100000*4] = {0}, n = 0;

    void build (long size) {
        for (int i = (n=size)-1; i > 0; i--) t[i] = max(t[i<<1],t[i<<1|1]);
    }

    void update(long p, long v) {
        for (t[p+=n]=v; p > 1; p>>=1) t[p>>1] = max(t[p], t[p^1]);
    }

    long query(long l, long r) {
        long res = 0;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) res = max(t[--r], res);
            if (l&1) res = max(res, t[l++]);
        }
        return res;
    }
}

vector<vector<long>> graph;
vector<bool> visited;

vector<long> weights;
vector<long> ans;

void backtrackLIS(long i) {
    if (visited[i]) return;
    visited[i] = 1;

    long imax = seg::query(0, weights[i]);

    long old_imax = seg::t[seg::n+weights[i]];
    seg::update(weights[i], imax+1);

    ans[i] = seg::query(0, seg::n); //LIS

    for (auto v: graph[i]) backtrackLIS(v);

    seg::update(weights[i], old_imax);
}

int main(void) {
    long n; cin >> n;
    graph.resize(n+1), visited.resize(n+1), weights.resize(n+1);
    ans.resize(n+1);

    for (int i = 1; i < n; i++) {
        long v; cin >> v;
        graph[i+1].push_back(v);
        graph[v].push_back(i+1);
    }

    // read and compress weights
    for (int i = 1; i <= n; i++) cin >> weights[i];
    auto lset = weights;

    sort(lset.begin(), lset.end());
    lset.resize(unique(lset.begin(), lset.end())-lset.begin());

    for (auto &v: weights)  //compression
        v = lower_bound(lset.begin(), lset.end(), v) - lset.begin();

    seg::build(n+5); // max val is n+1 after compression

    // solve
    backtrackLIS(1);

    for (int i = 2; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
