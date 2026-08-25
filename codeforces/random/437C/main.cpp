/*
 * LINK: https://codeforces.com/problemset/problem/437/C
 * NAME: C. The Child and Toy
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<pair<ll, ll>> vs(n+1); 
    vector<ll> ct(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> vs[i].first;
        vs[i].second = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ct[a] += vs[b].first;
        ct[b] += vs[a].first;
    }

    sort(vs.rbegin(), vs.rend());
    ll sum = 0;
    for (auto [w, v]: vs) {
        sum += ct[v];
        for (auto u: adj[v])
            ct[u] -= w;
    }

    cout << sum << endl;
    return 0;
}
