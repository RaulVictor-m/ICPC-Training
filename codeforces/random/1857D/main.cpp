/*
 * LINK: https://codeforces.com/problemset/problem/1857/D
 * NAME: D. Strong Vertices
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    a_u - a_v >= b_u - b_v
    a_u - b_u >= a_v - b_v
*/


int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<pair<ll, ll>> vs(n);

        for (int i = 0; i < n; i++) {
            ll v; cin >> v;
            vs[i].first = v, vs[i].second = i+1;
        }

        for (int i = 0; i < n; i++) {
            ll v; cin >> v;
            vs[i].first -= v;
        }

        sort(vs.begin(), vs.end());

        vector<ll> ans;
        ans.push_back(vs.back().second);

        for (int i = vs.size()-2; i >= 0; i--)
            if (vs[i].first == vs[i+1].first) ans.push_back(vs[i].second);
            else break;

        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto v: ans) cout << v << " "; cout << endl;
    }
    return 0;
}
