/*
 * LINK: https://cses.fi/problemset/task/1621
 * NAME: Distinct Numbers
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    int n; cin >> n;
    vector<ll> vals(n);
    for (auto &v: vals) cin >> v;

    sort(vals.begin(), vals.end());
    cout << unique(vals.begin(), vals.end()) - vals.begin() << endl;
    return 0;
}
