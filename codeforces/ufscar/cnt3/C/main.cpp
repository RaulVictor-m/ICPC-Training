/*
 * LINK: https://codeforces.com/group/jlSbN106ET/contest/717777/problem/C
 * NAME: C. The Corridor or There and Back Again
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int trap[201];
        for (int i = 0; i < 201; i++) trap[i] = 1e6;

        for (int i = 0; i < n; i++) {
            int d, s; cin >> d >> s;
            trap[d] = min(trap[d], s);
        }

        int mn = 1e6;
        for (int i = 1; i <= 200; i++)
            mn = min(mn, (trap[i]-1)/2 + i);

        cout << mn << endl;
    }
    return 0;
}
