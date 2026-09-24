/*
 * LINK: https://codeforces.com/problemset/problem/1093/D
 * NAME: D. Beautiful Graph
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

ll tpot[300001];
int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    tpot[0] = 1;
    rep(i, 1, 3e5+1) tpot[i] = (tpot[i-1]<<1)%MOD;

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        // dsu
        vector<int> par(n*2+1), sz((n+1)*2);
        rep(i, 0, n*2+1)  par[i] = i, sz[i] = (i <= n ? 1 : 0);

        auto find = [&par](this auto &&self, int v) -> int {
            return v == par[v] ? v : (par[v] = self(par[v]));
        };

        auto join = [&](int v, int u) -> void {
            v = find(v), u = find(u);
            if (u == v) return;
            if (sz[v] < sz[u]) swap(u, v);
            sz[v] += sz[u];
            par[u] = v;
        };

        // check biparted
        bool yes = true;
        rep(i, 0, m) {
            int a, b; cin >> a >> b;
            int pa = find(a), pb = find(b);

            if (pa == pb || !yes) yes = false;
            else join(a, b+n), join(b, a+n);
        }

        if (!yes) {
            cout << 0 << endl;
            continue;
        }

        // combine components
        set<pair<int, int>> lset;
        rep(i, 1, n+1) {
            int a = find(i), b = find(i+n);
            if (a > b) swap(a, b);
            lset.insert({a, b});
        }

        ll total = 1;
        for (auto [r, b]: lset) {
            ll lt = (tpot[sz[r]]+tpot[sz[b]])%MOD;
            total = (total * lt)%MOD;
        }
        cout << total << endl;
    }
    return 0;
}

