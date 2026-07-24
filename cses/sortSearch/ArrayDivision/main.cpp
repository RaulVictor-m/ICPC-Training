/*
 * LINK: https://cses.fi/problemset/task/1085
 * NAME: Array Division
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool test(ll max_val, ll k, vector<ll>& vs) {
    ll lasti = 1;
    for (int i = 1; i < vs.size(); i++) {
        if ((vs[i] - vs[lasti-1]) > max_val) 
            lasti = i, k--;

        if (vs[i] - vs[i-1] > max_val) return false;
        if (!k) return false;
    }
    return true;
}

int main(void) {
    ll n, k; cin >> n >> k;
    vector<ll> vs(n+1);

    for (int i = 1; i <= n; i++) cin >> vs[i];
    for (int i = 2; i <= n; i++) vs[i] += vs[i-1];

    ll r = 1e15, l = 1;
    ll index = -1;
    while (l <= r) {
        ll mid = (r+l)/2;

        if (test(mid, k, vs)) // can be smaller
            r = mid-1, index = mid;
        else                  // has to be bigger
            l = mid+1;
    }

    cout << index << endl;
    return 0;
}
