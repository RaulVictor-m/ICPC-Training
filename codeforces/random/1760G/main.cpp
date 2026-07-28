/*
 * LINK: https://codeforces.com/problemset/problem/1760/G
 * NAME: G. SlavicG's Favorite Problem
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> adj;
set<int> b_xors;

int n, a, b;

bool propb(int v, int p, int inx) {
    for (auto [u, w]: adj[v]) {
        if (p == u) continue;
        if (inx == w) return true;

        b_xors.insert(inx^w);
        if (propb(u, v, inx^w)) return true;
    }
    return false;
}

bool solve(int v, int p, int inx) {
    for (auto [u, w]: adj[v]) {
        if (p == u || u == b) continue;
        if (b_xors.count(inx^w)) return true;
        if (solve(u, v, inx^w)) return true;
    }
    return false;
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        adj.clear(), adj.resize(n+1);
        b_xors.clear();

        for (int i = 1; i < n; i++) {
            int v, u, w; cin >> v >> u >> w;
            adj[v].emplace_back(u, w);
            adj[u].emplace_back(v, w);
        }

        if (propb(b, 0, 0) || solve(a, 0, 0)) cout << "YES\n";
        else                cout << "NO\n";
    }
    return 0;
}
