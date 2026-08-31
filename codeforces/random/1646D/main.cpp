/*
 * LINK: https://codeforces.com/problemset/problem/1646/D
 * NAME: D. Weight the Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> dp, vs;

int dfs(int v, int p, int b) {
    int g1 = 0, g2 = 1;

    for (auto u: adj[v]) {
        if (u == p) continue;
        g1 += dfs(u, v, 1);
    }

    if (!b) {
        for (auto u: adj[v]) {
            if (u == p) continue;
            g2 += dfs(u, v, 0);
        }

        if (g2 > g1) dp[v] = 1;
        else         dp[v] = 0;

        return max(g1, g2);
    }

     return g1;
}

void build(int v, int p, int b) {
    if (!b) {
        if (dp[v]) vs[v] = adj[v].size(); 
        else  vs[v] = 1;

        for (auto u: adj[v]) {
            if (u == p) continue;
            build(u, v, dp[v]^1);
        }

    } else {
        vs[v] = 1;
        for (auto u: adj[v]) {
            if (u == p) continue;
            build(u, v, 1);
        }
    }
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1);
    dp.resize(n+1), vs.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int good = dfs(1, 0, 0);
    build(1, 0, 0);

    int sz = accumulate(vs.begin(), vs.end(), 0);

    cout << good << ' ' << sz << '\n';
    for (int i = 1; i <= n; i++) cout << vs[i] << " ";
    cout << endl;
    return 0;
}
