/*
 * LINK: https://codeforces.com/gym/106714/problem/M
 * NAME: M. Kingdom
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

// condensation graph
vector<vector<int>> c_adj;
vector<array<int, 20>> par;
vector<int> dep;

void pre(int v, int p) {
    par[v][0] = p;
    rep(k, 1, 20) par[v][k] = par[par[v][k-1]][k-1];

    for (auto u: c_adj[v])
        if (u != p) dep[u] = dep[v]+1, pre(u, v);
}

int lca(int v, int u) {
    if (dep[u] < dep[v]) swap(u, v);
    int h = dep[u] - dep[v];

    rep(k, 0, 20) if ((h>>k)&1) u = par[u][k];
    if (u == v) return v;

    rrep(k, 19, 0)
        if (par[v][k] != par[u][k]) v = par[v][k], u = par[u][k];

    return par[v][0];
}

int dist(int v, int u) {
    return dep[v] + dep[u] - 2*dep[lca(v, u)];
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;

    vector<vector<int>> adj(n+1);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    // calc condensation graph
    vector<int> comp(n+1);
    queue<int> qu;

    int comp_cnt = 1;
    rep(i, 1, n+1) 
        if (adj[i].size() > 2) qu.push(i), comp[i] = comp_cnt++;

    while (!qu.empty()) {
        auto v = qu.front();
        qu.pop();

        for (auto u: adj[v])
            if (!comp[u]) comp[u] = comp[v], qu.push(u);
    }

    c_adj.resize(comp_cnt), par.resize(comp_cnt), dep.resize(comp_cnt);
    rep(v, 1, n+1)
        for (auto u: adj[v])
            if (comp[u] != comp[v]) c_adj[comp[v]].pb(comp[u]);

    // calc LCAs for condensation
    pre(1, 0);

    // solving queries
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << dist(comp[a], comp[b])+1 << endl;
    }

    return 0;
}

