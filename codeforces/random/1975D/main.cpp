/*
 * LINK: https://codeforces.com/problemset/problem/1975/D
 * NAME: D. Paint the Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> dist, sz, par;

void dfs(int v, int p) {
    dist[v] = dist[p]+1, par[v] = p;
    sz[v] = 1;

    for (auto u: adj[v]) 
        if (u != p) dfs(u, v), sz[v] += sz[u];
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a, b; cin >> a >> b;
        adj.clear(), dist.clear(), sz.clear(), par.clear();
        adj.resize(n+1), dist.resize(n+1), sz.resize(n+1), par.resize(n+1);
        dist[0] = -1;

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(a, 0);
        int cb = b;
        while (dist[cb]*2 > dist[b]) cb = par[cb];

        int total = max(dist[cb], dist[b]-dist[cb]);
        dist[cb] = 0;
        dfs(cb, 0);

        for (auto u: adj[cb]) total += sz[u]*2;
        total -= *max_element(dist.begin(), dist.end());

        cout << total << endl;

    }
    return 0;
}
