/*
 * LINK: https://codeforces.com/problemset/problem/342/E
 * NAME: E. Xenia and Tree
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;

vector<ll> cpar;           //parent for Centroid Tree
vector<ll> sz;             //Tree sizes Centroid Tree
vector<ll> dis;            //Distance from node on sub CenTree
vector<bool> dead;         //dead Centroids
vector<ll> redDist;        //dist from closest Red from centroid (ANSWER)
vector<ll> cenLevel;       //level of the centroid
vector<array<ll, 20>> cenDist;//every distance from centroid at level

void csize(ll i, ll p = 0) {
    sz[i] = 1;

    for (auto v: graph[i]) {
        if (v == p || dead[v]) continue;
        csize(v, i);
        sz[i] += sz[v];
    }
}

void cenLevelDist(ll i, ll level, ll p = 0, ll h = 0) {
    cenDist[i][level] = h;
    for (auto v: graph[i]) {
        if (v == p || dead[v]) continue;
        cenLevelDist(v, level, i, h+1);
    }
}

ll decompose(ll i, ll treesz, ll p = 0) {
    for (auto v: graph[i])
        if (v != p && !dead[v] && sz[v]*2 > treesz)
            return decompose(v, treesz, i);

    return i;
}

void centroid(ll i, ll p = 0, ll level = 0) {
    csize(i);
    ll cent = decompose(i, sz[i]);

    dead[cent] = 1;
    cpar[cent] = p;
    cenLevel[cent] = level;
    cenLevelDist(cent, level);

    for (auto v: graph[cent])
        if (!dead[v]) centroid(v, cent, level+1);
}

void paint(ll v) {
    ll p = v;
    while (p) {
        redDist[p] = min(redDist[p], cenDist[v][cenLevel[p]]);
        p = cpar[p];
    }
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1);
    cpar.resize(n+1), sz.resize(n+1), dis.resize(n+1), dead.resize(n+1);
    redDist.resize(n+1, LONG_LONG_MAX/3);
    cenDist.resize(n+1);
    cenLevel.resize(n+1);

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    centroid(1);
    paint(1);

    while (m--) {
        ll t, v; cin >> t >> v;

        if (t == 1) {
            paint(v);
        } else {
            ll p = v;
            ll res = LONG_LONG_MAX/3;
            while (p) {
                res = min(res, redDist[p]+cenDist[v][cenLevel[p]]);
                p = cpar[p];
            }
            cout << res << endl;
        }
    }

    return 0;
}
