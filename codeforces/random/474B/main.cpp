/*
 * LINK: https://codeforces.com/problemset/problem/474/B
 * NAME: B. Worms
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;
    vector<ll> vs(n+1);

    for (ll i = 1; i <= n; i++) {
        cin >> vs[i];
        vs[i] += vs[i-1];
    }

    ll q; cin >> q;
    while (q--) {
        ll v; cin >> v;
        cout << lower_bound(vs.begin(), vs.end(), v) - vs.begin() << endl;
        
    }
    return 0;
}
