/*
 * LINK: https://codeforces.com/problemset/problem/327/A
 * NAME: A. Flipping Game
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;
    ll t1 = 0, t2 = 0;
    ll tt = 0;

    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        if (v) t1++, t2--;
        else t2++;

        if (t2 < 0) t2 = 0;
        tt = max(t2, tt);
    }

    if (!tt) t1--;
    cout << tt+t1 << endl;
    return 0;
}
