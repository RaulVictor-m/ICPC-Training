/*
 * LINK: https://cses.fi/problemset/task/1673
 * NAME: High Score
*/

#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll INF = LONG_LONG_MIN/3;

// bellman
vector<array<ll, 3>> edges;
vector<ll> dists;
vector<bool> changes;

// reversed dfs
vector<list<ll>> reverse_graph;
vector<bool> visited;

bool dfs(ll i) {
    if (changes[i]) return true;
    if (visited[i]) return false;
    visited[i] = true;

    for (auto v: reverse_graph[i]) {
        if (dfs(v)) return true;
    }

    return false;
}

bool bellman() {
    dists[1] = 0;
    bool achange = true;
    for (int i = 1; i < dists.size() && achange; i++) {
        achange = false;
        for (auto [a, b, c]: edges) {
            if (dists[a] == INF) continue;

            if ((dists[a] + c) > dists[b]) {
                dists[b] = (dists[a] + c);
                achange = true;
                if (i == dists.size()-1) changes[b] = true;
            }
        }
    }

    return achange;
}

int main(void) {
    int n, m; cin >> n >> m;
    edges.reserve(m);
    dists.resize(n+1, INF);
    reverse_graph.resize(n+1);
    visited.resize(n+1, 0);

    changes.resize(n+1, 0);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
        reverse_graph[b].push_back(a);
    }


    if (bellman() && dfs(n)) {
        cout << -1 << endl; return 0;
    }

    cout << dists.back() << endl;

    return 0;
}
