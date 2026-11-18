/*
 * LINK: https://cses.fi/problemset/task/1137
 * NAME: Subtree Queries
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

const int MAXN = 2e5+1;

namespace seg {
    ll t[MAXN*2];

    void update(int v, int tl, int tr, int p, ll x) {
        if (tl == tr) t[v] = x;
        else {
            int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;
            if (p <= tm) update(vl, tl, tm, p, x);
            else         update(vr, tm+1, tr, p, x);
            t[v] = t[vl] + t[vr];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l and tr == r) return t[v];

        int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;
        return query(vl, tl, tm, l, min(tm, r)) +
               query(vr, tm+1, tr, max(tm+1, l), r);
    }
}

vector<int> tin, tout;
vector<vector<int>> adj;

int t = 1;
void euler(int v, int p) {
    tin[v] = t++;

    for (auto u: adj[v])
        if (u != p) euler(u, v);

    tout[v] = t-1;
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q; cin >> n >> q;

    vector<int> vs(n+1);
    rep (i, 1, n+1) cin >> vs[i];

    tin.resize(n+1), tout.resize(n+1), adj.resize(n+1);

    rep (i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    euler(1, 0);
    rep (i, 1, n+1) seg::update(0, 1, n, tin[i], vs[i]);

    while (q--) {
        int tp; cin >> tp;

        if (tp == 1) {
            int s, x; cin >> s >> x;
            seg::update(0, 1, n, tin[s], x);
        } else {
            int s; cin >> s;
            cout << seg::query(0, 1, n, tin[s], tout[s]) << endl;
        }
    }

    return 0;
}

