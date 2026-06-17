/*
 * LINK: https://cses.fi/problemset/task/2216
 * NAME: Collecting Numbers
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    long n, res = 1; cin >> n;
    vector<long> v(n+1);

    for (int i = 0, j; i < n ; i++) {
        cin >> j; 
        v[j] = i;
    }

    for (int i = 1; i < v.size(); i++)
        if (v[i] < v[i-1]) res++;

    cout << res << endl;
    return 0;
}
