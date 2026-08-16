#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+2;

vector<vector<int>> adj(N);
vector<int> col(N);
vector<int> tin(N), tout(N), ver(N), sz(N), hv(N);
vector<ll> ans(N), cnt(N);

int t = 1;
void pre(int v, int p) {
    tin[v] = t, ver[t++] = v;
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;
        pre(u, v); 
        sz[v] += sz[u];

        if (sz[hv[v]] < sz[u]) hv[v] = u;
    }

    tout[v] = t-1;
}

ll sum = 0, mxc = 0;
void add(int v) {
    if ((++cnt[col[v]]) == mxc) sum += col[v];
    else if (cnt[col[v]] > mxc) sum = col[v], mxc = cnt[col[v]];
}

void dfs(int v, int p, bool keep) {
    ll osum = sum, omxc = mxc;
    for (auto u: adj[v])
        if (u != p && u != hv[v])
            dfs(u, v, false);

    if (hv[v]) dfs(hv[v], v, true);

    for (auto u: adj[v])
        if (u != p && u != hv[v])
            for (int t = tin[u]; t <= tout[u]; t++)
                add(ver[t]);
    add(v);

    ans[v] = sum;
    if (!keep) {
        sum = osum, mxc = omxc;
        for (int t = tin[v]; t <= tout[v]; t++)
            cnt[col[ver[t]]]--;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> col[i];

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pre(1, 0);
    dfs(1, 0, 1);

    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
    return 0;
}
