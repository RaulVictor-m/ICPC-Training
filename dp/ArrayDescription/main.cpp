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

ll m_array[MAXN] = {0};
ll dp[MAXN][MAXM] = {0};

ll dpI(ll n, ll m) {

}

int main(void) {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >>  m_array[i];
    }
    return 0;
}
