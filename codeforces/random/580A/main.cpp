/*
 * LINK: https://codeforces.com/problemset/problem/580/A
 * NAME: A. Kefa and First Steps
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(void) {
    ll n, l, c = 1, cmax = 1; cin >> n >> l;

    for (int i = 1; i < n; i++) {
        ll v; cin >> v;
        if (v >= l) c++; else c = 1;
        cmax = max(cmax, c), l = v;
    }

    cout << cmax << endl;
    return 0;
}
