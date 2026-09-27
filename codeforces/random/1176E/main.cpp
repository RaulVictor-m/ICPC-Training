/*
 * LINK: https://codeforces.com/problemset/problem/1176/E
 * NAME: E. Cover it!
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1);
        array<vector<int>, 2> comps;

        rep(i, 0, m) {
            int a, b; cin >> a >> b;
            adj[a].pb(b), adj[b].pb(a);
        }

        auto dfs = [&](this auto&& self, int v, int c) -> void {
            vis[v] = 1, comps[c].pb(v);
            for (auto u: adj[v]) if (!vis[u]) self(u, c^1);
        };

        dfs(1, 0);

        if (comps[0].size() > comps[1].size()) swap(comps[0], comps[1]);

        cout << comps[0].size() << endl;
        for (auto v: comps[0]) cout << v << " ";
        cout << endl;
    }
    return 0;
}

