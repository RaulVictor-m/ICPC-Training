/*
 * LINK: https://codeforces.com/problemset/problem/659/E
 * NAME: E. New Reform
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// basically just check components, and see if they have cycles,
// if there is a cycle then this component has no separate cities
// if there isnt, it has 1 separate city (OBS: think of rooted tree)

vector<ll> vis;
vector<vector<ll>> graph;

bool dfs(ll i, ll p) {
    vis[i] = 1;
    bool f = 0;
    for (auto v: graph[i]) {
        if (v == p) continue;
        if (vis[v] == 1) f = 1;
        if (vis[v]) continue;

        if (dfs(v, i)) f = 1;
    }
    return f;
}

int main(void) {
    ll n, m; cin >> n >> m;

    graph.resize(n+1), vis.resize(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll count = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && !dfs(i, 0))
            count++;

    cout << count << endl;
    return 0;
}
