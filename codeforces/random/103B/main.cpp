/*
 * LINK: https://codeforces.com/problemset/problem/103/B
 * NAME: B. Cthulhu
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<ll> vis;

void dfs(ll i) {
    vis[i] = 1;
    for (auto v: graph[i]) if (!vis[v]) dfs(v);
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1), vis.resize(n+1);

    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (m != n) {
        cout << "NO" << endl;
        return 0;
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "FHTAGN!" << endl;
    return 0;
}
