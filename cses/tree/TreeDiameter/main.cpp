/*
 * LINK: https://cses.fi/problemset/task/1131
 * NAME: Tree Diameter
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
void dfs(int v, int p, vector<int>& dep) {
    for (auto u: adj[v])
        if (u != p) dep[u] = dep[v]+1, dfs(u, v, dep);
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;

    adj.resize(n+1);
    vector<int> da(n+1), db(n+1);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    dfs(1, 0, da);
    int a = max_element(all(da)) - da.begin();

    dfs(a, 0, db);
    cout << (*max_element(all(db))) << endl;
    return 0;
}

