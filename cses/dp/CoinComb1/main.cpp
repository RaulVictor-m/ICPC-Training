/*
 * LINK: https://cses.fi/problemset/task/1635
 * NAME: Coin Combinations I
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    dp[x] = dp[x - c1] + dp[x - c2] + ... dp[x - ci]
*/

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 1;
const ll MAXX = 1e6 + 1;

ll coins[MAXN] = {0};

ll n;
ll dp[MAXX] = {0};

ll dpI(ll x) {
    for (ll i = 1; i <= x; i++) {
        for (ll j = 0; j < n; j++) {
            const ll ci = coins[j];
            if ((i - ci) < 0) continue;

            dp[i] = (dp[i] + dp[i - ci]) % MOD;
        }
    }

    return dp[x];
}

int main(void) {
    ll x; cin >> n >> x;

    for (ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;
    cout << dpI(x) << endl;
    return 0;
}
