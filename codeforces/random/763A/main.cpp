/*
 * LINK: https://codeforces.com/problemset/problem/763/A
 * NAME: A. Timofey and a tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<ll> cols;

bool dfs(ll i, ll p) {
    for (auto v: graph[i]) {
        if (v == p) continue;
        if ((cols[i] != cols[v]) || !dfs(v, i)) return false;
    }
    return true;
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1);
    cols.resize(n+1);

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set<ll> acols;
    for (int i = 1; i <= n; i++) cin >> cols[i];
    for (int i = 1; i <= n; i++) acols.insert(cols[i]);


    queue<ll> roots;
    for (int i = 1; i <= n && roots.empty(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (cols[graph[i][j]] != cols[i]) {
                roots.push(i);
                roots.push(graph[i][j]);
                break;
            }
        }
    }

    if (roots.empty()) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }

    ll root = 0;
    while (!roots.empty() && !root) {
        root = roots.front();
        roots.pop();
        if (graph[root].size() < acols.size()-1) {
            root = 0;
            continue;
        }
        for (auto v: graph[root]) {
            if (!dfs(v, root)) {
                root = 0;
                break;
            }
        }
    }

    if (!root) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << root << endl;
    return 0;
}
