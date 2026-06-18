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
        2: dfs them to find the only correct order from 1 to N
        3: take weights and coord compress them to fit the segtree
        4: use the order found in step 2 to find LIS for every index
        5: be happy after that

*/
namespace seg {
    long t[100000*2+2] = {0}, n = 0;

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
vector<long> order;

void dfs(long i) {
    if (visited[i]) return;
    visited[i] = 1;
    order.push_back(i);
    for (auto v: graph[i]) dfs(v);
}

int main(void) {
    long n; cin >> n;
    graph.resize(n+1), visited.resize(n+1);
    vector<long> weights(n+1);

    for (int i = 1; i < n; i++) {
        long v; cin >> v;
        graph[i+1].push_back(v);
        graph[v].push_back(i+1);
    }

    // read and compress weights
    {
        for (int i = 1; i <= n; i++) {
            cin >> weights[i];
        }
        auto lset = weights;
        sort(lset.begin(), lset.end());
        lset.resize(unique(lset.begin(), lset.end())-lset.begin());

        unordered_map<long, long> lmap;
        for (int i = 1; i <= lset.size(); i++) lmap[lset[i-1]] = i;

        for (auto &v: weights) v = lmap[v]; //compression
    }

    dfs(1); // finding the order of the array for LIS

    vector<long> ans(n+1);
    // compute LIS
    {
        seg::build(n+1); // max val is n+1 after compression
        for (auto v: order) {
            long lmax = seg::query(0, weights[v]);
            ans[v] = lmax+1;
            seg::update(weights[v], seg::t[n+1+weights[v]]+1);
        }
    }

    for (int i = 2; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
