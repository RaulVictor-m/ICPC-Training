/*
 * LINK: https://cses.fi/problemset/task/1640
 * NAME: Sum Of Two Values
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    ll n, x; cin >> n >> x;

    unordered_map<ll, ll> lmap;
    lmap.reserve((ll)2e5+2);

    for (ll i = 1; i <= n; i++) {
        ll a; cin >> a;

        if (lmap[a] != 0) {
            cout << lmap[a] << " " << i << endl;
            return 0;
        }

        lmap[x-a] = i;
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
