/*
 * LINK: https://codeforces.com/problemset/problem/489/B
 * NAME: B. BerSU Ball
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;
    vector<ll> va(n+1);
    for (int i = 1; i <= n; i++) cin >> va[i];
    sort(va.begin(), va.end());

    ll m; cin >> m;
    vector<ll> vb(m+1);
    for (int i = 1; i <= m; i++) cin >> vb[i];
    sort(vb.begin(), vb.end());

    ll dp[102][102] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (abs(va[i] - vb[j]) <= 1) 
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1});
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
