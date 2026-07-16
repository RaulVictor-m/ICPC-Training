/*
 * LINK: https://codeforces.com/problemset/problem/191/C
 * NAME: C. Fools and Roads
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> graph;
vector<ll> edges;
vector<array<ll, 20>> parent;
vector<ll> paths;
vector<ll> ht;

ll dfs(ll i, ll p) {
    ll total = 0;
    for (auto &[v, e]: graph[i]) {
        if (v == p) continue;
        ll res = dfs(v, i);

        edges[e] = res;
        total += res;
    }

    return paths[i] + total;
}

void blift(ll i, ll p, ll h) {
    parent[i][0] = p;
    for (ll k = 1; k < 20; k++) parent[i][k] = parent[parent[i][k-1]][k-1];

    ht[i] = h;
    for (auto &[v, e]: graph[i]) if (v != p) blift(v, i, h+1);
}

ll lca(ll a, ll b) {
    if (ht[a] > ht[b]) swap(a, b);
    ll h = ht[b] - ht[a];

    // levelling a and b
    for (ll k = 0; k < 20; k++)
        if ((h>>k)&1) b = parent[b][k];

    if (a == b) return a;

    for (ll k = 19; k >= 0; k--)
        if (parent[a][k] != parent[b][k])
            a = parent[a][k], b = parent[b][k];

    return parent[a][0];
}



int main(void) {
    ll n; cin >> n;
    graph.resize(n+1), parent.resize(n+1), paths.resize(n+1), ht.resize(n+1);
    edges.resize(n);

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }

    blift(1, 0, 1);

    ll q; cin >> q;
    while (q--) {
        ll a, b; cin >> a >> b;
        ll an = lca(a, b);
        paths[a]++;
        paths[b]++;
        paths[an] -= 2;;

        // cout << a << " " << b << " " << an << endl;
    }

    dfs(1, 0);

    for (int i = 1; i < n; i++) cout << edges[i] << " "; cout << endl;

    return 0;
}
