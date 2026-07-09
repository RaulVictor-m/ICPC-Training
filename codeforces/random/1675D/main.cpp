/*
 * LINK: https://codeforces.com/problemset/problem/1675/D
 * NAME: D. Vertical Paths
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<array<ll, 2>> deaph;
vector<vector<ll>> out;
vector<bool> vis;

ll dfs(ll i) {
    deaph[i][0] = 1, deaph[i][1] = i;
    for (auto v: graph[i]) deaph[i][0] = max(deaph[i][0], dfs(v)+1);
    return deaph[i][0];
}

void ans(ll i, vector<ll> &out) {
    vis[i] = 1;
    out.push_back(i);
    if (!graph[i].empty()) ans(graph[i].back(), out);
}

int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        graph.clear(), graph.resize(n+1);
        deaph.clear(), deaph.resize(n+1);
        vis.clear(), vis.resize(n+1);
        out.clear();

        ll root = 0;

        for (int i = 1; i <= n; i++) {
            ll v; cin >> v;
            if (v == i) root = i;
            else  graph[v].push_back(i);
        }

        dfs(root);
        sort(deaph.begin(), deaph.end(), greater<array<ll, 2>>());

        for (int i = 0; i < deaph.size()-1; i++) {
            vector<ll> temp;
            if (!vis[deaph[i][1]]) {
                ans(deaph[i][1], temp);
                out.emplace_back(temp);
            }
        }

        cout << out.size() << endl;
        for (auto out: out) {
            cout << out.size() << endl;
            for (auto v: out) cout << v << " "; cout << endl;
        }
        cout << endl;

    }
    return 0;
}
