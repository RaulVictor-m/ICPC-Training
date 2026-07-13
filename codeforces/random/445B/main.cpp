/*
 * LINK: https://codeforces.com/problemset/problem/445/B
 * NAME: B. DZY Loves Chemistry
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<bool> vis;

ll dfs(int i) {
    if (vis[i]) return 0;
    vis[i] = 1;

    ll sum = 1;
    for (auto v: graph[i]) sum += dfs(v);

    return sum;
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++) ans <<= max(dfs(i)-1, (ll)0);

    cout << ans << endl;
    return 0;
}
