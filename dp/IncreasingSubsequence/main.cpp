/*
 * LINK: https://cses.fi/problemset/task/1145
 * NAME: Increasing Subsequence
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        dp[x] = max(dp[0..x])+1;

        the trick here is to use coordinate compression to be able to fit
        the values of x in the dp

        and make the dp itself a segtree so that computing the max in a range 
        is O(logn)

*/
const ll MAXN = 1e5*2+1;
namespace seg {
    ll seg[MAXN*2];
    ll n; // set n before build

    #define join(a,b) std::max((a), (b));
    void build() {
        for (ll i = n-1; i > 0; i--) seg[i] = join(seg[i<<1], seg[i<<1|1]);
    }

    void update(ll pos, ll val) {
        for (seg[pos+=n] = val; pos > 1; pos >>= 1) seg[pos>>1] = join(seg[pos], seg[pos^1]);
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = join(res, seg[l++]);
            if (r&1) res = join(res, seg[--r]);
        }
        return res;
    }
};

ll l_list[MAXN] = {0};

ll dpI(ll n) {
    seg::n = n;
    for (ll i = 0; i < n; i++) {
        seg::update(l_list[i], seg::query(0, l_list[i])+1);
    }
    return seg::query(0, n);
}

int main(void) {
    int n; cin >> n;

    // input
    for (ll i = 0; i < n; i++) cin >> l_list[i];

    // compression
    set<ll> l_set;
    map<ll, ll> l_map;

    for (ll i = 0; i < n; i++) l_set.insert(l_list[i]);

    ll index = 0;
    for (auto v: l_set) l_map[v] = index++;

    for (ll i = 0; i < n; i++) l_list[i] = l_map[l_list[i]];

    cout << dpI(n) << endl;
    return 0;
}
