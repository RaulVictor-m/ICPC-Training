/*
 * LINK: https://codeforces.com/problemset/problem/103/B
 * NAME: B. Cthulhu
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<ll> vis;
set<ll> roots;

bool dfs(ll i, ll p) {
    vis[i] = 1;
    for (auto v: graph[i]) {
        if (i == p) continue;
        if (roots.count(v)) continue;
        if (vis[v]) return 1;

        dfs(v, i);
    }
    return 0;
}

int findCycle(ll i, ll count) {
    vis[i] = count;
    for (auto v: graph[i]) {
        if (!vis[v]) {
            ll res = findCycle(v, count+1);
            if (res == -1) return -1;

            if (res > 0) {
                roots.insert(i);
                return res;
            }

            if (res == i) return -1;

        } else if (vis[v] > 0 && vis[v] < (vis[i]-1)) {
            roots.insert(i);
            return v;
        }
    }
    vis[i] = -1;
    return 0;
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1), vis.resize(n+1);

    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    findCycle(1, 1);

    vis.assign(n+1, 0);
    if (roots.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }

    for (auto i: roots) {
        vis[i] = 1;
        if (dfs(i, 0)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "FHTAGN!" << endl;
    return 0;
}
