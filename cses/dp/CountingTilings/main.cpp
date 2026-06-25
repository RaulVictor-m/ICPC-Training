/*
 * LINK: https://cses.fi/problemset/task/2181
 * NAME: Counting Tilings
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        for this solution refer to this link
        my solution is based on this
        I couldnt explain it any better
        https://codeforces.com/blog/entry/111675

*/
const ll MOD = 1e9 + 7;
ll N;
ll M;

bool valid(int m1, int m2) {
    m1 |= 1 << N;

    for (int i = 0; i < N; i++) {
        int m1b = (m1 >> i)&1;
        int m2b = (m2 >> i)&1;
        if (m1b & m2b) return 0;
        if (!m1b && m2b) continue;

        if (!m1b && !m2b) {
            int m12b = (((m1|m2) >> (++i)) & 1);
            // cout << bitset<4>(m1) << "   " << bitset<4>(m2) << 
            if (m12b) return 0;
        }
    }
    return 1;
}

int valid_masks[(1<<10)+1][(1<<10)+1] = {0};

ll dp[1002][(1<<10)+1] = {0};
ll dpRec(ll m, ll m1) {
    if (dp[m][m1] != -1) return dp[m][m1];
    if (m == M && m1 == 0) return 1;
    if (m == M) return 0;

    ll total_mask = (1 << N);

    ll res = 0;
    for (ll m2 = 0; m2 < total_mask; m2++) {
        if (valid_masks[m1][m2]) res = (res + dpRec(m+1, m2))%MOD;
    }

    return dp[m][m1] = res;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= (1 << N); j++) dp[i][j] = -1;

    for (int i = 0; i <= (1 << N); i++)
        for (int j = 0; j <= (1 << N); j++)
            valid_masks[i][j] = valid(i, j);

    cout << dpRec(0, 0) << endl;

    return 0;
}
