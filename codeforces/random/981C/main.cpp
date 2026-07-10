/*
 * LINK: https://codeforces.com/problemset/problem/981/C
 * NAME: C. Useful Decomposition
 * STATUS: TODO (revisiting)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    checkout the tutorial
    https://codeforces.com/blog/entry/59713
*/

vector<vector<ll>> graph;
vector<ll> out;

void dfs(ll i, ll p) {
    if (graph[i].size() == 1 && p) {
        out.push_back(i);
        return;
    }

    for (auto v: graph[i]) if (v != p) dfs(v, i);
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1);

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[b].push_back(a);
        graph[a].push_back(b);
    }

    ll root = 0;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() > 2) {
            if (root) {
                cout << "No" << endl;
                return 0;
            }
            root = i;
        }
    }

    if (!root) root = 1;
    dfs(root, 0);

    cout << "Yes" << endl;
    cout << out.size() << endl;
    for (auto v: out) cout << root << " " << v << endl;

    return 0;
}
