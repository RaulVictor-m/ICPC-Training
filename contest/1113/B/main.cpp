/*
 * LINK: https://codeforces.com/contest/2248/problem/B
 * NAME: 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> va(n), vb(m);

        for (auto &v: va) cin >> v;
        for (auto &v: vb) cin >> v;

        if (n < m*2) {
            cout << "NO\n";
            continue;
        }

        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());

        int cs = 0, ce = va.size()-vb.size();
        bool no = false;
        while (!no && cs < vb.size()) {
            if (va[cs] < vb[cs] && va[ce++] > vb[cs++]) continue;
            no = 1;
            break;
        }

        if (no) cout << "NO\n";
        else    cout << "YES\n";
    }
    return 0;
}
