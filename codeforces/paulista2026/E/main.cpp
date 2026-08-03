/*
 * LINK: https://codeforces.com/gym/106598/problem/E
 * NAME: E. Space emergency
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+5;

namespace seg {
    ll t[N*4], st[N*4];
    bool mk[N*4];

    void build(int v, int tl, int tr, vector<ll>& vs) {
        if (tl == tr) {
            st[v] = t[v] = vs[tl];
            return;
        }
        int tm = (tl+tr)/2;

        build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
        st[v] = t[v] = t[v*2] + t[v*2+1];
    }

    void push(int v) {
        if (mk[v]) {
            t[v*2] = st[v*2] - t[v*2];
            t[v*2+1] = st[v*2+1] - t[v*2+1];
            mk[v*2] ^= 1, mk[v*2+1] ^= 1, mk[v] = 0;
        }
    }

    void inv(int v, int tl, int tr, int l, int r) {
        if (l > r) return;
        if (tl == l && tr == r) {
            t[v] = st[v] - t[v];
            mk[v] ^= 1;
        } else {
            push(v);
            int tm = (tl+tr)/2;
            inv(v*2, tl, tm, l, min(r, tm));
            inv(v*2+1, tm+1, tr, max(l, tm+1), r);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l && tr == r) return t[v];

        push(v);
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

vector<vector<int>> adj;
vector<int> par, sz, dep, hd, hv, pos;

void hl_dfs(int v) {
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == par[v]) continue;
        par[u] = v, dep[u] = dep[v]+1;

        hl_dfs(u), sz[v] += sz[u];
        if (sz[u] > sz[hv[v]]) hv[v] = u;
    }
}

int t = 1;
void hld(int v, int h) {
    hd[v] = h, pos[v] = t++;
    if (hv[v]) hld(hv[v], h);

    for (auto u: adj[v])
        if (u != par[v] && u != hv[v])
            hld(u, u);
}

int main(void) {
    int n, q; cin >> n >> q;
    adj.resize(n+1), par.resize(n+1), sz.resize(n+1), dep.resize(n+1);
    hd.resize(n+1), hv.resize(n+1), pos.resize(n+1);

    vector<array<ll, 3>> edges(n-1);
    for (auto &[a, b, w]: edges) cin >> a >> b >> w;

    for (auto &[a, b, w]: edges)
        adj[a].push_back(b), adj[b].push_back(a);

    hl_dfs(1);
    hld(1, 1);
    vector<ll> vs(t);

    for (auto &[a, b, w]: edges)
        vs[pos[(a == par[b] ? b : a)]] = w;

    seg::build(1, 1, t-1, vs);
    seg::inv(1, 1, t-1, 1, t-1); // invert all

    while (q--) {
        int a, b; cin >> a >> b;

        while (a != 0)
            seg::inv(1, 1, t-1, pos[hd[a]], pos[a]), a = par[hd[a]];

        while (b != 0)
            seg::inv(1, 1, t-1, pos[hd[b]], pos[b]), b = par[hd[b]];

        cout << seg::query(1, 1, t-1, 1, t-1) << '\n';
    }

    return 0;
}
