/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/I
 * NAME: I. Interlingual Intermediaries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> graph(n);

    for (ll i = 0; i < n; i++) {
        ll size; cin >> size;
        for (ll j = 0; j < size; j++) {
            ll v; cin >> v;
            graph[i].push_back(v);
        }
    }

    // Floyd Warshall
    ll dp[31][31];
    for (ll i = 0; i <= m; i++) 
        for (ll j = 0; j <= m; j++) dp[i][j] = LONG_MAX/4;

    for (ll i = 1; i <= m; i++) dp[i][i] = 0;
    for (auto g: graph) {
        for (ll i = 0; i < g.size(); i++)
            for (ll j = i+1; j < g.size(); j++)
                dp[g[i]][g[j]] = 1, dp[g[j]][g[i]] = 1;
    }

    for (ll k = 1; k <= m; k++) {
        for (ll i = 1; i <= m; i++) {
            for (ll j = 1; j <= m; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                dp[j][i] = dp[i][j];
            }
        }
    }

    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= m; j++) {
            cout << (dp[i][j] < LONG_MAX/4 ? dp[i][j] : -1) << "\t";
        }
        cout << endl;
    }

    // queries
    while (q--) {
        ll a, b; cin >> a >> b;
        a--, b--;

        ll lmin = LONG_MAX/4;
        for (auto ea: graph[a]) {
            for (auto eb: graph[b]) {
                lmin = min(lmin, dp[ea][eb]);
            }
        }

        cout << (lmin < LONG_MAX/4 ? lmin: -1) << endl;
    }
    return 0;
}
