/*
 * LINK: https://codeforces.com/problemset/problem/987/C
 * NAME: C. Three displays
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = LONG_LONG_MAX/3;

int main(void) {
    int n; cin >> n;
    vector<ll> vf(n), vc(n);

    for (auto &v: vf) cin >> v;
    for (auto &v: vc) cin >> v;

    ll b = INF;
    for (int j = 0; j < n; j++) {
        ll bi = INF, bk = INF;
        for (int i = j-1; i >= 0; i--)
            if (vf[i] < vf[j]) bi = min(bi, vc[i]);

        for (int k = j+1; k < n; k++)
            if (vf[k] > vf[j]) bk = min(bk, vc[k]);
        b = min(b, bi+bk+vc[j]);
    }

    if (b < INF) cout << b << '\n';
    else cout << -1 << '\n';
    return 0;
}
