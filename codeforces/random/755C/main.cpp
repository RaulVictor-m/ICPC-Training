/*
 * LINK: https://codeforces.com/problemset/problem/755/C
 * NAME: C. PolandBall and Forest
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<set<ll>> graph;
vector<bool> vis;

void dfs(ll i) {
    if (vis[i]) return;
    vis[i] = 1;
    for (auto v: graph[i]) dfs(v);
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1);
    vis.resize(n+1);

    for (int i = 1; i <= n; i++) {
        ll v; cin >> v;
        graph[i].insert(v);
        graph[v].insert(i);
    }

    ll count = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i), count++;

    cout << count << endl;
    return 0;
}
