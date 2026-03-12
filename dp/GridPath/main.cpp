/*
 * LINK: https://cses.fi/problemset/task/1638/
 * NAME: Grid Paths I
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    dp[x][y] = dp[x-1][y] + dp[x][y-1]
*/

const ll MOD = 1e9 + 7;

ll dp[1001][1001] = {0};

ll dpI(ll n) {
    if (dp[1][1] == -1) return 0;
    if (dp[n][n] == -1) return 0;
    dp[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == -1) continue;
            const ll up   = dp[i-1][j] != -1 ? dp[i-1][j] : 0;
            const ll left = dp[i][j-1] != -1 ? dp[i][j-1] : 0;
            dp[i][j] = (up + left) % MOD;
        }
    }
    return dp[n][n];
}

int main(void) {
    ll n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            dp[i][j] = c == '.' ? 0 : -1;
        }
    }

    cout << dpI(n) << endl;
    return 0;
}
