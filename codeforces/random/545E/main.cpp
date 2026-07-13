/*
 * LINK: https://codeforces.com/problemset/problem/545/E
 * NAME: E. Paths and Trees
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
 * Dijkstra tree ??
*/

int main(void) {
    ll n, m, u; cin >> n >> m;

    vector<vector<array<ll, 3>>> graph(n+1); // weight, vertex, index
    vector<ll> ws(m+1);

    for (int i = 1; i <= m; i++) {
        ll a, b, w; cin >> a >> b >> w;
        graph[a].push_back({w, b, i});
        graph[b].push_back({w, a, i});
        ws[i] = w;
    }

    cin >> u;

    vector<bool> u_edges(m+1);
    vector<ll> dist(n+1, LONG_LONG_MAX/3), edge_w(n+1, LONG_LONG_MAX/3);

    priority_queue<array<ll, 3>> pq; // -weight, vertex, edge

    pq.push({0, u, 0});
    dist[u] = 0;
    edge_w[u] = 0;

    while (!pq.empty()) {
        auto [w, i, e] = pq.top();
        w = -w;
        pq.pop();

        if (dist[i] < w || edge_w[i] < ws[e]) continue;
        u_edges[e] = 1;

        for (auto [w2, v, e2]: graph[i]) {
            if (dist[v] > w+w2) {
                dist[v] = w+w2;
                edge_w[v] = w2;
                pq.push({-dist[v], v, e2});
                continue;
            }

            if (dist[v] == w+w2 && w2 < edge_w[v]) {
                edge_w[v] = w2;
                pq.push({-dist[v], v, e2});
            }
        }
    }

    ll total = 0;
    for (int i = 1; i <= m; i++) if (u_edges[i]) total += ws[i];
    cout << total << endl;
    for (int i = 1; i <= m; i++) if (u_edges[i]) cout << i << " "; cout << endl;
    // cout << u << endl;

    return 0;
}
