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
vector<int> par, dep, ans;
vector<bool> vis;
vector<vector<pair<int, int>>> qry;

int find(int v) {
    return par[v] == v ? v : (par[v] = find(par[v]));
}

void solve(int v) {
    vis[v] = 1;
    for (auto u: c_adj[v])
        if (!vis[u]) dep[u] = dep[v]+1, solve(u), par[u] = v;

    for (auto [u, id]: qry[v]) {
        if (vis[u]) ans[id] = dep[v] + dep[u] - 2*dep[find(u)] + 1;
    }
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
    vis.resize(comp_cnt);
    iota(all(par), 0);

    rep(v, 1, n+1)
        for (auto u: adj[v])
            if (comp[u] != comp[v]) c_adj[comp[v]].pb(comp[u]);

    // solving queries
    int q; cin >> q;
    qry.resize(n+1), ans.resize(q);
    rep(i, 0, q) {
        int a, b; cin >> a >> b;
        qry[comp[a]].pb({comp[b], i}), qry[comp[b]].pb({comp[a], i});
    }

    solve(1);
    for (auto v: ans) cout << v << endl;
    return 0;
}

