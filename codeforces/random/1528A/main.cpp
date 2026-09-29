/*
 * LINK: https://codeforces.com/problemset/problem/1528/A
 * NAME: A. Parsa's Humongous Tree
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
        vector<array<int, 2>> rgs(n+1);
        vector<vector<int>> adj(n+1);

        rep(i, 1, n+1) cin >> rgs[i][0] >> rgs[i][1];

        rep(i, 1, n) {
            int a, b; cin >> a >> b;
            adj[a].pb(b), adj[b].pb(a);
        }

        vector<array<ll, 2>> dp(n+1, {-1, -1});
        auto dfs = [&](this auto&& self, int v, int p, bool m) -> ll {
            if (dp[v][m] != -1) return dp[v][m];

            ll total = 0;
            auto vx = rgs[v][m];

            for (auto u: adj[v]) {
                if (u == p) continue;
                auto ux_mx = rgs[u][1], ux_mn = rgs[u][0];

                auto umx = abs(ux_mx-vx)+self(u, v, 1);
                auto umn = abs(ux_mn-vx)+self(u, v, 0);

                total += max(umx, umn);
            }

            return dp[v][m] = total;
        };

        cout << max(dfs(1, 0, 0), dfs(1, 0, 1)) << endl;
    }
    return 0;
}

