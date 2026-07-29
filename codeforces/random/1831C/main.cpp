/*
 * LINK: https://codeforces.com/problemset/problem/1831/C
 * NAME: C. Copil Copac Draws Trees
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void solve(int v, int p, int f_e, int d) {
    dist[v] = d;
    for (auto [u, e]: adj[v]) {
        if (u == p) continue;
        if (e > f_e) solve(u, v, e, d);
        else         solve(u, v, e, d+1);
    }
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.clear(), dist.clear();
        adj.resize(n+1), dist.resize(n+1);

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b, i);
            adj[b].emplace_back(a, i);
        }

        solve(1, 0, 0, 1);
        cout << (*max_element(dist.begin(), dist.end())) << endl;
    }

    return 0;
}
