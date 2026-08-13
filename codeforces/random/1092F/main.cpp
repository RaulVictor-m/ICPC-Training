/*
 * LINK: https://codeforces.com/problemset/problem/1092/F
 * NAME: F. Tree with Maximum Cost

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj(3e5);
vector<ll> vs(3e5);
vector<ll> ans(3e5), sub(3e5), fans(3e5);

void dfs(int v, int p) {
    sub[v] = vs[v];
    for (auto u: adj[v]) 
        if (u != p)
            dfs(u, v), ans[v] += ans[u], sub[v] += sub[u];

    ans[v] += sub[v] - vs[v];
}

void solve(int v, int p) {
    if (p) {
        fans[v] = ((fans[p] - sub[v]) + (sub[p] - sub[v]));
        sub[v] = sub[p];
    } else {
        fans[v] = ans[v];
    }

    for (auto u: adj[v]) if (u != p) solve(u, v);
}

int main(void) {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> vs[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    solve(1, 0);

    cout << (*max_element(fans.begin(), fans.end())) << endl;

    return 0;
}
