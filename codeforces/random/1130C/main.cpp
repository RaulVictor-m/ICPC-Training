/*
 * LINK: https://codeforces.com/problemset/problem/1130/C
 * NAME: C. Connect
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, x1, x2, y1, y2; cin >> n >> x1 >> y1 >> x2 >> y2;

    ll grid[64][64] = {0};

    for (int i = 1; i <= n; i++) {
        string line; cin >> line;
        for (int j = 1; j <= n; j++) {
            grid[i][j] = line[j-1] == '0';
        }
    }

    vector<pair<ll, ll>> seq1;
    vector<pair<ll, ll>> seq2;

    queue<pair<ll, ll>> qu;
    qu.emplace(x1, y1);

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i = x-1; i <= x+1; i+=2) if (grid[i][y]) qu.emplace(i, y), grid[i][y] = 0;
        for (int i = y-1; i <= y+1; i+=2) if (grid[x][i]) qu.emplace(x, i), grid[x][i] = 0;

        seq1.emplace_back(x, y);
    }

    qu.emplace(x2, y2);

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i = x-1; i <= x+1; i+=2) if (grid[i][y]) qu.emplace(i, y), grid[i][y] = 0;
        for (int i = y-1; i <= y+1; i+=2) if (grid[x][i]) qu.emplace(x, i), grid[x][i] = 0;

        seq2.emplace_back(x, y);
    }

    ll lmin = LONG_LONG_MAX;
    for (auto [ax, ay]: seq1)
        for (auto [bx, by]: seq2)
            lmin = min(lmin, (ax-bx)*(ax-bx)+(ay-by)*(ay-by));

    cout << lmin << endl;
    return 0;
}
