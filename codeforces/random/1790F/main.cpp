/*
 * LINK: https://codeforces.com/problemset/problem/1790/F
 * NAME: F. Timofey and Black-White Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<bool> black;
vector<int> order;

vector<int> par; // centroid parent
vector<bool> dead; // centroid parent
vector<int> sz;  // subtree size for centroid
vector<array<int, 20>> dist; // dist from centroid at level
vector<int> ans; // answer for every centroid subtree;
vector<int> close_black;
vector<int> clevel;

void csz(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v]) 
        if (u != p && !dead[u]) csz(u, v), sz[v] += sz[u];
}

int centroid(int v, int p, int tsz) {
    for (auto u: adj[v]) 
        if (u != p && !dead[u] && sz[u]*2 > tsz)
            return centroid(u, v, tsz);
    return v;
}

// precalculate the distance to centroid at level
void cdist(int v, int p, int d, int level) {
    dist[v][level] = d;
    for (auto u: adj[v])
        if (u != p && !dead[u]) cdist(u, v, d+1, level);
}

void solve(int v, int p, int level) {
    csz(v, p);
    int cent = centroid(v, p, sz[v]);
    par[cent] = p, dead[cent] = 1;
    clevel[cent] = level;

    cdist(cent, p, 0, level);

    for (auto u: adj[cent])
        if (!dead[u]) solve(u, cent, level+1);
}

int color(int v) {
    int v0 = v;
    int m = INT_MAX;
    while (v) {
        if (ans[v] > close_black[v] + dist[v0][clevel[v]]) {
            ans[v] = close_black[v] + dist[v0][clevel[v]];
        }

        if (close_black[v] > dist[v0][clevel[v]]) {
            close_black[v] = dist[v0][clevel[v]];
        }
        m = min(ans[v], m);
        v = par[v];
    }
    return m;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, c0; cin >> n >> c0;

        adj.clear(), adj.resize(n+1);
        par.clear(), par.resize(n+1);
        sz.clear(), sz.resize(n+1);
        dead.clear(), dead.resize(n+1);
        dist.clear(), dist.resize(n+1);
        ans.clear(), ans.resize(n+1, INT_MAX/2);
        clevel.clear(), clevel.resize(n+1);
        close_black.clear(), close_black.resize(n+1, INT_MAX/2);
        black.clear(), black.resize(n+1, 0);
        order.clear(), order.resize(n-1);

        for (auto &v: order) cin >> v;

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }


        solve(1, 0, 0);
        color(c0);
        black[c0] = 1;

        int an = INT_MAX;
        for (auto v: order) {
            an = min(an, color(v));
            cout << an << " ";
        }
        cout << endl;

    }
    return 0;
}
