/*
 * LINK: https://codeforces.com/problemset/problem/920/E
 * NAME: E. Connected Components
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<set<ll>> graph;
set<ll> unvis;
vector<ll> vis;

void dfs(ll i) {
    vis[i] = 1;
    unvis.erase(i);

    auto it = unvis.begin();
    while (it != unvis.end()) {
        ll v = *it;
        if (graph[i].count(v)) {
            it++;
            continue;
        }

        dfs(v);

        it = unvis.upper_bound(v);
    }
}

int main(void) {
    ll n, m; cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        unvis.insert(i);
    }

    vector<ll> ans;
    for (int i = 1; i <= n; i++) {
        if (unvis.count(i)) {
            ll s = unvis.size();
            dfs(i);
            ans.push_back(s-unvis.size());
        }
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto v: ans) cout << v << " "; cout << endl;
    return 0;
}
