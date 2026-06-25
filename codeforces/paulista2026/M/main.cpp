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

    if (!p || !q) {
        cout << "=" << endl;
        return 0;
    }

    string st = s+t, ts = t+s;

    for (long i = 0; i < st.size(); i++) {
        if (st[i] < ts[i]) {
            cout << '<' << endl;
            return 0;

        } else  if (st[i] > ts[i]) {
            cout << '>' << endl;
            return 0;
        }
    }

    cout << '=' << endl;
    return 0;
}
