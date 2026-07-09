/*
 * LINK: https://codeforces.com/problemset/problem/1843/D
 * NAME: D. Apple Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<ll> leafs;

ll dfs(int i, int p) {
    ll c_leafs = 0;

    for (auto j: graph[i]) 
        if (j != p) c_leafs += dfs(j, i);

    return leafs[i] = max((ll)1, c_leafs);
}

int main(void) {
    ll t; cin >> t;

    while (t--) {
        ll n; cin >> n;

        graph.clear(), graph.resize(n+1);
        leafs.clear(), leafs.resize(n+1);

        for (int i = 1; i < n; i++) {
            ll a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs(1, 0);
        ll q; cin >> q;

        while (q--) {
            ll a, b; cin >> a >> b;
            cout << leafs[a] * leafs[b] << endl;
        }

    }
    return 0;
}
