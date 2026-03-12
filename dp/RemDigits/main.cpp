/*
 * LINK: https://cses.fi/problemset/task/1637
 * NAME: Removing Digits
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    dp[i] = min(dp[i - digit(1)], dp[i - digit(2)], ... dp[i - digit(i)]) + 1
*/

const ll MAXN = 1e6+1;

ll dp[MAXN] = {0};

ll dpI(ll n) {
    for (ll i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        ll acc10 = 1;
        for (ll j = 0; j <= 6; j++) {
            ll ni = i/acc10;
            acc10 *= 10;
            if (ni == 0) break;

            ll digit = ni % 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }

    return dp[n];
}

int main(void) {
    ll n; cin >> n;
    cout << dpI(n) << endl;
    return 0;
}
