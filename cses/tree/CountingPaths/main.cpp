/*
 * LINK: https://cses.fi/problemset/task/1136
 * NAME: Counting Paths
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

vector<vector<int>> adj, paths;
vector<int> dsu, acc, vis, par;

int find(int v) {
    return v == dsu[v] ? v : (dsu[v] = find(dsu[v]));
}

void pre(int v, int p) {
    par[v] = p, dsu[v] = v;
    for (auto u: adj[v]) 
        if (u != p) pre(u, v), dsu[u] = v;

    vis[v] = 1;
    for (auto u: paths[v])
        if (vis[u]) acc[v]++, acc[u]++, acc[find(u)]--, acc[par[find(u)]]--;
}

void pref(int v, int p) {
    for (auto u: adj[v]) 
        if (u != p) pref(u, v), acc[v] += acc[u];
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    [&](auto&... v) {(v.resize(n+1), ...);}(adj, paths, dsu, acc, vis, par);

    rep (i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    rep (i, 0, m) {
        int a, b; cin >> a >> b;
        paths[a].pb(b);
        if (a != b) paths[b].pb(a);
    }

    pre(1, 0), pref(1, 0);

    rep (i, 1, n+1) cout << acc[i] << " ";
    cout << endl;
    return 0;
}

