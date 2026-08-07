/*
 * LINK: https://codeforces.com/problemset/problem/920/F
 * NAME: F. SUM and REPLACE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 3e5+5;

namespace seg {
    struct Node {ll sum, mv, mi; };
    Node t[N*4];

    Node mkNode (ll v, ll i) {
        return Node{v, v, i};
    }

    Node join(Node a, Node b) {
        Node res;
        res.sum = a.sum + b.sum;
        if (a.mv > b.mv) res.mv = a.mv, res.mi = a.mi;
        else             res.mv = b.mv, res.mi = b.mi;
        return res;
    }

    void build(int v, int tl, int tr, vector<ll>& vs) {
        if (tl == tr) {
            t[v] = mkNode(vs[tl], tl);
            return;
        }

        int tm = (tl+tr)/2;
        build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
        t[v] = join(t[v*2], t[v*2+1]);
    }

    void update(int v, int tl, int tr, int p, ll x) {
        if (tl == tr) {
            t[v] = mkNode(x, tl); 
            return;
        }

        int tm = (tl+tr)/2;
        if (p <= tm) update(v*2, tl, tm, p, x) ;
        else         update(v*2+1, tm+1, tr, p, x);

        t[v] = join(t[v*2], t[v*2+1]);
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return mkNode(0, 0);
        if (l == tl && r == tr) return t[v];

        int tm = (tl+tr)/2;
        return join(query(v*2, tl, tm, l, min(r, tm)), 
                    query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

void up(int l, int r, vector<ll>& d, int n) {
    if (l > r) return;
    auto v = seg::query(1, 1, n, l, r);
    if (d[v.mv] < v.mv) {
        seg::update(1, 1, n, v.mi, d[v.mv]);
        up(l, v.mi-1, d, n), up(v.mi+1, r, d, n) ;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    vector<ll> vs(n+1);
    for (int i = 1; i <= n; i++) cin >> vs[i];
    seg::build(1, 1, n, vs);

    vector<ll> d(1e6+1);
    for (int i = 1; i <= 1e6; i++)
        for (int j = i; j <= 1e6; j+=i) d[j]++;

    while (m--) {
        int t, l, r; cin >> t >> l >> r;

        if (t == 1) up(l, r, d, n);
        else cout << seg::query(1, 1, n, l, r).sum << endl;


    }
    return 0;
}
