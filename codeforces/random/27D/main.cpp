/*
 * LINK: https://codeforces.com/problemset/problem/27/D
 * NAME: D. Ring Road 2
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void tsort(int v, vector<vector<int>>& adj, vector<int>& out, vector<bool>& vis) {
    vis[v] = 1;
    for (auto u: adj[v]) if (!vis[u]) tsort(u, adj, out, vis);
    out.push_back(v);
}

int main(void) {
    int n, m; cin >> n >> m;

    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(m*2), radj(m*2);

    for (auto &[a, b]: edges) {
        cin >> a >> b;
        if (a > b) swap(a, b);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            auto [a, b] = edges[i];
            auto [c, d] = edges[j];

            if ((a < c) && (c < b) && (b < d)) {
                int v = i<<1, u = j<<1;
                adj[v].push_back(u^1);
                adj[u].push_back(v^1);
                adj[v^1].push_back(u);
                adj[u^1].push_back(v);
            }
        }
    }

    vector<bool> vis(m*2);
    vector<int> tout;

    for (int i = 0; i < m*2; i++) 
        if (!vis[i]) tsort(i, adj, tout, vis);

    reverse(tout.begin(), tout.end());
    vis.assign(m*2, 0);

    int comps = 0;
    vector<int> root(m*2);
    for (auto v: tout) {
        if (vis[v]) continue;

        vector<int> comp;
        tsort(v, adj, comp, vis);
        for (auto u: comp) 
            root[u] = comps;

        comps++;
    }

    for (int i = 0; i < m*2; i+=2)
        if (root[i] == root[i^1]) {
            cout << "Impossible\n";
            return 0;
        }

    string ans(m, ' ');
    for (int i = 0; i < m*2; i+=2) {
        ans[i>>1] = root[i^1] > root[i] ? 'i' : 'o';
    }

    cout << ans << endl;

    return 0;
}
