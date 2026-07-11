/*
 * LINK: https://codeforces.com/problemset/problem/510/B
 * NAME: B. Fox And Two Dots
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char grid[64][64] = {0};
int vis[64][64] = {0}; // 0: not visited, 1: on stack, 2: left

bool dfs(ll i, ll j, ll p_i, ll p_j, char col) {
    if (grid[i][j] != col) return 0;
    if (vis[i][j] == 2) return 0;
    if (vis[i][j] == 1) return 1;

    vis[i][j] = 1;
    if (i-1 != p_i || j   != p_j) 
        if (dfs(i-1, j, i, j, col)) return 1;

    if (i+1 != p_i || j   != p_j) 
        if (dfs(i+1, j, i, j, col)) return 1;

    if (i   != p_i || j-1 != p_j) 
        if (dfs(i, j-1, i, j, col)) return 1;

    if (i   != p_i || j+1 != p_j) 
        if (dfs(i, j+1, i, j, col)) return 1;

    vis[i][j] = 2;
    return 0;
}

int main(void) {
    ll n, m; cin >> n >> m;

    string line;
    for (int i = 1; i <= n; i++) {
        cin >> line;
        for (int j = 1; j <= m; j++) {
            grid[i][j] = line[j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dfs(i, j, 0, 0, grid[i][j])) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
