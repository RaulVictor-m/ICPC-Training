/*
 * LINK: https://codeforces.com/problemset/problem/1611/D
 * NAME: D. Weights Assignment For Tree Edges
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
        int n; cin >> n;

        vector<vector<int>> adj(n+1);
        vector<int> ord(n+1), dist(n+1);

        int root = 0;
        rep(i, 1, n+1) {
            int v; cin >> v;
            if (v == i) root = i;
            else        adj[v].pb(i);
        }

        rep(i, 0, n) {
            int v; cin >> v;
            ord[v] = i;
        }

        auto dfs = [&](this auto&& self, int v, int d) -> bool {
            if (d != ord[v]) return false;

            for (auto u: adj[v]) {
                if (ord[u] <= d) return false;
                if (!self(u, ord[u])) return false;
                dist[u] = ord[u]-d;
            }
            return true;
        };

        if (!dfs(root, 0)) cout << -1;
        else rep(i, 1, n+1) cout << dist[i] << " ";
        cout << endl;
    }
    return 0;
}

