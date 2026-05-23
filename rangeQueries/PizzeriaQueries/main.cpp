/*
 * LINK: https://cses.fi/problemset/task/2206
 * NAME: PizzeriaQueries
 * STATE: BROKEN - no idea
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll maxn = 2e5+2;
const ll inf = LONG_LONG_MAX/4;
namespace seg {
    struct S { 
        ll dist, pPrice, sPrice;
        S(ll a = inf)  : dist(1), pPrice(a), sPrice(a) {} 
    };

    S t[maxn*2];
    ll n = 0;

    S join (const S &a, const S &b) {
        S res;
        res.dist = a.dist + b.dist;
        res.sPrice = min(a.sPrice, b.sPrice + b.dist);
        res.pPrice = min(b.pPrice, a.pPrice + a.dist);
        printf("join(S{%d, %d, %d}, S{%d, %d, %d}} = ", a.dist, a.sPrice, a.pPrice, b.dist, b.sPrice, b.pPrice);
        printf("res(S{%d, %d, %d}) \n", res.dist, res.sPrice, res.pPrice);
        return res;
    }

    void build(ll num) {
        for (ll i = (n=num)-1; i > 0; i--) t[i] = join(t[i<<1], t[i<<1|1]);
    }

    void update(ll p, ll v) {
        for (t[p+=n]=S(v); p>>=1;) t[p] = join(t[p<<1], t[p<<1|1]);
    }

    S query(ll l, ll r) {
        S resr, resl;
        // resr.dist = resl.dist = 0;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) resr = join(t[--r], resr);
            if (l&1) resl = join(resl, t[l++]);
            // cout << "resr  r = " << r << ", p = " << resr.pPrice << ", s = " << resr.sPrice << endl;
            // cout << "resl  l = " << l << ", p = " << resl.pPrice << ", s = " << resl.sPrice << endl << endl;
        }
        // resr.dist = resl.dist = 0;
        return join(resl, resr);
    }
}

int main(void) {
    ll n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        seg::t[i+n] = seg::S(v);
    }
    seg::build(n);

    for (int i = 0; i < n*2; i++) cout << seg::t[i].pPrice << " "; cout << endl;

    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 2) {
            int k; cin >> k;
            auto l = seg::query(0, k);
            auto r = seg::query(k-1, n);
            // cout << "l p = " << l.pPrice << endl;
            // cout << "l s = " << l.sPrice << endl;
            // cout << "r p = " << r.pPrice << endl;
            // cout << "r s = " << r.sPrice << endl;

            cout << min(l.pPrice, r.sPrice) << endl;
        } else {
            // int k, x; cin >> k >> x;
            // seg::update(k-1, x);
        }

    }
    return 0;
}
