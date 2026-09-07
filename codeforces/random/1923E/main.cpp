/*
 * LINK: https://codeforces.com/problemset/problem/1923/E
 * NAME: E. Count Paths
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;

vector<vector<int>> adj;
vector<int> col, sz, hv;

int t = 1;
void pre(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;
        pre(u, v), sz[v] += sz[u];

        if (sz[u] > sz[hv[v]]) hv[v] = u;
    }
}

ll ans = 0;
void dfs(int v, int p, bool kp) {
    static vector<int> sack(2e5+5, 0);
    static vector<bool> used(2e5+5, 0);

    for (auto u: adj[v])
        if (u != p && u != hv[v]) dfs(u, v, false);

    if (hv[v]) dfs(hv[v], v, true);
    ans += sack[col[v]], sack[col[v]] = 0;

    for (auto u: adj[v]) {
        if (u == p || u == hv[v]) continue;

        vector<int> st;
        [&st](this auto&& self, int v, int p) -> void {
            bool f = false;
            if (!used[col[v]]) 
                ans += sack[col[v]], used[col[v]] = 1, st.push_back(col[v]), f = true;

            for (auto u: adj[v]) 
                if (u != p) self(u, v);

            if (f) used[col[v]] = 0;
        }(u, v);

        while (!st.empty()) {
            sack[st.back()]++;
            st.pop_back();
        }

        ans += sack[col[v]], sack[col[v]] = 0;
    }

    sack[col[v]] = 1;

    if (!kp)
        [](this auto&& self, int v, int p) -> void {
            sack[col[v]] = 0;
            for (auto u: adj[v]) if (u != p) self(u, v);
        }(v, p);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;

        [&](auto&... v) { (v.clear(), ...), (v.resize(n+1), ...), t = 1, ans = 0; }
        (col, sz, hv, adj);

        for (int i = 1; i <= n; i++) cin >> col[i];
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        pre(1, 0);
        dfs(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
