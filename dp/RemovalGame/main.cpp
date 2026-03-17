/*
 * LINK: https://cses.fi/problemset/task/1097
 * NAME: Removal Game
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        right = (sum(start+1:end) - dp(start+1, end)) + coin[start]
        left  = (sum(start:end-1) - dp(start, end-1)) + coin[start]


        dp(start, end) = max(right, left);

        right is basically the total of the area start+1 -- end minus 
        the dp that area which gives the maximum value possible for a player
        that plays in that condition
        left is basically the same but to the other side

*/
const ll MAXN = 5001;

ll dp[MAXN][MAXN] = {0};
ll vals[MAXN] = {0};
ll prefix[MAXN] = {0};

ll dpRec(int start, int end) {
    // if (start > end) return 0;
    if (dp[start][end] != INT_MIN) return dp[start][end];
    if (start == end) return dp[start][end] = vals[start];

    ll right = ((prefix[end] - prefix[start]) - dpRec(start + 1, end)) + vals[start];
    ll left  = ((prefix[end-1] - prefix[start-1]) - dpRec(start, end - 1)) + vals[end];

    return dp[start][end] = max(right, left);
}

int main(void) {
    int n; cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
        prefix[i] = prefix[i-1] + vals[i];
    }

    cout << dpRec(1, n) << endl;

    return 0;
}
