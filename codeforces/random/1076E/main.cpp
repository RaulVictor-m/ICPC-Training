/*
 * LINK: https://codeforces.com/problemset/problem/1076/E
 * NAME: E. Vasya and a Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3e5+5;

namespace seg {
    ll t[N*4];

    void add(int v, int tl, int tr, int l, int r, ll val) {
        if (l > r) return;

        if (tl == l && tr == r) {
            t[v] += val;
        }
        else {
            int tm = (tl+tr)/2;
            add(v*2, tl, tm, l, min(r, tm), val);
            add(v*2+1, tm+1, tr, max(tm+1, l), r, val);
        }
    }

    ll query(int v, int tl, int tr, int p) {
        if (tl == tr) return t[v];

        int tm = (tl+tr)/2;
        if (p <= tm) return query(v*2, tl, tm, p)+t[v];
        else         return query(v*2+1, tm+1, tr, p)+t[v];
    }
}

vector<vector<int>> adj;
vector<ll> vs, ht;
vector<vector<pair<ll, ll>>> q;

void dfs(int v, int p) {
    for (auto [d, x]: q[v])
        seg::add(1, 0, ht.size(), ht[v], min((ll)ht[v]+d, (ll)ht.size()), x);

    vs[v] = seg::query(1, 0, ht.size(), ht[v]);

    for (auto u: adj[v]) 
        if (u != p) ht[u] = ht[v]+1, dfs(u, v);

    for (auto [d, x]: q[v])
        seg::add(1, 0, ht.size(), ht[v], min((ll)ht[v]+d, (ll)ht.size()), -x);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n+1), vs.resize(n+1), ht.resize(n+1), q.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int m; cin >> m;
    while (m--) {
        ll v, d, x; cin >> v >> d >> x;
        q[v].emplace_back(d, x);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) cout << vs[i] << " "; cout << endl;
    return 0;
}
