/*
 * LINK: https://codeforces.com/problemset/problem/620/E
 * NAME: E. New Year Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 4e5+5;

namespace seg {
    ll t[N*8];
    bool mk[N*8];

    void build(int v, int tl, int tr, vector<ll> &vs) {
        if (tl == tr) t[v] = vs[tl];
        else {
            int tm = (tl+tr)/2;
            build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
            t[v] = t[v*2] | t[v*2+1];
        }
    }

    void push(int v) {
        if (mk[v]) {
            t[v*2] = t[v], t[v*2+1] = t[v];
            mk[v] = 0, mk[v*2] = 1, mk[v*2+1] = 1;
        }
    }

    void update(int v, int tl, int tr, int l, int r, ll val) {
        if (l > r) return;
        if (tl == l and tr == r) t[v] = val, mk[v] = 1;
        else {
            push(v);
            int tm = (tl+tr)/2;
            update(v*2, tl, tm, l, min(r, tm), val);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
            t[v] = t[v*2] | t[v*2+1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l and tr == r) return t[v];
        push(v);
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) | query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

vector<vector<int>> graph;
vector<ll> col, tin, tout;
vector<ll> col2;
ll t = 1;

void euler(int v, int p) {
    tin[v] = t++;
    col2.push_back(col[v]);
    for (auto u: graph[v]) if (u != p) euler(u, v);
    tout[v] = t-1;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1), col.resize(n+1), tin.resize(n+1), tout.resize(n+1);
    col2.resize(1);

    for (int i = 1; i <= n; i++) {
        ll cl; cin >> cl;
        col[i] = (1LL<<cl);
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    euler(1, 0);
    seg::build(1, 1, n, col2);
    while (m--) {
        ll type, v; cin >> type >> v;
        if (type == 1) {
            ll c; cin >> c;
            c = (1LL<<c);
            seg::update(1, 1, n, tin[v], tout[v], c);
        } else {
            cout << __builtin_popcountll(seg::query(1, 1, n, tin[v], tout[v])) << '\n';
        }
    }
    return 0;
}
