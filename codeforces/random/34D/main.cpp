/*
 * LINK: https://codeforces.com/problemset/problem/34/D
 * NAME: D. Road Map
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> par;

void dfs(int v, int p) {
    for (auto u: adj[v]) 
        if (u != p) par[u] = v, dfs(u, v);
}

int main(void) {
    int n, r1, r2; cin >> n >> r1 >> r2;

    adj.resize(n+1), par.resize(n+1);

    for (int i = 1; i <= n; i++) {
        if (i == r1) continue;
        int u; cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    dfs(r2, 0);

    for (int i = 1; i <= n; i++) 
        if (i != r2) cout << par[i] << ' ';
    cout << endl;
    return 0;
}
