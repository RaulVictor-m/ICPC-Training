/*
 * LINK: https://codeforces.com/problemset/problem/208/E
 * NAME: E. Blood Cousins
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Binary lifting on the tree to find the parent
// Then store every node that is on the ith height
// for each query use the lift to get the parent
// and use binary search with t_in and t_out of the dfs
// on all the nodes in the ith height

vector<vector<ll>> graph, h_nodes;
vector<ll> tin, tout, ht;
ll t = 1;
vector<array<ll, 20>> parent;

void dfs(ll i, ll h) {
    tin[i] = t++, ht[i] = h;
    h_nodes[h].push_back(i);

    for (int k = 1; k < 20; k++) parent[i][k] = parent[parent[i][k-1]][k-1];

    for (auto v: graph[i]) dfs(v, h+1);

    tout[i] = t++;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    graph.resize(n+1), tin.resize(n+1), tout.resize(n+1);
    h_nodes.resize(n+1), parent.resize(n+1), ht.resize(n+1);

    vector<ll> roots;
    for (int i = 1; i <= n; i++) {
        ll v; cin >> v;
        graph[v].push_back(i);
        parent[i][0] = v;
        if (!v) roots.push_back(i);
    }

    for (auto i: roots) dfs(i, 1);

    ll q; cin >> q;
    while (q--) {
        ll v, p; cin >> v >> p;
        ll h = ht[v];

        for (int k = 0; k < 20; k++) 
            if ((p >> k)&1) v = parent[v][k];

        if (v == 0) {
            cout << 0 << endl;
            continue;
        }

        auto seg_s = upper_bound(h_nodes[h].begin(), h_nodes[h].end(), v, 
                     [](ll a, ll b) { return tin[a] < tin[b]; });

        auto seg_e = upper_bound(h_nodes[h].begin(), h_nodes[h].end(), v, 
                     [](ll a, ll b) { return tout[a] < tout[b]; });

        cout << (seg_e - seg_s)-1 << endl;
    }

    return 0;
}
