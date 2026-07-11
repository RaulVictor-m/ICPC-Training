/*
 * LINK: https://codeforces.com/problemset/problem/978/C
 * NAME: C. letters
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m; cin >> n >> m;

    vector<ll> preffix(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> preffix[i];
        preffix[i] += preffix[i-1];
    }

    while (m--) {
        ll v; cin >> v;
        ll dorm = lower_bound(preffix.begin(), preffix.end(), v) - preffix.begin();
        cout << dorm << " " << v - preffix[dorm - 1] << endl;
    }
    return 0;
}
