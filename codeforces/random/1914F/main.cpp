/*
 * LINK: https://codeforces.com/problemset/problem/1914/F
 * NAME: F. Programming Competition
 * STATUS: REVISIT
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> sz;

void csz(int v) {
    sz[v] = 1;
    for (auto u: adj[v]) csz(u), sz[v] += sz[u];
}

int dfs(int v, int k = 0) {
    int total = 0, mu = -1;

    for (auto u: adj[v]) {
        total += sz[u];
        if (mu == -1 || sz[mu] < sz[u]) mu = u;
    }

    if (total == 0) return 0;

    if (sz[mu] <= total) return (total-k)/2;
    total -= sz[mu];

    return total + dfs(mu, max(total+k-1, 0));
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.clear(), adj.resize(n+1);
        sz.clear(), sz.resize(n+1);

        for (int i = 2; i <= n; i++) {
            int v; cin >> v;
            adj[v].push_back(i);
        }

        csz(1);
        cout << dfs(1) << endl;
    }
    return 0;
}
