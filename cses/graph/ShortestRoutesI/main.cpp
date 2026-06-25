/*
 * LINK: https://cses.fi/problemset/task/1671
 * NAME: Shortest Routes I
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5+3;
const ll MAXM = MAXN*2;
const ll INF = LONG_LONG_MAX/3;

vector<list<array<ll, 2>>> graph;
vector<ll> dist;

void dijkstra() {
    priority_queue<array<ll, 2>> qu;
    qu.push({0, 1});

    while (!qu.empty()) {
        ll i = qu.top()[1];
        ll cost = -qu.top()[0];
        qu.pop();

        if (dist[i] != INF) continue;
        dist[i] = cost;

        for (auto arr: graph[i]) {
            ll j = arr[0], c = arr[1];
            if (dist[j] == INF) qu.push({-(c+cost), j});
        }
    }

}

void dijkstra_optimized() {
    priority_queue<array<ll, 2>> qu;
    qu.push({0, 1});
    dist[1] = 0;

    while (!qu.empty()) {
        ll i = qu.top()[1];
        ll cost = -qu.top()[0];
        qu.pop();

        if (dist[i] < cost) continue;

        for (auto arr: graph[i]) {
            ll j = arr[0], c = arr[1];
            if (dist[j] > (c+cost)) {
                dist[j] = c+cost;
                qu.push({-dist[j], j});
            }
        }
    }
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);
    dist.resize(n+1, INF);

    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra_optimized();
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}
