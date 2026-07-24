/*
 * LINK: https://codeforces.com/problemset/problem/1029/E
 * NAME: E. Tree with Small Distances
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> graph;
set<pair<int, int>> dists;
vector<int> dist;
vector<int> par;

void dfs(int v, int p = 0, int h = 0) {
    if (h > 2) dists.insert({h, v});
    dist[v] = h, par[v] = p;

    for (auto u: graph[v]) if (u != p) dfs(u, v, h+1);
}

int main(void) {
    int n; cin >> n;
    graph.resize(n+1), dist.resize(n+1), par.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    int count = 0;
    while (!dists.empty()) {
        auto [h, v] = *dists.rbegin();
        v = par[v];

        dists.erase({dist[v], v});
        count++;

        for (auto u: graph[v]) {
            dists.erase({dist[u], u});
        }
    }

    cout << count << '\n';
    return 0;
}
