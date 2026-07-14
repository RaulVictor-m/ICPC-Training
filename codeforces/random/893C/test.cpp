#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<ll> money;
vector<bool> vis;

ll dfs(ll i) {
    vis[i] = 1;
    ll lmin = money[i];
    for (auto v: graph[i]) {
        if (vis[v]) continue;
        lmin = min(lmin, dfs(v));
    }
    return lmin;
}

int main(void) {
    ll n, m; cin >> n >> m;
    money.resize(n+1);
    graph.resize(n+1);
    vis.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> money[i];

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll total = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            total += dfs(i);
        }
    }

    cout << total << endl;
    return 0;
}
