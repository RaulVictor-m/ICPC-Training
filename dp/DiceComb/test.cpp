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

ll dpRec(ll n) {
    if (n < 0) return 0;
    if (dp[n]) return dp[n];

    ll sum = 0;
    for (ll i = 1; i <= 6; i++) {
        sum = (dpRec(n-i) + sum) % MOD;
    }

    return dp[n] = sum;
}

ll dpI(ll n) {
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j <= 6; j++) {
            if ((i - j) < 0) break;
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    return dp[n];
}

int main() {
    for (ll i = 1; i < 1000; i++) {
        memset(dp, 0, sizeof(ll) * MAXN);
        dp[0] = dp[1] = 1;

        ll res1 = dpRec(i);

        memset(dp, 0, sizeof(ll) * MAXN);
        dp[0] = dp[1] = 1;
        ll res2 = dpI(i);

        if (res1 != res2) {
            cout << "code breaks at " << i << endl;
            return -1;
        }
    }

    cout << "OK" << endl;
    return 0;
}
