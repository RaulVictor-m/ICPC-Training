/*
 * LINK: https://codeforces.com/problemset/problem/1829/F
 * NAME: F. Forever Winter
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> sz;
vector<vector<ll>> graph;

void csize(ll i, ll p = 0) {
    sz[i] = 1;
    for (auto v: graph[i]) 
        if (v != p) csize(v, i), sz[i]+=sz[v];
}

ll centroid(ll i, ll treesz, ll p = 0) {
    for (auto v: graph[i])
        if (v != p && sz[v]*2 > treesz)
            return centroid(v, treesz, i);
    return i;
}

int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        graph.clear(), graph.resize(n+1); 
        sz.clear(), sz.resize(n+1); 

        for (int i = 0; i < m; i++) {
            ll a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        csize(1, 0);
        ll cent = centroid(1, sz[1]);

        cout << graph[cent].size() << " "<< graph[graph[cent][1]].size()-1 << "\n";
    }
    return 0;
}
