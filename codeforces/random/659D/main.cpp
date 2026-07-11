/*
 * LINK: https://codeforces.com/problemset/problem/659/D
 * NAME: D. Bicycle Race
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;
    vector<pair<ll, ll>> ps(n+1);
    vector<pair<ll, ll>> ds(n); //directions

    for (auto &[a, b]: ps) cin >> a >> b;

    for (int i = 1; i < n; i++) 
        ds[i-1].first = ps[i].first - ps[i-1].first,
        ds[i-1].second = ps[i].second - ps[i-1].second;

    ll sum = 0;
    for (int i = 1; i < n; i++) {
        auto [x, y] = ds[i]; 
        auto [l_x, l_y] = ds[i-1];

        if (y >= 1  && l_x >= 1)  sum++; else
        if (y <= -1 && l_x <= -1) sum++; else
        if (x >= 1  && l_y <= -1) sum++; else
        if (x <= -1 && l_y >= 1)  sum++;
    }

    cout << sum << endl;
    return 0;
}
