/*
 * LINK: https://cses.fi/problemset/task/1746/
 * NAME: Array Description
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
     v = current value
     i = item
     j = value

    if v == j
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]

    if v == 0; j = 0..m;
*/

const ll MAXN = 1e5+1;
const ll MAXM = 101;
const ll MOD = 1e9+7;

ll m_array[MAXN] = {0};
ll dp[MAXN][MAXM] = {0};

ll dpI(ll n, ll m) {
    if (n == 1) return m_array[n] == 0 ? m : 1;

    if (m_array[1] == 0) for (int j = 1; j <= m; j++) dp[1][j] = 1;
    else dp[1][m_array[1]] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (m_array[i] == 0 || j == m_array[i]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    if (m_array[n] != 0) return dp[n][m_array[n]];

    ll result = 0;
    for (int j = 1; j <= m; j++) result = (dp[n][j] + result) % MOD;

    return result;
}

int main(void) {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >>  m_array[i];
    }

    cout << dpI(n, m) << endl;
    return 0;
}
