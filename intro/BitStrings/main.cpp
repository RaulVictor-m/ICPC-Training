/*
 * LINK: https://cses.fi/problemset/task/1617
 * NAME: Bit Strings
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MOD = 1e9 + 7;

int main(void) {
    ll n, t = 2; cin >> n;

    for (int i = 1; i < n; i++) t <<= 1, t %= MOD;

    cout << t << endl;
    return 0;
}
