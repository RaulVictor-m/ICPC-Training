/*
 * LINK: https://codeforces.com/problemset/problem/1352/C
 * NAME: C. k-th Not Divisible by n
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;

        ll l = k/n;

        while (1) {
            if ((k+l)/n == l) break;
            else l = (k+l)/n;
        }
        cout << k+l << endl;
    }
    return 0;
}
