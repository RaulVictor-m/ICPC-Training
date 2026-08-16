/*
 * LINK: https://codeforces.com/problemset/problem/375/D
 * NAME: D. Tree and Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+2;

vector<vector<int>> adj(N);
vector<int> col(N);
vector<int> tin(N), tout(N), ver(N), sz(N), hv(N);
vector<int> ans(N), cnt(N), frq(N);
vector<vector<pair<int, int>>> q(N);

int t = 1;
void pre(int v, int p) {
    tin[v] = t, ver[t++] = v;
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;

        pre(u, v), sz[v] += sz[u];
        if (sz[hv[v]] < sz[u]) hv[v] = u;
    }

    tout[v] = t-1;
}

void dfs(int v, int p, bool keep) {
    for (auto u: adj[v])
        if (u != p && u != hv[v]) 
            dfs(u, v, false);

    if (hv[v]) dfs(hv[v], v, true);

    for (auto u: adj[v])
        if (u != p && u != hv[v]) 
            for (int t = tin[u]; t <= tout[u]; t++)
                frq[++cnt[col[ver[t]]]]++;

    frq[++cnt[col[v]]]++;

    for (auto [k, i]: q[v])
        ans[i] = frq[k];

    for (int t = tin[v]; !keep && t <= tout[v]; t++)
        frq[cnt[col[ver[t]]]--]--;
}


int main(void) {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= m; i++) {
        int v, k; cin >> v >> k;
        q[v].emplace_back(k, i);
    }

    pre(1, 0);
    dfs(1, 0, 1);

    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';

    return 0;
}
