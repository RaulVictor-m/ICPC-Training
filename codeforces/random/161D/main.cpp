/*
 * LINK: https://codeforces.com/problemset/problem/161/D
 * NAME: D. Distance in Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<array<ll, 501>> dist;

ll dfs(ll i, ll p, const ll k) {
    ll total = dist[i][k];
    array<ll, 500> distSub = {};

    for (auto v: graph[i]) {
        if (v == p) continue;
        ll temp = dfs(v, i, k);
        total += temp;

        // between sibblins
        for (int x = 0; x < k-1; x++) {
            distSub[k-2-x] += dist[v][k-2-x];
            total += dist[v][x] * (dist[i][k-1-x] - distSub[k-2-x]);
        }
    }
    return total;
}

void dfsCalcDist(ll i, ll p, const ll k) {
    dist[i][0] = 1;
    for (auto v: graph[i]) {
        if (v == p) continue;
        dfsCalcDist(v, i, k);

        for (int j = 1; j <= k; j++)
            dist[i][j] += dist[v][j-1];
    }
}

int main(void) {
    ll n, k; cin >> n >> k;
    graph.resize(n+1);
    dist.resize(n+1);

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfsCalcDist(1, 0, k);
    cout << dfs(1, 0, k) << endl;

    return 0;
}
