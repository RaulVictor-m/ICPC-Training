/*
 * LINK: https://cses.fi/problemset/task/2079
 * NAME: Finding a Centroid
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

vector<int> sz;
vector<vector<int>> adj;
void csz(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v])
        if (u != p) csz(u, v), sz[v] += sz[u];
}

int cent(int v, int p, int tsz) {
    for (auto u: adj[v]) 
        if (u != p && sz[u]*2 > tsz) 
            return cent(u, v, tsz);

    return v;
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    adj.resize(n+1), sz.resize(n+1);

    rep (i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    csz(1, 0);
    cout << cent(1, 0, sz[1]) << endl;
    return 0;
}

