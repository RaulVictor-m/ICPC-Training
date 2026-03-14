/*
 * LINK: https://cses.fi/problemset/task/1639
 * NAME: Edit Distance
 * STATE: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        MOVIE 
        LOVE

        t1[i] == t2[j]:
            dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1])
        else:
            dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1)

*/

const ll MAXN = 5000+2;

ll dp[MAXN][MAXN] = {0};

string textn;
string textm;

ll dpI() {

    for (int i = 1; i <= textn.size(); i++) {
        for (int j = 1; j <= textm.size(); j++) {
            if (textn[i-1] == textm[j-1]) {
                dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]});
                continue;
            } 

            dp[i][j] = min({dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1});
        }
    }
    return dp[textn.size()][textm.size()];
}

int main(void) {
    cin >> textn >> textm;

    for (int i = 0; i <= textn.size(); i++)
            dp[i][0] = i;

    for (int j = 0; j <= textm.size(); j++)
            dp[0][j] = j;

    cout << dpI() << endl;

    return 0;
}
