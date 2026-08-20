/*
 * LINK: https://codeforces.com/problemset/problem/741/D
 * NAME: D. Arpa’s letter-marked tree and Mehrdad’s Dokhtar-kosh paths
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+5;

vector<vector<int>> adj(N);
vector<int> mask(N), sz(N), hv(N), dep(N), tin(N), tout(N), ver(N);
vector<int> m_sack((1<<22)+1, -1e9), ans(N);

int t = 1;
void pre(int v) {
    tin[v] = t, ver[t++] = v;
    sz[v] = 1;
    for (auto u: adj[v]) {
        dep[u] = dep[v]+1;
        mask[u]^=mask[v];

        pre(u);
        sz[v] += sz[u];

        if (sz[hv[v]] < sz[u]) hv[v] = u;
    }
    tout[v] = t-1;
}

int get_max(int v, int dep_sub) {
    int mx = 0;
    mx = max(mx, m_sack[mask[v]] + dep[v] - dep_sub*2);
    for (int k = 0; k < 22; k++)
        mx = max(mx, m_sack[mask[v]^(1<<k)] + dep[v] - dep_sub*2);

    return mx;
}

vector<pair<int*, int>> hist;
void add(int v) {
    if (dep[v] > m_sack[mask[v]]) {
        hist.emplace_back(&m_sack[mask[v]], m_sack[mask[v]]);
        m_sack[mask[v]] = dep[v];
    }
}

void dfs(int v, bool keep) {
    int snap = hist.size();
    for (auto u: adj[v]) 
        if (u != hv[v]) dfs(u, false), ans[v] = max(ans[v], ans[u]);

    if (hv[v]) dfs(hv[v], true), ans[v] = max(ans[v], ans[hv[v]]);

    for (auto u: adj[v]) {
        if (u != hv[v]) {
            for (int t = tin[u]; t <= tout[u]; t++)
                ans[v] = max(ans[v], get_max(ver[t], dep[v]));

            for (int t = tin[u]; t <= tout[u]; t++)
                add(ver[t]);
        }
    }

    ans[v] = max(ans[v], get_max(v, dep[v]));
    add(v);

    if (!keep) {
        while(hist.size() > snap) {
            *hist.back().first = hist.back().second;
            hist.pop_back();
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    for (int i = 2; i <= n; i++) {
        int a;
        char s;
        cin >> a >> s;
        mask[i] = 1<<(s-'a');
        adj[a].push_back(i);
    }

    pre(1);
    dfs(1, 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;

    return 0;
}
