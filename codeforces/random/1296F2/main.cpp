/*
 * LINK: https://codeforces.com/problemset/problem/1296/F
 * NAME: F. Berland Beauty
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e3+5;

namespace seg {
    int t[N*4];
    bool mk[N*4];

    void push(int v) {
        if (mk[v]) {
            t[v*2] = t[v*2+1] = t[v];
            mk[v*2] = mk[v*2+1] = 1, mk[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        if (l > r) return;
        if (tl == l && tr == r) {
            t[v] = val;
            mk[v] = 1;
        } else {
            push(v);
            int tm = (tl+tr)/2;
            update(v*2, tl, tm, l, min(r, tm), val);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return INT_MAX;
        if (tl == l && tr == r) return t[v];
        int tm = (tl+tr)/2;
        push(v);

        return min(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

}

vector<vector<int>> adj;
vector<int> par, hv, hd, sz, pos, deaph; // parent, heavy, head

void hl_dfs(int v) {
    for (auto u: adj[v]) {
        if (u == par[v]) continue;
        par[u] = v, sz[u] = 1, deaph[u] = deaph[v]+1;

        hl_dfs(u), sz[v] += sz[u];

        if (sz[hv[v]] < sz[u]) hv[v] = u; // hv[v] will be biggest subtree
    }
}

int t = 1;
void hld(int v, int head) {
    hd[v] = head, pos[v] = t++;

    if (hv[v]) hld(hv[v], head);

    for (auto u: adj[v]) 
        if (u != par[v] && u != hv[v]) hld(u, u);
}

void qmod(int a, int b, int w) {
    while (hd[a] != hd[b]) {
        if (deaph[hd[a]] > deaph[hd[b]]) swap(a, b);
        seg::update(1, 1, t-1, pos[hd[b]], pos[b], w);
        b = par[hd[b]];
    }

    if (pos[a] > pos[b]) swap(a, b);
    if (pos[a]+1 <= pos[b]) //skiping the lca head to get only the edges
        seg::update(1, 1, t-1, pos[a]+1, pos[b], w);
}

bool qcheck(int a, int b, int w) {
    int m = INT_MAX;
    while (hd[a] != hd[b]) {
        if (deaph[hd[a]] > deaph[hd[b]]) swap(a, b);
        m = min(m, seg::query(1, 1, t-1, pos[hd[b]], pos[b]));
        b = par[hd[b]];
    }

    if (pos[a] > pos[b]) swap(a, b);
    if (pos[a]+1 <= pos[b]) //skiping the lca head to get only the edges
        m = min(m, seg::query(1, 1, t-1, pos[a]+1, pos[b]));

    return (m == w);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n+1);
    par.resize(n+1), hv.resize(n+1), hd.resize(n+1), sz.resize(n+1), pos.resize(n+1);
    deaph.resize(n+1);

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.emplace_back(a, b);
    }

    hl_dfs(1);
    hld(1, 1);

    int m; cin >> m;
    seg::update(1, 1, t-1, 1, t-1, 1e6);

    vector<array<int, 3>> q(m);
    for (auto &[w, a, b]: q) cin >> a >> b >> w;

    sort(q.begin(), q.end());
    for (auto &[w, a, b]: q) qmod(a, b, w);

    for (auto &[w, a, b]: q) 
        if (!qcheck(a, b, w)) {
            cout << -1 << endl;
            return false;
        }

    for (auto [a, b]: edges) {
        if (deaph[a] > deaph[b]) swap(a, b);
        cout << seg::query(1, 1, t-1, pos[b], pos[b]) << ' ';
    }

    cout << endl;

    return 0;
}
