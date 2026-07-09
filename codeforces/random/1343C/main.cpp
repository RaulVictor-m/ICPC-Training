/*
 * LINK: https://codeforces.com/problemset/problem/1343/C
 * NAME: C. Alternating Subsequence
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        ll total = 0;
        ll l; cin >> l;

        for (int i = 1; i < n; i++) {
            ll v; cin >> v;
            if ((v>>63) ^ (l>>63)) {
                total += l;
                l = v;
            } else {
                l = max(l, v);
            }
        }
        total += l;
        cout << total << endl;

    }
    return 0;
}
