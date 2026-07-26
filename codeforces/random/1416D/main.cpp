/*
 * LINK: https://codeforces.com/problemset/problem/1416/D
 * NAME: D. Graph and Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+5;

namespace seg {
    pair<int, int> t[N*8];

    void build(int v, int tl, int tr, vector<int> &vs) {
        if (tl == tr) t[v] = {vs[tl], tl};
        else {
            int tm = (tl+tr)/2;
            build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    void update(int v, int tl, int tr, int p, int val) {
        if (tl == tr) t[v].first = val;
        else {
            int tm = (tl+tr)/2;
            if (p <= tm)  update(v*2, tl, tm, p, val);
            else          update(v*2+1, tm+1, tr, p, val);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    pair<int, int> query(int v, int tl, int tr, int l, int r) {
        if (l > r) return {0, 0};
        if (tl == l and tr == r) return t[v];

        int tm = (tl+tr)/2;
        return max(query(v*2, tl, tm, l, min(tm, r)),
                   query(v*2+1, tm+1, tr, max(tm+1, l), r));
    }
}

namespace dsu {
    vector<int> par;

    void build(int n) {
        par.resize((n+1)*2);
        iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        if (par[v] == v) return v;
        return par[v] = find(par[v]);
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        par[b] = a;
    }
}

vector<vector<int>> tree;
vector<int> tin, tout;

int t = 1;
void euler(int v) {
    tin[v] = t++;
    for (auto u: tree[v]) euler(u);
    tout[v] = t-1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;

    vector<pair<int, int>> edges(m+1),  queries(q);
    vector<bool> dead(m+1); //dead edges
    vector<int> vs(n+1);;

    for (int i = 1; i <= n; i++) cin >> vs[i];
    for (int i = 1; i <= m; i++) cin >> edges[i].first >> edges[i].second;
    for (auto &[t, v]: queries) {
        cin >> t >> v;
        if (t == 2) dead[v] = 1;
    }

    dsu::build(n);
    reverse(queries.begin(), queries.end());

    int nroot = n+1;
    tree.resize(nroot*2), tin.resize(nroot*2), tout.resize(nroot*2);

    for (int i = 1; i <= m; i++) {
        if (dead[i]) continue;

        auto [a, b] = edges[i];
        a = dsu::find(a), b = dsu::find(b);
        if (a != b) {
            dsu::par[a] = nroot, dsu::par[b] = nroot;
            tree[nroot].push_back(a);
            tree[nroot].push_back(b);
            nroot++;
        }
    }

    vector<int> ans_v;
    for (auto [t, v]: queries) {
        if (t == 2) {
            auto [a, b] = edges[v];
            a = dsu::find(a), b = dsu::find(b);
            if (a != b) {
                dsu::par[a] = nroot, dsu::par[b] = nroot;
                tree[nroot].push_back(a);
                tree[nroot].push_back(b);
                nroot++;
            }
        } else ans_v.push_back(dsu::find(v));
    }

    for (int i = 1; i < nroot; i++)
        if (dsu::find(i) == i) euler(dsu::find(i));

    vector<int> vsn(t--); // ordered by euler tour
    for (int i = 1; i <= n; i++)
        vsn[tin[i]] = vs[i];

    seg::build(1, 1, t, vsn);

    reverse(ans_v.begin(), ans_v.end());
    for (auto v: ans_v) {

        auto [val, i] = seg::query(1, 1, t, tin[v], tout[v]);
        cout << val << endl;

        seg::update(1, 1, t, i, 0);
    }
    return 0;
}
