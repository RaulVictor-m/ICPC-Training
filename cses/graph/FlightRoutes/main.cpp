/*
 * LINK: https://cses.fi/problemset/task/1196/
 * NAME: Flight Routes
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll INF = LONG_LONG_MAX/3;

vector<list<array<ll, 2>>> graph;
vector<vector<ll>> dists;

void dijkstra() {
                    // -cost, i
    priority_queue<array<ll, 2>> qu;

    dists[1][0] = 0;
    qu.push({0, 1});

    while (!qu.empty()) {
        auto [cost, i] = qu.top();
        cost *= -1;
        qu.pop();

        if (cost > dists[i].back()) continue;

        for (auto [v, c]: graph[i]) {
            if ((c+cost) < dists[v].back()) {

                dists[v].back() = c+cost;
                sort(dists[v].begin(), dists[v].end());

                qu.push({-(c+cost), v});
            }
        }
    }
}

int main(void) {
    int n, m, k; cin >> n >> m >> k;

    graph.resize(n+1);
    dists.resize(n+1, vector<ll>(k, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra();
    for (auto v: dists.back()) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
