/*
 * LINK: https://codeforces.com/gym/106073/problem/M
 * NAME: M. Minas Gerais' walls
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(vector<ll> vs, ll x, ll k) {
    for (int i = vs.size()-1; i >= 0; i--) {
        if (vs[i] < x) {
            if ((x-vs[i]) > k) return false;
            for (int j = i; j >= 0 && k > 0; j--, k--)
                vs[j] += k;
            k = 0;
        }
    }
    return true;
}

int main(void) {
    ll n, k; cin >> n >> k;
    vector<ll> vs(n);
    for (auto &v: vs) cin >> v;

    ll l = 1, r = 1e14, ans = 1;
    while (l <= r) {
        ll mid = (l+r)/2;
        if (check(vs, mid, k)) l = mid+1, ans = mid;
        else                   r = mid-1;
    }

    cout << ans << endl;
    return 0;
}
