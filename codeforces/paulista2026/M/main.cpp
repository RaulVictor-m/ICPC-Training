/*
 * LINK: https://codeforces.com/gym/106598/problem/M
 * NAME: M
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
*/

int main(void) {
    string s, t; cin >> s >> t;
    long p, q; cin >> p >> q;

    string st = s+t, ts = t+s;

    if (!p || !q || st == ts) cout << '=' << endl;
    else if (st < ts)         cout << '<' << endl;
    else                      cout << '>' << endl;

    return 0;
}
