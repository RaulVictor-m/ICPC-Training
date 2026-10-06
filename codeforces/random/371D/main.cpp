/*
 * LINK: https://codeforces.com/problemset/problem/371/D
 * NAME: D. Vessels
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

    int n; cin >> n;
    vector<ll> par(n+2), vs(n+2), cur(n+2);

    rep(i, 1, n+1) cin >> vs[i], par[i] = i;
    vs.back() = LINF, par.back() = par.size()-1;

    auto find = [&](this auto&& self, int v) -> int {
        return par[v] = (par[v] == v ? v : self(par[v]));
    };

    int m; cin >> m;
    while (m--) {
        int t, v; cin >> t >> v;

        if (t == 1) {
            ll x; cin >> x;

            while (1) {
                v = find(v);
                cur[v] += x;
                x = vs[v] - cur[v];

                if (x < 0) x = -x, cur[v] -= x, par[v] = find(v+1);
                else break;
            }

        } else cout << cur[v] << endl;
    }

    return 0;
}

