/*
 * LINK: https://codeforces.com/problemset/problem/1857/C
 * NAME: C. Assembly via Minimums
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll t; cin >> t;
    vector<ll> vs;
    vector<ll> ans;
    while (t--) {
        ll n; cin >> n;
        vs.resize((n*(n-1))/2);

        for (auto &v: vs) cin >> v;
        sort(vs.begin(), vs.end());

        ans.clear();
        ans.push_back(vs.front());

        for (ll i = 1; i < vs.size(); i++)
            if (vs[i] != vs[i-1]) ans.push_back(vs[i]);

        for (int i = 0; i < n; i++)
            if (i < ans.size()) cout << ans[i] << " ";
            else                cout << ans.back() << " ";
        cout << endl;
    }

    return 0;
}
