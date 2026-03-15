/*
 * LINK: https://cses.fi/problemset/task/3403
 * NAME: Longest Commum Subsequence
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

    if list1[i] == list2[j]
        dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1)
    else 
        dp[i][j] = max(dp[i-1][j], dp[i][j-1])

*/
const ll MAXN = 1000+2, MAXM = 1000+2;

ll list1[MAXN] = {0};
ll list2[MAXM] = {0};
ll dp[MAXN][MAXM] = {0};

ll dpI(ll n, ll m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (list1[i] == list2[j])
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1});
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}


int main(void) {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> list1[i];
    for (int i = 1; i <= m; i++) cin >> list2[i];


    int cont = dpI(n, m);
    cout << cont << endl;

    stack<ll> p_list;
    for (int i = n, j = m; i > 0 && j > 0 && cont > 0;) {
        if      (dp[i][j] == dp[i][j-1]) j--;
        else if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == (dp[i-1][j-1] + 1)) {
            p_list.push(list1[i]);
            cont--;
            i--;
        }
    }

    for (; !p_list.empty(); p_list.pop())  cout << p_list.top() << " ";

    cout << endl;
    return 0;
}
