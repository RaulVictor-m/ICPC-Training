/*
 * LINK: https://cses.fi/problemset/task/1748
 * NAME: Increasing Subsequence II
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        its exactly the same as the first version of the problem
        the only diference is that the dp gets the sum of all
        values instead of the max

        dp[x] = sum(dp[0..x]);

*/
const ll MAXN = 1e5*2+1;
const ll MOD = 1e9+7;
namespace seg {
    ll seg[MAXN*2];
    ll n;

    #define join(a, b) (((a)+(b))%(MOD))

    void update(ll p, ll v) {
        for (seg[p+=n]=v; p > 1; p>>=1) seg[p>>1] = join(seg[p], seg[p^1]);
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (l&1) res = join(res, seg[l++]);
            if (r&1) res = join(res, seg[--r]);
        }
        return res;
    }
}

ll l_list[MAXN] = {0};

ll dpI(ll n) {
    seg::n = n;

    for (ll i = 0; i < n; i++) {
        seg::update(l_list[i], (seg::query(0, l_list[i]+1)+1)%MOD);
    }

    return seg::query(0, n);
}

int main(void) {
    ll n; cin >> n;

    //input 
    for (ll i = 0; i < n; i++) cin >> l_list[i];

    //compression
    set<ll> l_set;
    map<ll, ll> l_map;

    for (ll i = 0; i < n; i++) l_set.insert(l_list[i]);

    ll index = 0;
    for (auto v: l_set) l_map[v] = index++;

    for (ll i = 0; i < n; i++) l_list[i] = l_map[l_list[i]];

    cout << dpI(n) << endl;

    return 0;
}
