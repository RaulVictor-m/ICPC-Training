/*
 * LINK: https://codeforces.com/problemset/problem/1611/E2
 * NAME:  E2. Escape The Maze (hard version)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Check the editorial for explanation

vector<vector<int>> adj;
vector<int> near;

int dfs(int v, int p = 0, int dist = 0) {
    bool children = true;
    int count = 0;
    for (auto u: adj[v]) {
        if (u == p) continue;

        int c = dfs(u, v, dist+1);
        if (c < 0) children = false;
        count += c;

        near[v] = min(near[u]+1, near[v]);
    }

    if (near[v] <= dist) return 1;
    if (!count || !children) return -1;
    return count;
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        adj.clear(), near.clear();
        adj.resize(n+1), near.resize(n+1, n+2);

        for (int i = 0; i < k; i++) {
            int v; cin >> v;
            near[v] = 0;
        }

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << dfs(1) << endl;
    }
    return 0;
}
