/*
 * LINK: https://cses.fi/problemset/task/1672
 * NAME: Shortest Routes II
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/
const ll MAXN = 502;
const ll MAXM = MAXN*MAXN;
const ll INF = LONG_LONG_MAX/3;

ll graph[MAXN][MAXN] = {0};

int main(void) {
    int n, m, q; cin >> n >> m >> q;

    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++) graph[i][j] = i == j ? 0: INF;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], (ll)c);
        graph[b][a] = graph[a][b];
    }

    // floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << (graph[a][b] != INF ? graph[a][b] : -1) << endl;
    }

    return 0;
}
