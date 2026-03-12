/*
 * LINK: https://cses.fi/problemset/task/1634
 * NAME: Minimizing Coins
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    dp[x] = min(dp[x - c1], dp[x - c2], ... dp[x - ci]) + 1
*/

const ll MAXN = 1e6 + 1;
const ll MAXX = 1e6 + 1;
ll n;

ll coins[MAXN] = {0};

ll dp[MAXX] = {0};
ll dpI(ll x) {
    for (ll i = 1; i <= x; i++) {
        for (ll j = 0; j < n; j++) {
            if (i - coins[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return dp[x];
}

ll dpRec(ll x) {
    if (x < 0) return INT_MAX;
    if (dp[x] != INT_MAX) return dp[x];

    ll res = INT_MAX;
    for (ll i = 0; i < n; i++) {
        res = min(res, dpRec(x - coins[i]) + 1);
    }

    return dp[x] = res;
}

int main(void) {
    ll x; cin >> n >> x;

    for (ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (ll i = 1; i <= x; i++) {
        dp[i] = INT_MAX; // Biase for min function first iterations
    }

    const ll res = dpI(x);
    cout << (res == INT_MAX ? -1 : res) << endl;

    return 0;
}
