/*
 * LINK: https://codeforces.com/problemset/problem/609/E
 * NAME: E. Minimum spanning tree for each edge
*/

#include <bits/stdc++.h>

using namespace std;
#define int int64_t

vector<bool> dead;
vector<vector<array<int, 3>>> graph; // vertex, weight, edge
vector<array<int, 20>> par;    // lca parent
vector<array<int, 20>> m_edge; // max edge
vector<int> ht;

void preLCA(int v, int p, int ew, int h) {
    par[v][0] = p, m_edge[v][0] = ew;
    for (int k = 1; k < 20; k++) {
        par[v][k] = par[par[v][k-1]][k-1];
        m_edge[v][k] = max(m_edge[v][k-1], m_edge[par[v][k-1]][k-1]);
    }
    ht[v] = h;

    for (auto [u, w, e]: graph[v])
        if (u != p && !dead[e]) preLCA(u, v, w, h+1);
}

int lca(int a, int b) {
    if (ht[a] > ht[b]) swap(a, b);
    int h = ht[b] - ht[a];

    int lmax = 0;
    for (int k = 0; k < 20; k++)
        if ((h>>k)&1)
            lmax = max(lmax, m_edge[b][k]), b = par[b][k];

    if (a == b) return lmax;

    for (int k = 19; k >= 0; k--) {
        if (par[a][k] != par[b][k]) {
            lmax = max({m_edge[b][k], m_edge[a][k], lmax});
            a = par[a][k], b = par[b][k];
        }
    }

    return max({m_edge[b][0], m_edge[a][0], lmax});
}

namespace dsu {
    vector<int> par, sz;
    void build(int n) {
        par.resize(n+1), sz.resize(n+1, 0);
        iota(par.begin(), par.end(), 0);
    }

    int find(int i) {
        return par[i] == i ? i : find(par[i]);
    }

    bool join(int a, int b, int w) {
        a = find(a), b = find(b);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);

        par[b] = a;
        sz[a] += sz[b]+w;
        return 1;
    }
}

int32_t main(void) {
    ll n, m; cin >> n >> m;

    dsu::build(n), dead.resize(m+1), graph.resize(n+1);
    vector<array<int, 4>> edges(m+1); // w, a, b, i

    par.resize(n+1), m_edge.resize(n+1), ht.resize(n+1);

    for (int i = 1; i <= m; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][3] = i;
    }

    auto usort_edges = edges;
    sort(edges.begin(), edges.end());

    for (auto &[w, a, b, i]: edges) {
        dead[i] = !dsu::join(a, b, w);
        graph[a].push_back({b, w, i});
        graph[b].push_back({a, w, i});
    }

    preLCA(1, 0, 0, 0);
    int mst = dsu::sz[dsu::find(1)];

    for (int i = 1; i <= m; i++) {
        if (dead[i]) {
            int a = usort_edges[i][1], b = usort_edges[i][2], w = usort_edges[i][0];
            cout << (mst-lca(a, b))+w << '\n';
        } else {
            cout << mst << '\n';
        }
    }

    return 0;
}
