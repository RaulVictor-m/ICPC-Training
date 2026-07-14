/*
 * LINK: https://codeforces.com/problemset/problem/500/A
 * NAME: A. New Year Transportation
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, t; cin >> n >> t;
    vector<ll> graph(n);

    for (int i = 1; i < n; i++) {
        cin >> graph[i];
        graph[i] += i;
    }

    ll v = 1;
    while (v < t) v = graph[v];

    if (v == t) cout << "YES" << endl;
    else  cout << "NO" << endl;
    return 0;
}
