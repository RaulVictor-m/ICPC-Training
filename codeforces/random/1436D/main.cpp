/*
 * LINK: https://codeforces.com/problemset/problem/1436/D
 * NAME: D. Bandit in a City
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<ll> sz, lfs, ans;

void pre(int v) {
    for (auto u: adj[v]) 
        pre(u), sz[v] += sz[u], lfs[v] += lfs[u];
}

void dfs(int v) {
    ans[v] = (ll)ceil((double)sz[v] / (double)lfs[v]);
    for (auto u: adj[v])
        dfs(u), ans[v] = max(ans[v], ans[u]);
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1), sz.resize(n+1), lfs.resize(n+1);
    ans.resize(n+1);

    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
    }

    for (int i = 1; i <= n; i++) cin >> sz[i];
    for (int i = 1; i <= n; i++) lfs[i] = (adj[i].size() == 0);
    pre(1);
    dfs(1);
    cout << ans[1] << endl;

    return 0;
}
