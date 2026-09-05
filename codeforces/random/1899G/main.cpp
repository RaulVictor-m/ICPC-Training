/*
 * LINK: https://codeforces.com/problemset/problem/1899/G
 * NAME: G. Unusual Entertainment
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;

const int N = 1e5+5;

vector<vector<int>> adj(N);
vector<int> per(N), tin(N), tout(N), ver(N), sz(N), hv(N);
vector<bool> ans(N);
vector<vector<array<int, 3>>> q;

int t = 1;
void pre(int v, int p) {
    tin[v] = t, ver[t++] = v, sz[v] = 1;

    for (auto u: adj[v]) {
        if (u == p) continue;
        pre(u, v);
        sz[v] += sz[u];

        if (sz[hv[v]] < sz[u]) hv[v] = u;
    }

    tout[v] = t-1;
}

void dfs(int v, int p, bool keep) {
    static set<int> sack;
    for (auto u: adj[v])
        if (u != p && u != hv[v]) dfs(u, v, false);

    if (hv[v]) dfs(hv[v], v, true);

    for (auto u: adj[v])
        if (u != p && u != hv[v])
            for (int t = tin[u]; t <= tout[u]; t++)
                sack.insert(per[ver[t]]);

    sack.insert(per[v]);

    for (auto [l, r, id]: q[v]) {
        auto it = sack.lower_bound(l);
        ans[id] = (it != sack.end() && (*it) <= r);
    }

    if (!keep) sack.clear();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) {
        int n, m; cin >> n >> m;

        //clean up
        [&](auto&... v) { (v.clear(), ...), (v.resize(n+1), ...); }
        (per, tin, tout, ver, sz, hv, adj, q);
        t = 1;

        //input
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1, p; i <= n; i++)
            cin >> p, per[p] = i;

        for (int i = 1; i <= m; i++) {
            int l, r, x; cin >> l >> r >> x;
            q[x].push_back({l, r, i});
        }

        //solve
        pre(1, 0);
        dfs(1, 0, 0);
        for (int i = 1; i <= m; i++)
            cout << (ans[i] ? "YES\n" : "NO\n");
        cout << '\n';
    }

    return 0;
}
