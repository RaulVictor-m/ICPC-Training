/*
 * LINK: https://codeforces.com/problemset/problem/1000/E
 * NAME: E. We Need More Bosses
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    https://cp-algorithms.com/graph/bridge-searching.html
    find the longest path in the bridge tree
*/

ll ans = 0;
vector<vector<pair<ll,ll>>> graph;
vector<ll> tin, low;
vector<ll> ht;
vector<bool> b;
vector<bool> vis;
ll timer = 1;

void bridges(ll i, ll p = 0) {
    tin[i] = low[i] = timer++;

    for (auto &[v, e]: graph[i]) {
        if (v == p) continue;
        if (tin[v]) {
            low[i] = min(low[i], tin[v]);
        } else {
            bridges(v, i);
            low[i] = min(low[i], low[v]);
            if (low[v] > tin[i]) b[e] = 1;
        }
    }
}

void hpath(ll i, ll p = 0, ll h = 1) {
    ht[i] = h;
    for (auto &[v, e]: graph[i]) {
        if (v == p || ht[v]) continue;
        hpath(v, i, h + (ll)b[e]);
    }
}

ll lpath(ll i, ll p = 0) {
    ll total = 0;
    vis[i] = 1;
    for (auto &[v, e]: graph[i]) {
        if (v == p || vis[v]) continue;
        total = max(total, lpath(v, i) + (ll)b[e]);
    }
    return total;
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1), tin.resize(n+1), low.resize(n+1), b.resize(m+1);
    vis.resize(n+1);
    ht.resize(n+1);

    for (int i = 1; i <= m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }

    bridges(1);
    hpath(1);
    ll lmax = 0;
    for (int i = 1; i <= n; i++)
        if (ht[lmax] < ht[i]) lmax = i;
    cout << lpath(lmax) << endl;
    return 0;
}
