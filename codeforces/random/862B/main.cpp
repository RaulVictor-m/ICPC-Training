/*
 * LINK: https://codeforces.com/problemset/problem/862/B
 * NAME: B. Mahmoud and Ehab and the bipartiteness
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
array<vector<ll>, 2> lsets;
vector<bool> vis;

void dfs(ll i, bool s) {
    if (vis[i]) return;
    vis[i] = 1;

    lsets[s].push_back(i);
    for (auto v: graph[i]) dfs(v, !s);
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1);
    vis.resize(n+1);

    for (int i = 1; i < n; i++) {
        long a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    ll sum = 0;
    for (auto i: lsets[0]) {
        sum += lsets[1].size() - graph[i].size();
    }

    cout << sum << endl;
    return 0;
}
