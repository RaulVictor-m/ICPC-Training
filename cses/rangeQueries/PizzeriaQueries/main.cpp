/*
 * LINK: https://cses.fi/problemset/task/2206
 * NAME: PizzeriaQueries
 * STATE: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        there is basically left logic which from the formula is price - a + k
        and right with is price + a - k
        the thing is, inside the seg we do know a, so we abuse this fact and compute both
        only missing the k variable on both sides, which does not affect the result since
        no matter the k it will be constant for both so for the left we just need to find
        the min(price - a)+k and from the right the min(price + a)-k
*/

const ll maxn = 2e5+2;
const ll inf = LONG_LONG_MAX/4;
namespace seg {
    struct S { 
        ll lPrice, rPrice;
        S(ll a = inf, ll index = 0)  : lPrice(a-index), rPrice(a+index) {} 
    };

    S t[maxn*2];
    ll n = 0;

    S join (const S &a, const S &b) {
        S res;
        res.lPrice = min(a.lPrice, b.lPrice);
        res.rPrice = min(a.rPrice, b.rPrice);
        return res;
    }

    void build(ll num) {
        for (ll i = (n=num)-1; i > 0; i--) t[i] = join(t[i<<1], t[i<<1|1]);
    }

    void update(ll p, ll v) {
        for (t[p+=n]=S(v, p+1); p>>=1;) t[p] = join(t[p<<1], t[p<<1|1]);
    }

    S query(ll l, ll r) {
        S resr, resl;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) resr = join(t[--r], resr);
            if (l&1) resl = join(resl, t[l++]);
        }
        return join(resl, resr);
    }
}

int main(void) {
    ll n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        seg::t[i+n] = seg::S(v, i+1);
    }
    seg::build(n);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 2) {
            int k; cin >> k;
            auto l = seg::query(0, k);
            auto r = seg::query(k-1, n);
            cout << min(l.lPrice+k, r.rPrice-k) << endl;

        } else {
            int k, x; cin >> k >> x;
            seg::update(k-1, x);
        }
    }
    return 0;
}
