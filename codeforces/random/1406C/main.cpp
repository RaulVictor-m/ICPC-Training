/*
 * LINK: https://codeforces.com/problemset/problem/1406/C
 * NAME: C. Link Cut Centroids
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> sz, par;

void dfs(int v, int p) {
    par[v] = p, sz[v] = 1;
    for (auto u: adj[v]) 
        if (u != p) dfs(u, v),sz[v] += sz[u];
}

int centroid(int v, int p, int tsz) {
    for (auto u: adj[v])
        if (u != p && sz[u]*2 > tsz)
            return centroid(u, v, tsz);
    return v;
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.clear(), sz.clear(), par.clear();
        adj.resize(n+1), sz.resize(n+1), par.resize(n+1);

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1, 0);
        int c1 = centroid(1, 0, sz[1]);
        int c2 = -1;

        for (auto u: adj[c1]) if (sz[1] == sz[u]*2) c2 = u;

        // cout << c1 << " " << c2 << endl;
        if (c2 == -1) {
            printf("%d %d\n%d %d\n", c1, adj[c1].front(), c1, adj[c1].front());
            continue;
        } else {
            int r = adj[c2].back();
            if (r == c1) r = adj[c2][adj[c2].size()-2];

            // cout << c2 << r << endl << c1 << r << endl;
            printf("%d %d\n%d %d\n", c2, r, c1, r);
        }
    }
    return 0;
}
