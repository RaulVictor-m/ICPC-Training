/*
 * LINK: https://codeforces.com/problemset/problem/276/C
 * NAME: C. Little Girl and Maximum Sum
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n, q; cin >> n >> q;

    vector<int> vs(n+2), pref(n+2);

    for (int i = 1; i <= n; i++) cin >> vs[i];

    for (int i = 1; i <= q; i++) {
        int a, b; cin >> a >> b;
        pref[a]++, pref[b+1]--;
    }

    for (int i = 1; i <= n; i++) pref[i] += pref[i-1];

    sort(pref.begin(), pref.end());
    sort(vs.begin(), vs.end());

    ll total = 0;
    for (int i = n+1; i > 1; i--) total += (ll)vs[i]*pref[i];

    cout << total << endl;
    return 0;
}
