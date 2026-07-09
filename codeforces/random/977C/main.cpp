/*
 * LINK: https://codeforces.com/problemset/problem/977/C
 * NAME: C. Less or Equal
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, k; cin >> n >> k;

    vector<ll> vs(n);
    for (auto &v: vs) cin >> v;

    for (ll l = 1, r = 1e9, mid = (l+r)/2; l <= r; mid = (l+r)/2) {

        ll tk = k;
        for (auto v: vs) if (v <= mid) tk--;

        if (tk == 0) {
            cout << mid << endl;
            return 0;
        }

        if (tk > 0) l = mid+1; else
        if (tk < 0) r = mid-1;
    }

    cout << -1 << endl;
    return 0;
}
