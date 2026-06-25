/*
 * LINK: https://cses.fi/problemset/task/1651
 * NAME: Range Update Queries
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        its just a segtree where I put the positive value add
        where the range begins and puts the same value but negative where it ends
        and them to know the result of a single value
        i just query from 0 to the value. And that will acount only for the values 
        added to that range since the previuos ranges addition will be subtrated
        before it gets to the value

        and then knowing exactly how much has to be added to the value in the range
        i just sum it with the original value

        so like
        original list
        1 1 1 1 1

        query:
        1 2 4 1
        seg:
        0 1 0 -1 0

        so if someone asks value of 3
        query 1 to 4
        (0 + 1 + 0) = 1

        and sum the original value 1

        (1 + 1)
        so it would be 2
*/
const ll MAXN = 1e5*2 + 4;

namespace seg {
    ll seg[MAXN*2] = {0};
    ll n;

    void add(ll p, ll v) {
        for (seg[p+=n]+=v; p > 1; p>>=1) seg[p>>1] = seg[p] + seg[p^1];
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) res += seg[--r];
            if (l&1) res += seg[l++];
        }
        return res;
    }
}
ll l_list[MAXN] = {0};

int main(void) {
    ll n, q; cin >> n >> q;

    for (ll i = 0;i < n; i++) {
        cin >> l_list[i];
    }

    seg::n = n+1;
    for (ll i = 0;i < q; i++) {
        ll query; cin >> query;

        if (query == 1) {
            ll l, r, v; cin >> l >> r >> v;
            seg::add(--l, v);
            seg::add(r, (-v));
        } else {
            ll p; cin >> p;
            cout << l_list[(p-1)] + seg::query(0, p) << endl;
        }
    }

    // for (ll i = 0;i < (n+1)*2; i++) {
    //     cout << seg::seg[i] << " ";
    // }
    return 0;
}
