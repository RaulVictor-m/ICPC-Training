/*
 * LINK: https://codeforces.com/problemset/problem/652/E
 * NAME: E. Pursuit For Artifacts
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> adj(4e5);
vector<pair<int, int>> edges(4e5);
vector<bool> dead(4e5), mark(4e5);

vector<int> tin(4e5), low(4e5), comp(4e5);
vector<bool> vis(4e5);

vector<int> dead_lst;

vector<vector<pair<int, int>>> c_adj(4e5);
vector<int> c_mark(4e5);

int t = 1;
void bridges(int v, int p) {
    low[v] = tin[v] = t++;
    for (auto [u, e]: adj[v]) {
        if (u == p) continue;
        if (tin[u]) {
            low[v] = min(low[v], tin[u]);
        } else {
            bridges(u, v);
            low[v] = min(low[v], low[u]);

            if (low[u] > tin[v]) 
                dead[e] = 1, dead_lst.push_back(e);
        }
    }
}

void mcomp(int v, int c) {
    comp[v] = c, vis[v] = 1;
    for (auto [u, e]: adj[v]) {
        if (!dead[e]) {
            c_mark[c] |= mark[e];
            if (!vis[u]) mcomp(u, c);
        }
    }
}

bool solve(int v, int p, int dst, bool m) {
    m |= c_mark[v];
    if (v == dst) return m;

    for (auto [u, e]: c_adj[v]) {
        if (u == p) continue;
        if (solve(u, v, dst, m||mark[e])) return true;
    }

    return false;
}

int main(void) {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
        edges[i] = {a, b};
        mark[i] = c;
    }

    bridges(1, 0);
    int comps = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) mcomp(i, comps++);

    for (auto e: dead_lst) {
        auto [a, b] = edges[e];
        c_adj[comp[a]].emplace_back(comp[b], e),
        c_adj[comp[b]].emplace_back(comp[a], e);
    }

    int a, b; cin >> a >> b;
    if (solve(comp[a], 0, comp[b], 0)) cout << "YES\n";
    else                               cout << "NO\n";

    return 0;
}
