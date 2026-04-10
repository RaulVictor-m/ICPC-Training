/*
 * LINK: https://cses.fi/problemset/task/1192
 * NAME: Counting Rooms
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        just a simple bfs over any .
        then increment by 1 when not more dots are connects 
        and then try to find another . and repeat

*/

bool grid[1001][1001] = {0};
bool visited[1001][1001] = {0};
ll n, m; 

ll bfs(int i, int j) {
    if (!grid[i][j]) return 0;
    if (visited[i][j]) return 0;

    queue<array<ll,2>> qu;
    qu.push({i, j});

    while (!qu.empty()) {
        int ii = qu.front()[0];
        int jj = qu.front()[1];
        qu.pop();

        if (ii >= n) continue;
        if (jj >= m) continue;
        if (!grid[ii][jj]) continue;
        if (visited[ii][jj]) continue;

        visited[ii][jj] = 1;

        qu.push({ii, jj+1});
        qu.push({ii, jj-1});
        qu.push({ii+1, jj});
        qu.push({ii-1, jj});
    }

    return 1;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char v; cin >> v;
            grid[i][j] = v == '.';
        }
    }

    ll count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count += bfs(i, j);
        }
    }

    cout << count << endl;

    return 0;
}
