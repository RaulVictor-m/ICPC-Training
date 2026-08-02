/*
 * LINK: https://codeforces.com/problemset/problem/343/D
 * NAME: D. Water Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+5;

namespace seg {
    bool t[N*4], mk[N*4];

    void push(int v) {
        if (mk[v]) {
            t[v*2] = t[v*2+1] = t[v];
            mk[v*2] = mk[v*2+1] = 1, mk[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, bool val) {
        if (l > r) return;
        if (tl == l && tr == r)
            t[v] = val, mk[v] = 1;
        else {
            push(v);
            int tm = (tl+tr)/2;
            update(v*2, tl, tm, l, min(tm, r), val);
            update(v*2+1, tm+1, tr, max(tm+1, l), r, val);
        }
    }

    bool query(int v, int tl, int tr, int p) {
        if (tl == tr) return t[v];

        push(v);
        int tm = (tl+tr)/2;
        if (p <= tm) return query(v*2, tl, tm, p);
        else         return query(v*2+1, tm+1, tr, p);
    }
}

vector<vector<int>> adj;
vector<int> par, hv, hd, sz, dep, pos, tout;

void hl_dfs(int v) {
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == par[v]) continue;
        par[u] = v, dep[u] = dep[v]+1;

        hl_dfs(u), sz[v] += sz[u];
        if (sz[hv[v]] < sz[u]) hv[v] = u;
    }
}

int t = 1;
void hld(int v, int h) {
    hd[v] = h, pos[v] = t++;
    if (hv[v]) hld(hv[v], h);

    for (auto u: adj[v])
        if (u != par[v] && u != hv[v]) hld(u, u);
    tout[v] = t-1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n+1), dep.resize(n+1), pos.resize(n+1), tout.resize(n+1);
    par.resize(n+1), hv.resize(n+1), hd.resize(n+1), sz.resize(n+1); 

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    hl_dfs(1);
    hld(1, 1);

    int q; cin >> q;
    while (q--) {
        int tp, v; cin >> tp >> v;
        if (tp == 1) seg::update(1, 1, t-1, pos[v], tout[v], 1); else 
        if (tp == 3) cout << seg::query(1, 1, t-1, pos[v]) << '\n';
        else while (v != 0) {
            seg::update(1, 1, t-1, pos[hd[v]], pos[v], 0);
            v = par[hd[v]];
        }
    }

    return 0;
}
