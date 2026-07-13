/*
 * LINK: https://codeforces.com/problemset/problem/427/C
 * NAME: C. Checkposts
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
 * the best solution is basically spliting SCCS
 * and then in every SCC there will be one Post
 * this post has to be located at the lowest costing
 * position on the SCC
 * and the of solutions is just a combination of all min
 * cost vertices in every SCC
*/

void dfs(int i, vector<vector<ll>>& g, vector<ll>& tout, vector<ll>& vis) {
    vis[i] = 1;
    for (auto v: g[i]) if (!vis[v]) dfs(v, g, tout, vis);
    tout.push_back(i);
}

int main(void) {
    ll n; cin >> n;

    vector<vector<ll>> graph(n+1), rgraph(n+1);
    vector<ll> vis(n+1), price(n+1), tout, scc;
    vector<pair<ll, ll>> comps; // min-price, amount

    for (int i = 1; i <= n; i++) cin >> price[i];

    ll m; cin >> m;

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i, graph, tout, vis);

    reverse(tout.begin(), tout.end());
    vis.assign(n+1, 0);

    for (auto i: tout) {
        if (vis[i]) continue;

        dfs(i, rgraph, scc, vis);

        comps.push_back({1e10, 0});
        for (auto v: scc) {
            if (price[v] < comps.back().first) 
                comps.back().first = price[v], comps.back().second = 1;
            else if (price[v] == comps.back().first) {
                comps.back().second++;
            }
        }

        scc.clear();
    }

    const ll MOD = 1e9+7;
    ll total = 0, count = 1;
    for (auto [v, c]: comps) total += v, count *= c, count %= MOD;

    cout << total << " " << count << endl;
    return 0;
}
