/*
 * LINK: https://cses.fi/problemset/task/1074
 * NAME: Stick Lengths
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    ll n; cin >> n;
    vector<ll> vals(n);

    for (ll &v: vals) cin >> v;
    sort(vals.begin(), vals.end());

    ll total = 0, median = vals[n/2];
    for (ll v: vals) total += abs(v-median);

    cout << total << endl;
    return 0;
}
