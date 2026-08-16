/*
 * LINK: https://codeforces.com/contest/570/problem/D
 * NAME: D. Tree Requests
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+3;

vector<int> adj[N];
int tin[N], tout[N], ver[N], sz[N], hv[N], dep[N];
int let[N];
int hts[N];
vector<bool> ans(N);

vector<pair<int, int>> q[N];

int t = 1;
void pre(int v) {
    tin[v] = t, ver[t++] = v;
    sz[v] = 1;

    for (auto u: adj[v]) {
        dep[u] = dep[v]+1;
        pre(u);
        sz[v] += sz[u];

        if (sz[u] > sz[hv[v]]) hv[v] = u;
    }
    tout[v] = t-1;
}

void dfs(int v, bool keep) {
    for (auto u: adj[v])
        if (u != hv[v]) dfs(u, false);

    if (hv[v]) dfs(hv[v], true);

    for (auto u: adj[v])
        if (u != hv[v])
            for (int t = tin[u]; t <= tout[u]; t++)
                hts[dep[ver[t]]] ^= let[ver[t]];

    hts[dep[v]] ^= let[v];

    for (auto [h, i]: q[v])
        ans[i] = __builtin_popcount((unsigned)hts[h-1]) <= 1;

    if (!keep) {
        for (int t = tin[v]; t <= tout[v]; t++)
            hts[dep[ver[t]]] ^= let[ver[t]];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        int v; cin >> v;
        adj[v].push_back(i);
    }

    string line; cin >> line;
    for (int i = 0; i < line.size(); i++) 
        let[i+1] = (1<<(line[i]-'a'));

    for (int i = 1; i <= m; i++) {
        int v, h; cin >> v >> h;
        q[v].emplace_back(h, i);
    }

    pre(1);
    dfs(1, 1);

    for (int i = 1; i <= m; i++)
        if (ans[i]) cout << "Yes\n";
        else        cout << "No\n";

    return 0;
}
