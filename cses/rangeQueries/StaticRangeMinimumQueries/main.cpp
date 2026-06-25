/*
 * LINK: https://cses.fi/problemset/task/1647
 * NAME: Static Range Minimum Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


const ll inf = LONG_MAX/3;
int main(void) {
    ll n, q; cin >> n >> q;
    vector<ll> seg(n*2, inf);

    for (int i = 0; i < n; i++) cin >> seg[i+n];
    for (int i = n-1; i > 0; i--) seg[i] = min(seg[i<<1], seg[i<<1|1]);

    while(q--) {
        ll l, r, res = inf; cin >> l >> r;
        for (l+=n-1, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) res = min(res, seg[--r]);
            if (l&1) res = min(res, seg[l++]);
        }
        cout << res << endl;
    }
    return 0;
}
