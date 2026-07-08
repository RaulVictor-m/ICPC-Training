/*
 * LINK: https://codeforces.com/problemset/problem/1520/D
 * NAME: Same Differences
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// a_j - a_i = j - i
// a_j - j = a_i - i

int main(void) {
    ll t; cin >> t;
    map<ll, ll> vs;
    while (t--) {
        ll n; cin >> n;
        vs.clear();

        ll total = 0;
        for (int i = 0; i < n; i++) {
            ll v; cin >> v;
            v-=(i+1);
            if (vs.count(v)) total+=vs[v];
            vs[v]++;
        }

        cout << total << endl;
    }
    return 0;
}
