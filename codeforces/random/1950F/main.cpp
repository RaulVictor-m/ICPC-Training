/*
 * LINK: https://codeforces.com/problemset/problem/1950/F
 * NAME: F. 0, 1, 2, Tree!
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if (c != a+1) {
            cout << -1 << endl;
            continue;
        }

        int height = 0;
        int slot = 1;
        while (a > 0 || b > 0 || c > 0) {
            int ta = min(a, slot);
            int tb = min(b, slot-ta);
            int tc = min(c, slot-ta-tb);

            slot = (ta*2) + tb;
            height++, a -= ta, b -= tb, c -= tc;
        }
        cout << height-1 << endl;
    }

    return 0;
}
