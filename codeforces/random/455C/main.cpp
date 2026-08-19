/*
 * LINK: https://codeforces.com/problemset/problem/455/C
 * NAME: C. Civilization
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3e5+5;
namespace uf {
    int par[N], sz[N], dim[N];

    void build(int n) {
        for (int i = 1; i <= n; i++)  par[i] = i, sz[i] = 1;
    }

    int find(int v) {
        return par[v] = (par[v] == v ? v : find(par[v]));
    }

    bool join(int a, int b, bool d) {
        a = find(a), b = find(b);

        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);

        if (d) dim[a] = max({dim[a], dim[b], (dim[a]+1)/2+(dim[b]+1)/2+1});

        sz[a] += sz[b], par[b] = a;

        return true;
    }
}

vector<vector<int>> adj(N);
int dist(int v, int p, vector<int> &d) {
    int mx = v;
    for (auto u: adj[v]) {
        if (u == p) continue; 
        d[u] = d[v]+1;
        int res = dist(u, v, d);

        if (d[mx] < d[res]) mx = res;
    }
    return mx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;

    uf::build(n);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        uf::join(a, b, 0);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> d(n+1, -1e6);
    for (int r = 1; r <= n; r++) {
        if (r != uf::find(r)) continue;
        d[r] = 0;
        int da = dist(r, 0, d);

        d[da] = 0;
        int db = dist(da, 0, d);

        uf::dim[r] = d[db];
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            cout << uf::dim[uf::find(x)] << endl;
        } else {
            int x, y; cin >> x >> y;
            uf::join(x, y, 1);
        }
    }

    return 0;
}
