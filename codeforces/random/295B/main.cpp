/*
 * LINK: https://codeforces.com/problemset/problem/295/B
 * NAME: B. Greg and Graph
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;
    ll dp[501][501] = {0};
    vector<ll> vs(n);
    vector<bool> n_ok(n);

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> dp[i][j];

    for (ll i = 0; i < n; i++) {
        cin >> vs[i]; 
        vs[i]--;
        n_ok[vs[i]] = 1;
    }

    reverse(vs.begin(), vs.end());

    vector<ll> ans;
    for (auto k: vs) {
        n_ok[k] = 0;
        ans.push_back(0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];

                if (!(n_ok[i] || n_ok[j])) ans.back() += dp[i][j];
            }
        }
    }
    reverse(ans.begin(), ans.end());

    for (auto v: ans) cout << v << " "; cout << endl;
    return 0;

}
