/*
 * LINK: https://cses.fi/problemset/task/1749
 * NAME: List Removals
 * STATUS: BROKEN
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = (1e5+2)*2;
namespace seg {
    ll seg[MAXN*2] = {0};
    ll n = 0;

    void build() {
        for (ll i = n-1; i > 0; i--) seg[i] = seg[i<<1] + seg[i<<1|1];
    }

    void add(ll p, ll v) {
        for (seg[p+=n]+=v; p > 1; p>>=1) seg[p>>1] = seg[p] + seg[p^1];
    }

    void update(ll p, ll v) {
        for (seg[p+=n]=v; p > 1; p>>=1) seg[p>>1] = seg[p] + seg[p^1];
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (r+=n, l+=n; l < r; l>>=1, r>>=1) {
            if (r&1) res += seg[--r];
            if (l&1) res += seg[l++];
        }
        return res;
    }
}

ll vals[MAXN] = {0};

int main(void) {
    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) cin >> vals[i];

    seg::n = n+1;
    for (ll i = 0; i <= n; i++) seg::seg[seg::n + i] = 1;

    seg::build();

    for (ll i = 0; i < n; i++) {
        ll q; cin >> q;
        ll index = seg::query(0, q);

        cout << vals[index] << " ";
        // for (ll i = 0; i <= n; i++) cout << seg::seg[seg::n+i] << " ";
        // cout << endl;

        ll c_val = seg::seg[q + seg::n];
        seg::add(q-1, c_val);
        seg::update(q, 1);
    }


    // quick_exit(0);
    return 0;
}
