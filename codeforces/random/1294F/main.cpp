/*
 * LINK: https://codeforces.com/problemset/problem/1294/F
 * NAME: F. Three Paths on a Tree
 * STATUS: DONE - but bad code
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<int> dist;
set<pair<int, int>> edges;

void longest(int v, int p = 0, int h = 0) {
    dist[v] = h;
    for (auto u: graph[v]) if (u != p) longest(u, v, h+1);
}

bool addedges(int v, int p, int dst) {
    if (v == dst) return true;
    for (auto u: graph[v]) {
        if (u == p) continue;
        if (addedges(u, v, dst)) {
            edges.emplace(min(u, v), max(u, v));
            return true;
        }
    }
    return false;
}

int main(void) {
    int n; cin >> n;
    graph.resize(n+1), dist.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int d1 = 0; longest(1);
    for (int i = 1; i <= n; i++) if (dist[d1] < dist[i]) d1 = i;
    dist.assign(n+1, 0);

    int d2 = 0; longest(d1);
    for (int i = 1; i <= n; i++) if (dist[d2] < dist[i]) d2 = i;
    dist.assign(n+1, -1);

    queue<int> qu;
    qu.push(d1), qu.push(d2);
    dist[d1] = 0, dist[d2] = 0;

    while (!qu.empty()) {
        int v = qu.front(); qu.pop();
        for (auto u: graph[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v]+1;
                qu.push(u);
            }
        }
    }

    int d3 = 0;
    for (int i = 1; i <= n; i++) if (dist[d3] < dist[i]) d3 = i;
    addedges(d1, 0, d2);
    addedges(d1, 0, d3);
    addedges(d2, 0, d3);

    cout << edges.size() << endl;
    cout << d1 << " " << d2 << " " << d3 << " " << endl;
    return 0;
}
