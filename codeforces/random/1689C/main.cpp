/*
 * LINK: https://codeforces.com/problemset/problem/1689/C?mobile=false
 * NAME: C. Infected Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> sz;

void csz(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v]) 
        if (u != p) csz(u, v), sz[v] += sz[u];
}

int dfs(int v) {
    if (v != 1) {
        sort(adj[v].begin(), adj[v].end(), [](int a, int b) {return sz[a] < sz[b];});
        adj[v].pop_back();
    }

    if (adj[v].empty()) return 0;
    if (adj[v].size() == 1) return sz[adj[v][0]] - 1;

    return max(dfs(adj[v][0]) + sz[adj[v][1]] - 1, 
               dfs(adj[v][1]) + sz[adj[v][0]] - 1);
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.clear(), adj.resize(n+1);
        sz.clear(), sz.resize(n+1);

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        csz(1, 0);
        cout << dfs(1) << endl;
    }
    return 0;
}
