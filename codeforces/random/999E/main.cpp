/*
 * LINK: https://codeforces.com/problemset/problem/999/E
 * NAME: E. Reachability from the Capital
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(ll i, vector<vector<ll>>& graph, vector<ll>& tout, vector<ll>& vis) {
    vis[i] = 1;
    for (auto v: graph[i]) 
        if (!vis[v]) dfs(v, graph, tout, vis);
    tout.push_back(i);
}

int main(void) {
    ll n, m, s; cin >> n >> m >> s;
    vector<vector<ll>> graph(n+1), rgraph(n+1);
    vector<ll> tout, vis(n+1), scc, root(n+1), inDeg;

    for (int i = 1; i <= m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) 
        if (!vis[i]) dfs(i, graph, tout, vis);

    reverse(tout.begin(), tout.end());
    vis.assign(n+1, 0);

    ll sccs = 0;
    for (auto i: tout) {
        if (vis[i]) continue;

        dfs(i, rgraph, scc, vis);

        for (auto v: scc) root[v] = sccs;
        sccs++;

        scc.clear();
    }

    inDeg.resize(sccs);
    for (int i = 1; i <= n; i++)
        for (auto v: graph[i])
            if (root[i] != root[v])
                inDeg[root[v]]++;

    ll count = 0;
    inDeg[root[s]]++; // should be not counted if zero
    for (auto v: inDeg) if (!v) count++;

    cout << count << endl;
    return 0;
}
