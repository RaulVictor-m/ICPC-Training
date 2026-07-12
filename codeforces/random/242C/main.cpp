/*
 * LINK: https://codeforces.com/problemset/problem/242/C
 * NAME: C. King's Path
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;

    ll n; cin >> n;

    set<pair<ll, ll>> w_list;

    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;

        for (int j = b; j <= c; j++) w_list.insert({a, j});

    }

    // BFS
    queue<array<ll, 3>> qu; //x, y, dist
    qu.push({x0, y0, 0});
    w_list.erase({x0, y0});

    while (!qu.empty()) {
        auto [x, y, c] = qu.front();
        qu.pop();

        if (x == x1 && y == y1) {
            cout << c << endl;
            return 0;
        }
        // cout << x << " " << y << " " << c << endl;;


        for (ll i = y-1; i <= y+1; i++)
            for (ll j = x-1; j <= x+1; j++)
                if (j == x && i == y) continue;
                else if (w_list.count({j, i})) {
                    w_list.erase({j, i});
                    qu.push({j, i, c+1});
                }
    }
    cout << -1 << endl;

    return 0;
}
