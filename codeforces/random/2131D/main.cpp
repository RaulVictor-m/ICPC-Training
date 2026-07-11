/*
 * LINK: https://codeforces.com/problemset/problem/2131/D
 * NAME: D. Arboris Contractio
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
 *  just choose the node with the most amount of leafs directly connected to it
 *  and them every other leaf is a path starting from this root
 */

int main(void) {
    ll t; cin >> t;
    vector<ll> deg;
    vector<vector<ll>> g;
    while (t--) {
        ll n; cin >> n;

        deg.clear(), deg.resize(n+1);
        g.clear(), g.resize(n+1);

        for (int i = 1; i < n; i++) {
            ll a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
            deg[a]++, deg[b]++;
        }

        if (n == 2) {
            cout << 0 << endl;
            continue;
        }

        ll leafs = 0;
        for (auto d: deg) leafs += (d==1);

        ll root = 0, root_leafs = 0;
        for (int i = 1; i <= n; i++) {
            ll v_leafs = 0;
            for (auto e: g[i]) v_leafs += (deg[e] == 1);

            if (v_leafs > root_leafs) root = i, root_leafs = v_leafs;
        }

        cout << leafs - root_leafs << endl;
    }
    return 0;
}
