/*
 * LINK: https://cses.fi/problemset/task/1750
 * NAME: Planets Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    https://cp-algorithms.com/graph/lca_binary_lifting.html

*/

int conn[200000][30] = {0};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q; cin >> n >> q;

    for (int i = 1; i <= n; i++) cin >> conn[i][0];

    for (int k = 1; k < 30; k++)
        for (int i = 1; i <= n; i++)
            conn[i][k] = conn[conn[i][k-1]][k-1];

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        for (int k = 29; k >= 0 ; k--) {
            if (b & (1<<k)) a = conn[a][k];
        }
        cout << a << endl;
    }

    return 0;
}
