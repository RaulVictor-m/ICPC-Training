/*
 * LINK: https://br.spoj.com/problems/MINHOCA2/
 * NAME: MINHOCA2 - Campo de Minhocas
 * STATUS: BROKEN
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

ll grid[1002][1002] = {0};
ll dp[1002][1002][2] = {0};

int dpI(int n, int m) {
    if (n == m and n == 1) return grid[1][1];

    for (int j = 1; j <= m; j++)
        dp[1][j][0] = dp[1][j-1][0] + grid[1][j];


    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][0] = max({dp[i-1][j][0], dp[i-1][j][1], dp[i][j-1][0]}) + grid[i][j];
        }

        for (int j = m; j > 0; j--) {
            dp[i][j][1] = max({dp[i-1][j][0], dp[i-1][j][1], dp[i][j+1][1]}) + grid[i][j];
        }
    }

    return max(dp[n][m][0], dp[n][m][1]);
}

int main(void) {
    int t = 0;
    while (++t) {
        int n, m; cin >> n >> m;
        if (!n && !m) break;


        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) cin >> grid[i][j];

        for (int i = 1; i <= n+1; i++) 
            for (int j = 1; j <= m+1; j++) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }

        cout << "Teste " << t << "\n" << dpI(n, m) << "\n\n";

    }
    return 0;
}
