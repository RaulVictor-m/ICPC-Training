/*
 * LINK: https://cses.fi/problemset/task/1633
 * NAME: Dice Combinations
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    dp[n] = dp[n-1] + dp[n-2] + ... dp[n-6]
*/

const ll MAXN = 1e6 + 1;
const ll MOD  = 1e9 + 7;
ll dp[MAXN] = {0};
ll dpI(ll n) {
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j <= 6; j++) {
            if ((i - j) < 0) break;
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    return dp[n];
}

int main(void) {
    ll n; cin >> n;

    dp[0] = dp[1] = 1;
    cout << dpI(n) << endl;
    return 0;
}
