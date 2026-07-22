/*
 * LINK: https://cses.fi/problemset/task/1648
 * NAME: Dynamic Range Sum Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5+2;

namespace seg {
    ll t[N*4];
    void build(vector<ll> &vs, int v, int tl, int tr) {
        if (tl == tr) t[v] = vs[tl];
        else {
            int tm = (tl+tr)/2;
            build(vs, v*2, tl, tm), build(vs, v*2+1, tm+1, tr);
            t[v] = t[v*2]+t[v*2+1];
        }
    }

    void update(int v, int tl, int tr, int p, ll val) {
        if (tl == tr) t[v] = val;
        else {
            int tm = (tl+tr)/2;
            if (p <= tm) update(v*2, tl, tm, p, val);
            else         update(v*2+1, tm+1, tr, p, val);
            t[v] = t[v*2]+t[v*2+1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (r < l) return 0;
        if (tl == l and tr == r) return t[v];
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) + 
               query(v*2+1, tm+1, tr, max(tm+1, l), r);
    }
}

int main(void) {
    int n, q; cin >> n >> q;
    vector<ll> vs(n+1);
    for (int i = 1; i <= n; i++) cin >> vs[i];
    seg::build(vs, 1, 1, n);

    while (q--) {
        int t, a, b; cin >> t >> a >> b;

        if (t == 1) seg::update(1, 1, n, a, b);
        else        cout << seg::query(1, 1, n, a, b) << '\n';
    }
    return 0;
}
