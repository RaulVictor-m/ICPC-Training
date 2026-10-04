/*
 * LINK: https://codeforces.com/problemset/problem/1037/D
 * NAME: D. Valid BFS?
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
    ll n; cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> ord(n+1);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, 1, n+1) {
        int v; cin >> v;
        ord[v] = i;
    }

    for (auto &lst: adj)
        sort(all(lst), [&](int a, int b) { return ord[a] < ord[b]; });

    queue<pair<int, int>> qu;
    qu.push({1, 0});

    for (int i = 1; !qu.empty(); i++, qu.pop()) {
        auto [v, p] = qu.front();

        if (ord[v] != i) {
            cout << "NO\n";
            return 0;
        }

        for (auto u: adj[v])
            if (u != p) qu.push({u, v});
    }

    cout << "YES\n";
    return 0;
}
