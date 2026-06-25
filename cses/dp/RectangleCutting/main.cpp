/*
 * LINK: https://cses.fi/problemset/task/1744
 * NAME: Rectangle Cutting
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

    dp[1][j] = j - 1;
    dp[i][1] = i - 1;

    if i == j 
        dp[i][j] = 0
    else
        ni = 1..i
        ni = 1..j
        dp[i][j] = min(min(dp[i-ni][j] + dp[ni][j])), min((dp[i][j-nj] + dp[i][nj])))

*/

ll dp[502][502] = {0};

ll dpI(ll a, ll b) {
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {

            if (i == j) { dp[i][j] = 0; continue; }

            for (int ni = 1; ni <= (i/2); ni++)
                dp[i][j] = min((dp[i-ni][j] + dp[ni][j] + 1), dp[i][j]);

            for (int nj = 1; nj <= (j/2); nj++)
                dp[i][j] = min((dp[i][j-nj] + dp[i][nj] + 1), dp[i][j]);
        }
    }

    return dp[a][b];
}

int main(void) {
    int a, b; cin >> a >> b;

    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            dp[i][j] = INT_MAX;

    cout << dpI(a, b) << endl;
    return 0;
}
