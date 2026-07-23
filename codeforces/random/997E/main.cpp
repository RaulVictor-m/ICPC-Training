/*
 * LINK: https://codeforces.com/problemset/problem/977/E
 * NAME: E. Cyclic Components
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<int> vis;

bool dfs(int v, int p, int root) {
    vis[v] = 1;
    if (graph[v].size() != 2) return false;

    for (auto u: graph[v]) {
        if (u == p) continue;
        if (u == root) return true;
        if (vis[u]) return false;
        return dfs(u, v, root);
    }
    return false;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1), vis.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfs(i, 0, i)) count++;

    cout << count << '\n';
    return 0;
}
