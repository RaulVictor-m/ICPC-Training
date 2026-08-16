/*
 * LINK: https://codeforces.com/contest/208/problem/E
 * NAME: E. Blood Cousins
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+2;

vector<vector<int>> adj(N);
vector<int> dep(N), sz(N), hv(N), dc(N), tin(N), tout(N), ver(N), ans(N);

vector<array<int, 20>> par(N);
vector<vector<pair<int, int>>> q(N);

int t = 1;
void pre(int v) {
    for (int k = 1; k < 20; k++)
        par[v][k] = par[par[v][k-1]][k-1];

    tin[v] = t, ver[t++] = v;
    sz[v] = 1;
    for (auto u: adj[v]) {
        dep[u] = dep[v]+1;
        par[u][0] = v;

        pre(u);

        sz[v] += sz[u];
        if (sz[u] > sz[hv[v]]) hv[v] = u;
    }
    tout[v] = t-1;
}

void dfs(int v, bool keep) {
    for (auto u: adj[v])
        if (u != hv[v]) dfs(u, 0);

    if (hv[v]) dfs(hv[v], 1);

    for (auto u: adj[v]) 
        for (int t = tin[u]; u != hv[v] && t <= tout[u]; t++)
            dc[dep[ver[t]]]++;

    dc[dep[v]]++;

    for (auto [h, i]: q[v])
        ans[i] = dc[dep[v]+h]-1;

    for (int t = tin[v]; !keep && t <= tout[v]; t++)
        dc[dep[ver[t]]]--;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        if (!v) roots.push_back(i);
        else adj[v].push_back(i);
    }

    for (auto r: roots) pre(r);

    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        int v, p; cin >> v >> p;

        for (int k = 0; k < 20; k++)
            if ((p>>k)&1) v = par[v][k];

        q[v].emplace_back(p, i);
    }

    for (auto r: roots) dfs(r, 0);
    for (int i = 1; i <= m; i++) cout << ans[i] << " "; cout << endl;

    return 0;
}
