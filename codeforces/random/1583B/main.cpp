/*
 * LINK: https://codeforces.com/problemset/problem/1583/B
 * NAME: B. Omkar and Heavenly Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll t; cin >> t;
    vector<bool> isb;

    while (t--) {
        ll n, m; cin >> n >> m;
        isb.clear(), isb.resize(n+1, 0);

        while (m--) {
            ll a, b, c; cin >> a >> b >> c;
            isb[b] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!isb[i]) {
                for (int j = 1; j <= n; j++) 
                    if (i != j) cout << i << " " << j << endl;
                break;
            }
        }
    }
    return 0;
}
