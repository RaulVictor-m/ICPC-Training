/*
 * LINK: https://cses.fi/problemset/task/1143
 * NAME: Hotel Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/
const ll maxn = 2e5+2;

namespace seg {
    ll t[maxn*2] = {0}, n = 0;

    void build(int size) {
        for (int i = (n=size)-1; i > 0; i--) t[i] = max(t[i<<1], t[i<<1|1]);
    }

    void update(ll p, ll v) {
        for (t[p+=n]=v; p > 1; p>>=1) t[p>>1] = max(t[p], t[p^1]);
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (l+=n, r+=n; l < r; r>>=1, l>>=1) {
            if (r&1) res = max(t[--r], res);
            if (l&1) res = max(res, t[l++]);
        }
        return res;
    }
}


int main(void) {
    ll n, q; cin >> n >> q;

    for (ll i = 0; i < n; i++) {
        ll v; cin >> v;
        seg::t[n+i] = v;
    }

    seg::build(n);

    for (ll i = 0; i < q; i++) {
        ll v; cin >> v;

        ll l = 0, r = n, mid, index = -1;
        while (l < r) {
            mid = (l+r)/2;
            auto iv = seg::query(l, mid+1);
            if (iv >= v) r = mid, index = mid;
            else         l = mid+1;
        }

        if (index >= 0) {
            seg::update(index, seg::t[index+n] - v);
            cout << index+1 << " ";
        } else cout << 0 << " ";
    }
    cout << endl;

    return 0;
}
