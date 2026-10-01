/*
 * LINK: https://codeforces.com/problemset/problem/949/C
 * NAME: C. Data Center Maintenance
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

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, h; cin >> n >> m >> h;

    vector<int> vs(n+1), tin(n+1), ord;
    vector<vector<int>> adj(n+1), radj(n+1);

    rep(i, 1, n+1) cin >> vs[i];

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        if (((vs[a]+1)%h) == vs[b]) adj[a].pb(b), radj[b].pb(a);
        if (((vs[b]+1)%h) == vs[a]) adj[b].pb(a), radj[a].pb(b);
    }

    int t = 1;
    auto tour = [&](this auto&& s, int v, auto& g, auto& tin, auto& out) -> void {
        tin[v] = t++;
        for (auto u: g[v])
            if (!tin[u]) s(u, g, tin, out);
        out.pb(v);
    };

    rep(i, 1, n+1) 
        if (!tin[i]) tour(i, adj, tin, ord);

    reverse(ord.begin(), ord.end());

    tin.assign(n+1, 0), t = 1;
    vector<int> ans;

    for (auto v: ord) {
        if (tin[v]) continue;
        vector<int> comp;

        tour(v, radj, tin, comp);
        bool sink = true;

        for (auto u: comp)
            for (auto to: adj[u]) if (tin[to] < tin[v]) sink = false;

        if (sink && (ans.empty() || ans.size() > comp.size()))
            ans = move(comp);
    }

    cout << ans.size() << endl;
    for (auto v: ans) cout << v << " "; cout << endl;

    return 0;
}

