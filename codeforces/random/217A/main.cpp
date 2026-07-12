/*
 * LINK: https://codeforces.com/problemset/problem/217/A
 * NAME: A. Ice Skating
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_map<ll, vector<ll>> xs, ys;
vector<pair<ll, ll>> points;
vector<bool> vis;

void dfs(ll i) {
    if (vis[i]) return;
    vis[i] = 1;

    auto [x, y] = points[i];
    for (auto v: xs[x]) dfs(v);
    for (auto v: ys[y]) dfs(v);
}

int main(void) {
    ll n; cin >> n;
    vis.resize(n);
    points.resize(n);

    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        points[i].first = x, points[i].second = y;

        xs[x].push_back(i), ys[y].push_back(i);
    }

    ll comps = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) comps++, dfs(i);
    }

    cout << comps-1 << endl;
    return 0;
}
