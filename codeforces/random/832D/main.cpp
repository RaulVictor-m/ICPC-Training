/*
 * LINK: https://codeforces.com/problemset/problem/832/D
 * NAME: D. Misha, Grisha and Underground
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+5;

vector<vector<int>> adj(N);
vector<array<int, 20>> par(N);
vector<int> dep(N), tin(N), tout(N);

int t = 1;
void euler(int v) {
    tin[v] = t++;
    for (auto u: adj[v]) 
        dep[u] = dep[v]+1, euler(u);
    tout[v] = t-1;
}

int lca(int a, int b) {
    if (tin[a] > tin[b]) swap(a, b);
    if (tout[b] <= tout[a]) return a;

    for (int k = 19; k >= 0; k--)
        if (tout[b] > tout[par[a][k]]) a = par[a][k];

    return par[a][0];
}

int dist(int a, int b) {
    return dep[a] + dep[b] - dep[lca(a, b)]*2;
}

int value(int a, int b, int c) {
    return (dist(a, c) + dist(b, c) - dist(a, b))/2 + 1;
}

int main(void) {
    int n, q; cin >> n >> q;

    tout[0] = 1e6;
    for (int i = 2; i <= n; i++) {
        cin >> par[i][0];
        adj[par[i][0]].push_back(i);
    }

    for (int k = 1; k < 20; k++)
        for (int i = 1; i <= n; i++)
            par[i][k] = par[par[i][k-1]][k-1];

    euler(1);
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        cout << max({value(a, b, c), value(a, c, b), value(b, c, a)}) << endl;
    }

    return 0;
}
