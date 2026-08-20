/*
 * LINK: https://codeforces.com/problemset/problem/1066/D
 * NAME: D. Boxes Packing
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m, k; cin >> n >> m >> k;

    vector<ll> vs(n);

    for (auto &u: vs) cin >> u;

    auto check = [&vs](ll k, ll m, ll t) -> bool {
        ll sum = 0;
        for (int i = vs.size()-t; i < vs.size(); i++) {
            if (sum+vs[i] > k) m--, sum = vs[i];
            else           sum += vs[i];
        }
        return m > 0;
    };

    int l = 0, r = n, res = 0;
    while (l <= r) {
        int mid = (l+r)/2;
        if (check(k, m, mid)) l = mid+1, res = mid;
        else                  r = mid-1;
    }

    cout << res << endl;
    return 0;
}
