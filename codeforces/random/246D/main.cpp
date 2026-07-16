/*
 * LINK: https://codeforces.com/problemset/problem/246/D
 * NAME: D. Colorful Graph
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m; cin >> n >> m;
    map<ll, set<ll>> graph;
    vector<ll> col(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
        graph[col[i]] = {};
    }

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        if (col[a] == col[b]) continue;
        graph[col[a]].insert(col[b]);
        graph[col[b]].insert(col[a]);
    }

    ll size = -1, index = 0;
    for (auto &[i, s]: graph) {
        if ((ll)s.size() > size) {
            size = s.size(), index = i;
        }
    }

    cout << index << endl;
    return 0;
}
