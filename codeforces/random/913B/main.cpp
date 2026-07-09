/*
 * LINK: https://codeforces.com/problemset/problem/913/B
 * NAME: B. Christmas Spruce
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<ll> children;

ll dfs(ll i) {
    if (graph[i].empty()) return 1;

    for (auto v: graph[i]) children[i] += dfs(v);

    return 0;
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1);
    children.resize(n+1);

    for (int i = 2; i <= n; i++) {
        long v; cin >> v;
        graph[v].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!graph[i].empty() && children[i] < 3) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
