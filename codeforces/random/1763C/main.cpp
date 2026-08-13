/*
 * LINK: https://codeforces.com/problemset/problem/1763/C
 * NAME: C. Another Array Problem
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<ll> vs(n);
        for (auto &u: vs) cin >> u;

        if (n >= 4) {
            cout << (n*(*max_element(vs.begin(), vs.end()))) << endl;
        } else {
            if (n == 2) {
                cout << max(vs[0] + vs[1], abs(vs[0]-vs[1])*2) << endl;

            } else {
                ll total = max({vs[0]*3, vs[2]*3, abs(vs[0]-vs[1])*3, abs(vs[1]-vs[2])*3,
                                vs[0]+vs[1]+vs[2]});

                cout << total << endl;

            }
        }
    }
    return 0;
}
