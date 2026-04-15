/*
 * LINK: https://cses.fi/problemset/task/1194
 * NAME: Monsters
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e3+3;
const ll MAXM = 1e3+3;

int n, m; 

char visited[MAXN][MAXM] = {0};
queue<array<int, 2>> qu;
array<int, 2> bfs() {
    while (!qu.empty()) {
        int i = qu.front()[0];
        int j = qu.front()[1];
        bool mons = visited[i][j] == 'M';
        qu.pop();

        if (!mons && (i == 0 || j == 0 || i == (n-1) || j == (m-1))) return {i, j};

        if (j < (m-1) && !visited[i][j+1]) {
            qu.push({i, j+1});
            visited[i][j+1] = mons ? 'M': 'R';
        }

        if (j > 0 && !visited[i][j-1]) {
            qu.push({i, j-1});
            visited[i][j-1] = mons ? 'M': 'L';
        }

        if (i < (n-1) && !visited[i+1][j]) {
            qu.push({i+1, j});
            visited[i+1][j] = mons ? 'M': 'D';
        }

        if (i > 0 && !visited[i-1][j]) {
            qu.push({i-1, j});
            visited[i-1][j] = mons ? 'M': 'U';
        }
    }
    return {-1, -1};
}

int main(void) {
    cin >> n >> m;

    array<int, 2> indexA;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char v; cin >> v;
            if (v == 'A') {
                indexA = {i, j};
                visited[i][j] = 'A';
            } else if (v == 'M') {
                qu.push({i, j});
                visited[i][j] = 'M';
            } else if (v != '.') visited[i][j] = '#';
        }
    }
    qu.push(indexA);

    auto res = bfs();
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (visited[i][j] == 0) cout << '.';
    //         else cout << visited[i][j];
    //     }
    //     cout << endl;
    // }
    if (res[0] == -1) {
        cout << "NO" << endl;
        return 0;
    }

    stack<char> resp;
    for (int i = res[0], j = res[1]; visited[i][j] != 'A';) {
        resp.push(visited[i][j]);
        if (visited[i][j] == 'R') j--; else
        if (visited[i][j] == 'L') j++; else
        if (visited[i][j] == 'U') i++; else
        if (visited[i][j] == 'D') i--;
    }

    cout << "YES" << endl;
    cout << resp.size() << endl;
    while (!resp.empty()) {
        cout << resp.top(); 
        resp.pop();
    }
    cout << endl;
    return 0;
}
