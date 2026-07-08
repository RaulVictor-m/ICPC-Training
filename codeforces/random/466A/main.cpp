/*
 * LINK: https://codeforces.com/problemset/problem/466/A
 * NAME: A. Cheap Travel
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n, m, p, pm; cin >> n >> m >> p >> pm;

    if (p*m <= pm) {
        cout << p*n << endl;
        return 0;
    } 

    int total = 0;
    total += (pm*(n/m));
    n %= m;

    if (!n) {
        cout << total << endl;
        return 0;
    }

    total += min(pm, n*p);
    cout << total << endl;
    return 0;
}
