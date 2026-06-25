/*
 * LINK: https://cses.fi/problemset/task/1193
 * NAME: Labyrinth
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int n,m;
bool grid[1003][1003] = {0};
char visited[1003][1003] = {0};

int bfs(int i1, int j1, int i2, int j2) {
    queue<array<ll, 4>> qu;
    qu.push({i1, j1, -1, 0});
    while (!qu.empty()) {
        int i = qu.front()[0];
        int j = qu.front()[1];
        int dir = qu.front()[2];
        int count = qu.front()[3];

        qu.pop();

        if (visited[i][j] != 0) continue;
        visited[i][j] = (char)dir;

        if (i == i2 && j == j2) return count;

        if (!visited[i][j+1]) qu.push({i, j+1, 'R', count+1});
        if (!visited[i+1][j]) qu.push({i+1, j, 'D', count+1});
        if (!visited[i][j-1]) qu.push({i, j-1, 'L', count+1});
        if (!visited[i-1][j]) qu.push({i-1, j, 'U', count+1});
    }
    return -1;
}

int main(void) {
    cin >> n >> m;

    int i1, j1, i2, j2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char v; cin >> v;
            if (v == '#') visited[i][j] = v;

            if      (v == 'A') i1 = i, j1 = j;
            else if (v == 'B') i2 = i, j2 = j;
        }
    }

    //boundries check hack
    for (int i = 0; i <= n; i++) visited[i][0] = -1, visited[i][m+1] = -1;
    for (int j = 0; j <= m; j++) visited[0][j] = -1, visited[n+1][j] = -1;


    int res = bfs(i1, j1, i2, j2);
    if (res == -1) {
        cout << "NO" << endl;
        return 0;
    } 

    cout << "YES" << endl;
    cout << res << endl;

    string resp;
    resp.reserve(res);

    for (int i = i2, j = j2; res >= 1; res--) {
        resp += visited[i][j];
        if (visited[i][j] == 'R' ) j--;
        else if (visited[i][j] == 'L' ) j++;
        else if (visited[i][j] == 'D' ) i--;
        else if (visited[i][j] == 'U' ) i++;
    }

    for (int i = resp.size()-1; i >= 0; i--) {
        cout << resp[i];
    }

    cout << endl;

    return 0;
}
