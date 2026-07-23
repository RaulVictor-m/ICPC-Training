/*
 * LINK: https://codeforces.com/problemset/problem/505/B
 * NAME: B. Mr. Kitayuta's Colorful Graph
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n, m; cin >> n >> m;
    bitset<100> dp[101][101];
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b][--c] = 1;
        dp[b][a][c] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] |= (dp[i][k]&dp[k][j]);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << dp[a][b].count() << '\n';
    }

    return 0;
}
