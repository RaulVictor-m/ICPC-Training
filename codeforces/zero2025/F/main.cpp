/*
 * LINK: https://codeforces.com/gym/105925/problem/F
 * NAME: F
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    int n; cin >> n;

    int dp[8002][5] = {0};
    dp[4000][0] = 1;

    for (int i = 0; i < n; i++) {
        int v; cin >> v; 

        for (int w = min(4000, 4000+v); w >= max(-4000, -4000-v); w--) {
            for (int j = 4; j > 0; j--) {
                dp[w+4000][j] += dp[(w-v)+4000][j-1];
            }
        }
    }

    // for (int i = -30; i < 30; i++) {

    //     for (int j = 0; j < 5; j++) {
    //         cout << dp[i+4000][j] << " ";
    //     }
    //     cout << endl;
    // }

    int q; cin >> q;
    while (q--) {
        int v; cin >> v;
        cout << dp[v+4000][4]-1;
    }
    return 0;
}
