/*
 * LINK: https://codeforces.com/problemset/problem/1922/C
 * NAME: C. Closest Cities
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> vs(n+1), pref(n+2), suff(n+2);
        for (int i = 1; i <= n; i++) cin >> vs[i];

        vs.push_back(1e16), vs[0] = -1e16;

        for (int i = 1; i <= n; i++) {
            if ((vs[i] - vs[i-1]) < (vs[i+1] - vs[i]))
                suff[i-1] = 1, pref[i+1] = (vs[i+1] - vs[i]);
            else
                pref[i+1] = 1, suff[i-1] = (vs[i] - vs[i-1]);
        }

        for (int i = 2, j = n-1; i <= n; i++, j--)
            pref[i] += pref[i-1], suff[j] += suff[j+1];

        int m; cin >> m;
        while (m--) {
            int a, b; cin >> a >> b;
            if (a < b) cout << (pref[b] - pref[a]) << '\n';
            else cout << (suff[b] - suff[a]) << '\n';
        }
    }
    return 0;
}
