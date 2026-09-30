/*
 * LINK: https://codeforces.com/problemset/problem/1822/F
 * NAME: F. Gardening Friends
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
    int t; cin >> t;

    while (t--) {
        ll n, k, c; cin >> n >> k >> c;

        vector<vector<int>> adj(n+1);
        vector<int> dr(n+1), da(n+1), db(n+1);
        rep(i, 1, n) {
            int a, b; cin >> a >> b;
            adj[a].pb(b), adj[b].pb(a);
        }

        auto dist = [&adj](this auto&& self, int v, int p, auto& dx) -> void {
            for (auto u: adj[v])
                if (u != p) dx[u] = dx[v]+1, self(u, v, dx);
        };

        dist(1, 0, dr);
        int a = max_element(all(dr)) - dr.begin();

        dist(a, 0, da);
        int b = max_element(all(da)) - da.begin();

        dist(b, 0, db);

        ll mx = 0;
        rep(i, 1, n+1)
            mx = max(mx, max(da[i], db[i])*k - dr[i]*c);

        cout << mx << endl;
    }
    return 0;
}

