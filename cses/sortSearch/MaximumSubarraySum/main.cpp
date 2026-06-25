/*
 * LINK: https://cses.fi/problemset/task/1643
 * NAME: Maximum Subarray Sum
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    ll n; cin >> n;

    ll lmax = LONG_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        sum += v;

        lmax = max(lmax, sum);
        sum = sum < 0 ? 0: sum;
    }

    cout << lmax << endl;
    return 0;
}
