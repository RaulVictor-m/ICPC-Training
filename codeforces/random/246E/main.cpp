/*
 * LINK: https://codeforces.com/contest/246/problem/E
 * NAME: E. Blood Cousins Return
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+2;

vector<vector<int>> adj(N);
vector<int> tin(N), tout(N), ver(N), sz(N), hv(N), dep(N);
vector<map<int, int>> sacks(N);
vector<int> names(N);
vector<int> ans(N), cnt(N);
vector<vector<pair<int, int>>> q(N);

int t = 1;
void pre(int v) {
    tin[v] = t, ver[t++] = v;
    sz[v] = 1;
    for (auto u: adj[v]) {
        dep[u] = dep[v]+1;
        pre(u);
        sz[v] += sz[u];

        if (sz[hv[v]] < sz[u]) hv[v] = u;
    }
    tout[v] = t-1;
}

void add(int v) {
    if ((sacks[dep[v]][names[v]]++) == 0) 
        cnt[dep[v]]++; 
}

void rm(int v) {
    if ((--sacks[dep[v]][names[v]]) == 0) 
        cnt[dep[v]]--; 
}

void dfs(int v, bool keep) {
    for (auto u: adj[v]) 
        if (u != hv[v]) dfs(u, false);

    if (hv[v]) dfs(hv[v], true);

    for (auto u: adj[v]) 
        if (u != hv[v])
            for (int t = tin[u]; t <= tout[u]; t++)
                add(ver[t]);

    add(v);

    for (auto [k, i]: q[v])
        if (dep[v]+k < N)
            ans[i] = cnt[dep[v]+k];

    if (!keep)
        for (int t = tin[v]; t <= tout[v]; t++)
            rm(ver[t]);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    map<string, int> table;
    int cnt_names = 1;
    for (int i = 1; i <= n; i++) {
        string line; cin >> line;
        if (!table.count(line)) 
            table[line] = cnt_names, names[i] = cnt_names++;
        else 
            names[i] = table[line];

        int v; cin >> v;
        adj[v].push_back(i);
    }

    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        int v, k; cin >> v >> k;
        q[v].emplace_back(k, i);
    }

    for (auto u: adj[0]) pre(u);
    for (auto u: adj[0]) dfs(u, 0);

    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    return 0;
}
