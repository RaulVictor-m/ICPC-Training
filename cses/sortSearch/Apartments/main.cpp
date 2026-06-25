/*
 * LINK: https://cses.fi/problemset/task/1084
 * NAME: Apartments
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    ll n, m, k; cin >> n >> m >> k;

    vector<ll> apl(n);
    vector<ll> apr(m);

    for (auto &v : apl) cin >> v;
    for (auto &v : apr) cin >> v;

    sort(apl.begin(), apl.end());
    sort(apr.begin(), apr.end());

    ll total = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (abs(apl[i] - apr[j]) <= k) total++, i++, j++; else
        if (apl[i] > apr[j]) j++; 
        else i++;
    }

    cout << total << endl;
    return 0;
}
