/*
 * LINK: https://codeforces.com/problemset/problem/274/B
 * NAME: B. Zero Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<ll> vs, dc, ic;

void dfs(int v, int p) {
    ll td = 0, ti = 0;
    for (auto u: adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        td = max(td, dc[u]), ti = max(ti, ic[u]);
    }

    dc[v] += td, ic[v] += ti;
    ll diff = (vs[v] - dc[v]) + ic[v];

    if (diff < 0) ic[v] += -diff; else dc[v] += diff;
}

int main(void) {
    int n; cin >> n;

    adj.resize(n+1), vs.resize(n+1);
    dc.resize(n+1), ic.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) cin >> vs[i];

    dfs(1, 0);
    cout << dc[1] + ic[1] << endl;
    return 0;
}
