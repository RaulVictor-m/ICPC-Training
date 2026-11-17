/*
 * LINK: https://cses.fi/problemset/task/1133
 * NAME: Tree Distances II
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
vector<ll> sz, ans;

void pre(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;
        pre(u, v);
        sz[v] += sz[u], ans[v] += ans[u] + sz[u];
    }
}

void reroot(int v, int p) {
    for (auto u: adj[v]) {
        if (u == p) continue;
        ans[u] += (ans[v] - (ans[u] + sz[u])) + (sz[v] - sz[u]);
        sz[u] += sz[v] - sz[u];
        reroot(u, v);
    }
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    adj.resize(n+1), sz.resize(n+1), ans.resize(n+1);

    rep (i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    pre(1, 0);
    reroot(1, 0);

    rep (i, 1, n+1) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

