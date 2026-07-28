/*
 * LINK: https://codeforces.com/problemset/problem/1702/G1?mobile=false
 * NAME: G1. Passable Paths (easy version)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<bool> marked;

int dfs(int v, int p = 0) {
    int count = 0;

    for (auto u: adj[v]) {
        if (u == p) continue;

        int c = dfs(u, v);

        if (c > 1) return -1;
        if (c == -1) return -1;
        count += c;
    }

    if (!count and marked[v]) return 1;
    return count;
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1), marked.resize(n+1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> vs(k);
        for (auto &v: vs) cin >> v;
        for (auto v: vs) marked[v] = 1;
        int ans = dfs(vs[0], 0);
        if (ans == -1 || ans > 2) cout << "No\n";
        else                      cout << "Yes\n";

        for (auto v: vs) marked[v] = 0;
    }



    return 0;
}
