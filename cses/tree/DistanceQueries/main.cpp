/*
 * LINK: 
 * NAME: 
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

vector<vector<int>> adj;
vector<vector<pair<int, int>>> qu;
vector<int> ans, par;
vector<int> dep;

int find(int v) {
    return v == par[v] ? v : (par[v] = find(par[v]));
}

void dfs(int v) {
    for (auto u: adj[v]) {
        if (dep[u]) continue;
        dep[u] = dep[v] + 1, dfs(u);
        par[find(u)] = find(v);
    }

    for (auto [u, i]: qu[v])
        if (dep[u]) ans[i] = dep[u] - dep[find(u)]*2 + dep[v];
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q; cin >> n >> q;

    adj.resize(n+1), qu.resize(n+1), ans.resize(q), par.resize(n+1);
    dep.resize(n+1);
    iota(all(par), 0);

    rep (i, 2, n+1) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    rep (i, 0, q) {
        int a, b; cin >> a >> b;
        qu[a].pb({b, i}), qu[b].pb({a, i});
    }

    dep[1] = 1;
    dfs(1);
    rep (i, 0, q) cout << ans[i] << endl;
    return 0;
}

