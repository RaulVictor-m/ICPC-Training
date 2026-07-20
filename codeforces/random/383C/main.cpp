/*
 * LINK: https://codeforces.com/problemset/problem/383/C
 * NAME: C. Propagating tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5+5;

namespace seg {
    int t[MAXN*4] = {0}, n = 0;

    void add(int v, int p) {
        for (t[p+=n]+=v; p > 1; p>>=1) t[p>>1] = t[p]+t[p^1];
    }

    int query(int l, int r) {
        int res = 0;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (l&1) res = res + t[l++];
            if (r&1) res = t[--r] + res;
        }
        return res;
    }
}

vector<vector<int>> graph;
vector<int> vs, ht, tin, tout;
int t = 0;

void euler(int v, int p = 0, int h = 1) {
    tin[v] = t++, ht[v] = h;
    for (auto u: graph[v])
        if (u != p) euler(u, v, h+1);

    tout[v] = t++;
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1), vs.resize(n+1); 
    ht.resize(n+1), tin.resize(n+1), tout.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> vs[i];
    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    euler(1);
    seg::n = t+2;
    while (m--) {
        int type, x, v; cin >> type >> x;

        if (type == 1) {
            cin >> v;
            if ((ht[x]%2) == 0) v = -v;
            seg::add(v, tin[x]), seg::add(-v, tout[x]+1);

        } else {
            int val = seg::query(0, tout[x]+1);
            if ((ht[x]%2) == 0) val = -val;

            cout << vs[x] + val << "\n";
        }
    }

    return 0;
}
