/*
 * LINK: https://cses.fi/problemset/task/1090
 * NAME: Ferris Wheel
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    ll n, k; cin >> n >> k;
    vector<ll> vals(n);
    for (auto &v: vals) cin >> v;

    sort(vals.begin(), vals.end());

    ll total=0;
    for (int i = 0, j = vals.size()-1; i <= j;) {
        if (vals[j] + vals[i] <= k) i++, j--, total++;
        else j--, total++;
    }

    cout << total << endl;
    return 0;
}
