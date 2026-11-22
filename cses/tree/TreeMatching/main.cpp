/*
 * LINK: https://cses.fi/problemset/task/1130
 * NAME: Tree Matching
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
vector<bool> match;
int dfs(int v, int p) {
    int acc = 0;
    for (auto u: adj[v]) {
        if (u == p) continue;
        acc += dfs(u, v);
        if (!match[u] && !match[v]) match[v] = 1, acc++;
    }
    return acc;
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    adj.resize(n+1), match.resize(n+1);

    rep (i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    cout << dfs(1, 0) << endl;
    return 0;
}

