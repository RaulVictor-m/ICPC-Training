/*
 * LINK: https://codeforces.com/problemset/problem/1304/E
 * NAME: E. 1-Trees and Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<array<int, 20>> par;
vector<int> tin, tout, dep;

int t = 1;
void preLCA(int v, int p) {
    par[v][0] = p, tin[v] = t++;
    for (int k = 1; k < 20; k++) par[v][k] = par[par[v][k-1]][k-1];

    for (auto u: adj[v]) 
        if (u != p)
            dep[u] = dep[v]+1, preLCA(u, v);
    tout[v] = t-1;
}

int dist(int a, int b) {
    if (tin[a] > tin[b]) swap(a, b);
    if (tout[b] <= tout[a]) return dep[b] - dep[a];

    int l = a;
    for (int k = 19; k >= 0; k--)
        if (tout[b] > tout[par[l][k]]) l = par[l][k];

    l = par[l][0];
    return (dep[a] - dep[l]) + (dep[b] - dep[l]);
}

int main(void) {
    int n; cin >> n;

    adj.resize(n+1), par.resize(n+1), tin.resize(n+1), tout.resize(n+1), dep.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    tout[0] = 1e9;
    preLCA(1, 0);

    int q; cin >> q;
    while (q--) {
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;

        int d1 = dist(a, b);
        int d2 = dist(a, x) + dist(y, b) + 1;
        int d3 = dist(a, y) + dist(x, b) + 1;
        auto ok = [](int d, int k) -> bool {
            return (d <= k) && ((d&1) == (k&1));
        };

        if (ok(d1, k) || ok(d2, k) || ok(d3, k))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}
