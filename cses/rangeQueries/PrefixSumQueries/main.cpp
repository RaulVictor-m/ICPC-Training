/*
 * LINK: https://cses.fi/problemset/task/2166
 * NAME: Prefix Sum Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = (1e5 + 2) * 2;

namespace seg {
    struct node { ll sum, pref; node(ll s = 0, ll p = 0) : sum(s), pref(p) {}};
    node seg[MAXN*2] = {0};
    ll n = 0;

    node join(node a, node b) {
        return node(a.sum + b.sum, max(a.pref, a.sum + b.pref));
    }

    void build(int num) {
        for (int i = (n=num)-1; i > 0; i--) seg[i] = join(seg[i<<1], seg[i<<1|1]);
    }

    void update(int p, ll v) {
        for (seg[p+=n]=node(v, v); p>>=1;) seg[p] = join(seg[p<<1], seg[p<<1|1]);
    }

    ll query(int l, int r) {
        node resr, resl;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (l&1) resl = join(resl, seg[l++]);
            if (r&1) resr = join(seg[--r], resr);
        }

        return join(resl, resr).pref;
    }
}


int main(void) {
    ll n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        seg::seg[i+n] = seg::node(v, v);
    }
    seg::build(n);

    for (int i = 0; i < q; i++) {
        ll op, a, b; cin >> op >> a >> b;

        if (op == 1) seg::update(a-1, b);
        else cout << seg::query(a-1, b) << endl;
    }

    return 0;
}
