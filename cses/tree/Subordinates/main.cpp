/*
 * LINK: https://cses.fi/problemset/task/1674
 * NAME: Subordinates
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
vector<int> sz;

void csz(int v) {
    for (auto u: adj[v]) csz(u), sz[v] += sz[u];
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;

    sz.resize(n+1, 1), adj.resize(n+1);

    rep(i, 2, n+1) {
        int v; cin >> v;
        adj[v].pb(i);
    }
    csz(1);

    rep(i, 1, n+1) cout << sz[i]-1 << " ";
    cout << endl;
    return 0;
}

