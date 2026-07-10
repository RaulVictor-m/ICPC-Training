/*
 * LINK: https://codeforces.com/problemset/problem/1559/D1
 * NAME: D1. Mocha and Diana (Easy Version)
 * STATUS: BROKEN
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*

*/

vector<vector<ll>> graph1;
vector<vector<ll>> graph2;
vector<ll> vis1;
vector<ll> vis2;

ll dfs(ll i, vector<ll> &vis, vector<vector<ll>> &graph) {
    if (vis[i]) return 0;
    vis[i] = 1;

    for (auto v: graph[i]) dfs(v, vis, graph);

    return 1;
}

int main(void) {
    ll n, m1, m2; cin >> n >> m1 >> m2;
    graph1.resize(n+1);
    vis1.resize(n+1);
    graph2.resize(n+1);
    vis2.resize(n+1);

    for (int i = 0; i < m1; i++) {
        ll a, b; cin >> a >> b;
        graph1[a].push_back(b);
        graph1[b].push_back(a);
    }

    for (int i = 0; i < m2; i++) {
        ll a, b; cin >> a >> b;
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }

    dfs(1, vis1, graph1);
    dfs(1, vis2, graph2);

    vector<ll> ans;
    for (int i = 1; i <= n; i++) {
        if (!vis1[i] && !vis2[i]) {
            dfs(i, vis1, graph1);
            dfs(i, vis2, graph2);
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto v: ans) cout << 1 << " " << v << endl;
    return 0;
}
