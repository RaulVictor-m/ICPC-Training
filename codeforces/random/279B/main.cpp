/*
 * LINK: https://codeforces.com/problemset/problem/279/B
 * NAME: B. Books
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, t; cin >> n >> t;
    vector<ll> vs(n);

    for (auto &v: vs) cin >> v;

    int l = 0, r = 0;
    ll sum = vs.front();
    ll cnt = 0, mcnt = 0;

    while (r < n) {
        if (sum <= t) {
            cnt++, sum += vs[++r];
        } else {
            if (l < r) cnt--, sum -= vs[l++];
            else sum -= vs[l++], sum += vs[++r], cnt = 0;
        }
        mcnt = max(cnt, mcnt);
    }

    cout << mcnt << endl;
    return 0;
}
