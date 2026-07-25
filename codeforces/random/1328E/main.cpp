/*
 * LINK: https://codeforces.com/problemset/problem/1328/E?mobile=true
 * NAME: E. Tree Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// if you change every node for its parent, them it has to be in the path
// and not from dist one of the path
// them just use tin and tout of the euler tour to determine if the nodes
// are actually a part of a path

vector<vector<int>> graph;
vector<int> tin, tout, par;

int t = 1;
void dfs(int v, int p) {
    tin[v] = t++, par[v] = p;
    for (auto u: graph[v]) if (u != p) dfs(u, v);
    tout[v] = t++;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1), tin.resize(n+1), tout.resize(n+1), par.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    tin[0] = 0, tout[0] = t;

    vector<int> vk(n+1);
    while (m--) {
        int k; cin >> k;
        vk.resize(k);
        for (auto &v: vk) cin >> v;
        for (auto &v: vk) v = par[v];

        sort(vk.begin(), vk.end(), [](int a, int b) {return tin[a] < tin[b];});

        bool y = 1;
        for (int i = 1; i < k && y; i++)
            if (tout[vk[i]] > tout[vk[i-1]]) y = 0;

        if (y) cout << "YES\n";
        else   cout << "NO\n";
    }
    return 0;
}
