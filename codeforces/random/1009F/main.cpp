/*
 * LINK: https://codeforces.com/problemset/problem/1009/F
 * NAME: F. Dominant Indices
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6+5;
vector<vector<int>> adj(N);
vector<int> hv(N), dep(N), sz(N), ans(N), hts(N);

void pre(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;
        dep[u] = dep[v]+1;
        pre(u, v);
        sz[v] += sz[u];

        if (sz[hv[v]] < sz[u]) hv[v] = u;
    }
}

int mx = 0;
void addh(int h, int x) {
    hts[h]+=x;
    if (hts[mx] < hts[h] || (hts[mx] == hts[h] && mx > h))
        mx = h;
}

void add(int v, int p, int x) {
    for (auto u: adj[v]) 
        if (u != p) add(u, v, x);
    addh(dep[v], x);
}

void dfs(int v, int p, bool k) {
    int tmx = mx;
    for (auto u: adj[v]) {
        if (u == p || u == hv[v]) continue;
        dfs(u, v, false);
    }

    if (hv[v]) dfs(hv[v], v, true);

    addh(dep[v], 1);
    for (auto u: adj[v]) {
        if (u == p || u == hv[v]) continue;
        add(u, v, 1);
    }

    ans[v] = mx;

    if (!k) add(v, p, -1), mx = tmx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pre(1, 0);
    dfs(1, 0, 1);

    for (int i = 1; i <= n; i++) cout << ans[i]-dep[i] << endl;

    return 0;
}
