/*
 * LINK: https://codeforces.com/problemset/problem/580/C
 * NAME: C. Kefa and Park
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> cats;
vector<vector<ll>> graph;

ll dfs(ll i, ll p, ll m, const ll M) {
    if (!m && cats[i]) return 0;
    if (graph[i].size() == 1 && graph[i].front() == p) return 1;

    ll total = 0;
    for (auto v: graph[i]) if (v != p) total += dfs(v, i, cats[i] ? m-1: M, M);

    return total;
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1);
    cats.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> cats[i];

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << dfs(1, 0, m, m) << endl;
    return 0;
}
