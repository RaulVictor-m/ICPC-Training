/*
 * LINK: https://cses.fi/problemset/task/2183
 * NAME: Missing Coin Sum
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    long n, j = 1; cin >> n;
    vector<long> v(n);

    for (auto &v: v) cin >> v;
    sort(v.begin(), v.end());

    for (long i = 0; i < n; i++)
        if (v[i] <= j) j+=v[i];  
        else break;

    cout << j << endl;
    return 0;
}
