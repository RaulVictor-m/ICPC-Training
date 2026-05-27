/*
 * LINK: https://cses.fi/problemset/task/1653
 * NAME: Elevator Rides
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        i basically treat n as 20bit integer for indexing on the dp
        then the dp is defined as

        dp[i] = max(dp[i^(1)], dp[i^(2)], dp[i^(4)], dp[i^(5)], ...);
        i = 1..2^n

        which cover all possible sets of people to be put in the elevator ride
*/

      // rides, current_weight
vector<array<ll, 2>> dp;
vector<ll> w;
const ll INF = LONG_MAX/3;
int main(void) {
    ll n, x; cin >> n >> x;

    dp.resize((1<<n), {INF, INF});
    dp[0] = {1, 0};
    w.resize(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    for (ll i = 1; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            if (((i >> j)&1)) {
                array<ll, 2> cur = dp[i^(1<<j)];

                if ((w[j]+cur[1]) > x) cur[0]++, cur[1] = w[j];
                else                           cur[1] += w[j];

                dp[i] = min(dp[i], cur);
            }
        }
    }
    cout << dp[(1<<n)-1][0] << endl;
    return 0;
}
