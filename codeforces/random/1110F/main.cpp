/*
 * LINK: https://codeforces.com/problemset/problem/1110/F
 * NAME: F. Nearest Leaf
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+5;
const ll INF = 1e16;

namespace seg {
    vector<ll> t(N*4), lz(N*4);
    void build(int v, int tl, int tr, vector<ll> vs) {
        if (tl == tr) {
            t[v] = vs[tl];
            return;
        }

        int tm = (tl+tr)/2;
        build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
        t[v] = min(t[v*2], t[v*2+1]);
    }

    void push(int v) {
        t[v*2] += lz[v], t[v*2+1] += lz[v];
        lz[v*2] += lz[v], lz[v*2+1] += lz[v];
        lz[v] = 0;
    }

    void add(int v, int tl, int tr, int l, int r, ll x) {
        if (l > r) return;
        if (tl == l and tr == r) {
            t[v] += x, lz[v] += x;
        } else {
            push(v);
            int tm = (tl+tr)/2;
            add(v*2, tl, tm, l, min(r, tm), x);
            add(v*2+1, tm+1, tr, max(l, tm+1), r, x);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return INF;
        if (tl == l and tr == r) return t[v];
        push(v);
        int tm = (tl+tr)/2;
        return min(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

vector<vector<pair<int, ll>>> adj(N);
vector<vector<pair<int, pair<int, int>>>> q(N);
vector<ll> ans(N), ver(N, INF);
vector<int> tin(N), tout(N);

int t = 1;
void euler(int v, ll d) {
    if (adj[v].empty()) ver[t] = d;
    tin[v] = t++;
    for (auto [u, w]: adj[v]) euler(u, w+d);
    tout[v] = t-1;
}

void solve(int v) {
    for (auto &[id, r]: q[v])
        ans[id] = seg::query(1, 1, t, r.first, r.second);

    for (auto [u, w]: adj[v]) {
        seg::add(1, 1, t, 1, t, w);
        seg::add(1, 1, t, tin[u], tout[u], -(w*2));
        solve(u);
        seg::add(1, 1, t, 1, t, -w);
        seg::add(1, 1, t, tin[u], tout[u], (w*2));
    }
}

int main(void) {
    int n, m; cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        ll v, w; cin >> v >> w;
        adj[v].emplace_back(i, w);
    }


    for (int i = 1; i <= m; i++) {
        int v, l, r; cin >> v >> l >> r;
        q[v].push_back({i, {l, r}});
    }

    euler(1, 0), t--;
    seg::build(1, 1, t, ver);
    solve(1);

    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';

    return 0;
}
