/*
 * LINK: https://codeforces.com/problemset/problem/891/C
 * NAME: C. Envy
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+5;

namespace uf {
    ll par[N], sz[N];
    void build(int n) {
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int v) {
        return par[v] == v ? v : find(par[v]);
    }

    bool join(int a, int b, ll len) {
        a = find(a), b = find(b);

        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);

        sz[a] = sz[b]+len, par[b] = a;
        return true;
    }
}

vector<array<ll, 3>> edges(N);

vector<array<ll, 20>> par(N), mx(N);
vector<ll> dep(N);

vector<vector<int>> adj(N);
vector<bool> alive(N);


void pre(int v, int p) {
    for (int k = 1; k < 20; k++)
        par[v][k] = par[par[v][k-1]][k-1],
        mx[v][k] = max(mx[v][k-1], mx[par[v][k-1]][k-1]);

    for (auto [u, w]: adj[v]) {
        if (u == p) continue;
        par[u][0] = p, mx[u][0] = w;
        dep[u] = dep[v]+1;
        pre(u, v);
    }
}

ll dist(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int h = dep[b] - dep[a];

    ll lmx = 0;
    for (int k = 0; k < 20; k++)
        if ((h>>k)&1)
            lmx = max(mx[b][k], lmx), b = par[b][k];

    if (a == b) return lmx;

    for (int k = 19; k >= 0; k--) {

    }

}

int main(void) {
    int n, m; cin >> n >> m;

    uf::build(n);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= m; i++) {
        alive[i] = uf::join(edges[i][1], edges[i][2], edges[i][0]);
        if (alive[i]) {
            adj[edges[i][1]].emplace_back(edges[i][2], edges[i][0]);
            adj[edges[i][2]].emplace_back(edges[i][1], edges[i][0]);
        }
    }


    return 0;
}
