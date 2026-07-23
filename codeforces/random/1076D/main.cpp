/*
 * LINK: https://codeforces.com/problemset/problem/1076/D
 * NAME: D. Edge Deletion
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m, k; cin >> n >> m >> k;

    vector<vector<array<ll, 3>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w, i+1});
        graph[b].push_back({a, w, i+1});
    }
    if (!k) {
        cout << 0 << '\n';
        return 0;
    }

    vector<ll> dist(n+1, LONG_LONG_MAX/3);
    priority_queue<array<ll, 3>> pq;
    vector<ll> ans;
    pq.push({0, 1, 0});
    dist[1] = 0;

    while (!pq.empty()) {
        auto [w, i, e] = pq.top();
        w = -w;
        pq.pop();

        if (w > dist[i]) continue;
        if (e != 0) {
            ans.push_back(e);
            if (!(--k)) break;
        }

        for (auto [v, w2, e2]: graph[i]) {
            if (dist[i]+w2 < dist[v]) {
                dist[v] = dist[i]+w2;
                pq.push({-dist[v], v, e2});
            }
        }
    }

    cout << ans.size() << endl;
    for (auto e: ans) cout << e << " "; cout << endl;
    return 0;
}
