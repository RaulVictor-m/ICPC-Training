/*
 * LINK: https://codeforces.com/problemset/problem/1368/A
 * NAME: A. C+=
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        ll a, b, n, c = 0; cin >> a >> b >> n;

        if (b < a) swap(a, b);

        while (b <= n) a += b, swap(a, b), c++;

        cout << c << endl;
    }
    return 0;
}
