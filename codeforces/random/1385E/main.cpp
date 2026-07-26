/*
 * LINK: https://codeforces.com/problemset/problem/1385/E
 * NAME: E. Directing Edges
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// topological sort says that if there is an edge between
// a and b, tout[a] is bigger, so if there is an edge
// that goes from a to b and tout[b] is bigger its a cycle
// and if there is no cycle them i just have to take all
// undirected edges and direct them in the same direction
// as the original topological order comming from the
// directed edges that way i ensure that there is not
// going to be any cycles


vector<vector<int>> graph;
vector<int> vis, tout;

int t = 1;
void tsort(int v) {
    vis[v] = 1;
    for (auto u: graph[v]) if (!vis[u]) tsort(u);
    tout[v] = t++;
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        graph.clear(), vis.clear(), tout.clear();
        graph.resize(n+1), vis.resize(n+1), tout.resize(n+1);
        vector<array<int, 3>> edges;

        for (int i = 0; i < m; i++) {
            int t, a, b; cin >> t >> a >> b;
            if (t) graph[a].push_back(b); 
            edges.push_back({a, b, t});
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i]) tsort(i);

        // directing edges based on tsort
        for (auto &[a, b, t]: edges)
            if (tout[a] < tout[b])
                if (t) goto no; else swap(a, b);

        cout << "YES\n";
        for (auto &[a, b, t]: edges) {
            cout << a << ' ' << b << '\n';
        }
        continue;

        no:
            cout << "NO\n";
    }
    return 0;
}
