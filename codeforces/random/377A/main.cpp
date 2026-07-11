/*
 * LINK: https://codeforces.com/problemset/problem/377/A
 * NAME: A. Maze
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll keep[512][512] = {0};
ll grid[512][512] = {0};
ll vis[512][512] = {0};

void dfs(ll i, ll j, ll &k) {
    if (!k || !grid[i][j] || vis[i][j]) return;

    vis[i][j] = 1, keep[i][j] = 1, k--;
    dfs(i, j+1, k), dfs(i, j-1, k);
    dfs(i+1, j, k), dfs(i-1, j, k);
}

int main(void) {
    ll n, m, k; cin >> n >> m >> k;

    string line;
    ll i1=1, j1=1, count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> line;
        for (int j = 1; j <= m; j++) 
            if (line[j-1] == '.')
                grid[i][j] = 1, j1 = j, i1 = i, count++;
    }

    count -= k;
    dfs(i1, j1, count);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) 
            if (!grid[i][j]) cout << '#'; else
            if (!keep[i][j]) cout << 'X'; 
            else             cout << '.';
        cout << endl;
    }

    return 0;
}
