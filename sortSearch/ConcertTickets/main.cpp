/*
 * LINK: https://cses.fi/problemset/task/1091
 * NAME: Concert Tickets
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    ll n, m; cin >> n >> m;
    multiset<ll> lset;
    for (ll i = 0, j; i < n; i++) {
        cin >> j;
        lset.insert(j);
    }

    for (int i = 0; i < m; i++) {
        ll v; cin >> v;
        auto it = lset.lower_bound(v);

        if (*it != v) {
            if (it != lset.begin()) it--;
            else {
                cout << -1 << endl;
                continue;
            }
        }

        cout << *it << endl;
        lset.erase(it);
    }

    return 0;
}
