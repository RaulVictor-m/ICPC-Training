/*
 * LINK: https://codeforces.com/problemset/problem/1056/D
 * NAME: D. Decorate Apple Tree
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

    vector<vector<int>> adj(n+1);
    vector<int> lcnt(n+1);

    rep(i, 2, n+1) {
        int v; cin >> v;
        adj[v].pb(i);
    }

    [&](this auto &&self, int v) -> void {
        lcnt[v] = adj[v].empty();
        for (auto u: adj[v]) self(u), lcnt[v]+=lcnt[u];
    }(1);

    sort(all(lcnt));
    rep(i, 1, n+1) cout << lcnt[i] << ' ';

    return 0;
}

