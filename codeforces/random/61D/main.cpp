/*
 * LINK: https://codeforces.com/problemset/problem/61/D
 * NAME: D. Eternal Victory
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// It will visit every edge twice except for the edges
// from the root to the furthest leaf

vector<vector<pair<ll,ll>>> graph;

ll dfs(ll i, ll p) {
    ll lmax = 0;
    for (auto [v, w]: graph[i]) {
        if (v == p) continue;
        lmax = max(lmax, dfs(v, i)+w);
    }
    return lmax;
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1);

    ll total = 0;
    for (int i = 1; i < n; i++) {
        ll a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
        total += w*2;
    }

    total -= dfs(1, 0);

    cout << total << endl;
    return 0;
}
