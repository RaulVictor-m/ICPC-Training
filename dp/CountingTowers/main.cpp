/*
 * LINK: https://cses.fi/problemset/task/2413
 * NAME: Counting Towers
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        2 types of block on the top layer

        type 0 [    ]

        type 1 [ ][ ]

        type 0:
            dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1];

            meaning if the i-th layer is [    ] 
            them all possible configs are

            "dp[i-1][0] * 2":
              |    |    [    ] 
              |    |    [    ]


            "+ dp[i-1][0]":
              [    ]
              [ ][ ]

        type 1:
            dp[i][1] = dp[i-1][1] * 4 + dp[i-1][0];

            meaning if the i-th layer is [ ][ ] 
            them all possible configs are

            "dp[i-1][1] * 4": 
              [ ][ ]    | |[ ]    [ ]| |     | || | 
              [ ][ ]    | |[ ]    [ ]| |     | || | 

            "+ dp[i-1][0]":
              [ ][ ]
              [    ]

         so:
            dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1];
            dp[i][1] = dp[i-1][1] * 4 + dp[i-1][0];
            dp[i] = dp[i][0] + dp[i][1];

        helpful source: https://codeforces.com/blog/entry/98085
*/

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 2;

ll dp[MAXN][3] = {0};

void dpI(int n) {
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 2;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 2; j++) {
            dp[i][0] = (dp[i-1][0]*2 + dp[i-1][1]) % MOD;
            dp[i][1] = (dp[i-1][1]*4 + dp[i-1][0]) % MOD;

            dp[i][2] = (dp[i][0] + dp[i][1]) % MOD;
         }
    }
}

int main(void) {
    int t; cin >> t;

    dpI(MAXN);

    while(t--) {
        int n; cin >> n;
        cout << dp[n][2] << endl;
    }

    return 0;
}
