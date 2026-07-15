/*
 * LINK: https://codeforces.com/problemset/problem/938/D
 * NAME: D. Buy a Ticket
 * STATUS: REVIEW
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m; cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w;
        graph[b].emplace_back(a, w*2);
        graph[a].emplace_back(b, w*2);
    }

    vector<ll> dist(n+1);
    priority_queue<pair<ll, ll>> pq;

    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
        pq.emplace(-dist[i], i);
    }

    while (!pq.empty()) {
        auto [w, i] = pq.top();
        w = -w;
        pq.pop();

        if (w > dist[i]) continue;

        for (auto [v, w2]: graph[i]) {
            if (w2+dist[i] < dist[v]) {
                dist[v] = w2+dist[i];
                pq.emplace(-dist[v], v);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;
    return 0;
}
