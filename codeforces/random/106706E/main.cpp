/*
 * LINK: https://codeforces.com/gym/106706/problem/E
 * NAME: E. Mesh mante2 ya zalame
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

int KK = 0;
#define V(v, r) (((v)*KK) + (r))

void tsort(int v, auto& adj, auto& vis, auto& out) {
    vis[v] = 1;
    for (auto u: adj[v]) 
        if (!vis[u]) tsort(u, adj, vis, out);
    out.pb(v);
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k; cin >> n >> m >> k;
    KK = k;

    vector<vector<int>> adj((n+1)*k), radj((n+1)*k);
    vector<bool> vis((n+1)*k);
    vector<int> out;

    rep (i, 0, m) {
        int a, b; cin >> a >> b;
        rep (j, 0, k)
            adj[V(a, j)].pb(V(b, (j+1)%k)), radj[V(b, (j+1)%k)].pb(V(a, j));
    }

    rep (i, 1, (n+1)*k) if (!vis[i]) tsort(i, adj, vis, out);
    reverse(all(out));

    vis.assign(vis.size(), 0);

    vector<int> roots((n+1)*k);
    vector<vector<int>> comps;

    // sccs
    for (auto v: out) {
        if (vis[v]) continue;
        vector<int> comp;

        tsort(v, radj, vis, comp);
        for (auto u: comp) roots[u] = comps.size();
        comps.pb(comp);
    }

    // precomputed table
    vector<bitset<6001>> scc_set(comps.size());

    rep (i, 1, (n+1)) 
        scc_set[roots[i*k]][i] = 1;

    reverse(all(comps));

    for (auto &comp: comps)
        for (auto v: comp)
            for (auto u: adj[v])
                if (roots[v] != roots[u])
                    scc_set[roots[v]] |= scc_set[roots[u]];


    int q; cin >> q;
    while (q--) {
        int c, a, b; cin >> c >> a >> b;
        bitset<6001> pa, pb, anyb;
        a = (k - a) % k;
        b = (k - b) % k;

        while (c--) {
            int u; cin >> u;
            pa ^= scc_set[roots[V(u, a)]];
            pb ^= scc_set[roots[V(u, b)]];
            anyb |= scc_set[roots[V(u, b)]];
        }

        cout << (pa & (~pb) & anyb).count() << endl;
    }

    return 0;
}

