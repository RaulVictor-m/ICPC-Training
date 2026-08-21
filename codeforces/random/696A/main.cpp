/*
 * LINK: https://codeforces.com/problemset/problem/696/A
 * NAME: A. Lorenzo Von Matterhorn
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, ll> fees;

int main(void) {
    ll q; cin >> q;

    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll v, u, w; cin >> v >> u >> w;
            while (v != u) {
                if (u > v) fees[u] += w, u>>=1;
                else       fees[v] += w, v>>=1;
            }
        } else {
            ll v, u, w = 0; cin >> v >> u;
            while (v != u) {
                if (u < v) swap(u, v);
                if (fees.count(u)) w += fees[u];
                u>>=1;
            }

            cout << w << endl;
        }
    }
    return 0;
}
