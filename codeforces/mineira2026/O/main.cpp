/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/O
 * NAME: O. Operations in Order
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
int main(void) {
    ll n, s = 0, m = 1; cin >> n;
    for (ll i = 0; i < n; i++) {
        char op;
        ll v; cin >> op >> v;

        if (op == '*') s = (s*v)%MOD, m = (v*m)%MOD; else
        if (op == '+') s = (s+v)%MOD;
        else cout << (((v*m)%MOD)+s)%MOD << endl;
    }
    return 0;
}
