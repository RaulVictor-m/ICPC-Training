/*
 * LINK: https://codeforces.com/problemset/problem/1927/F
 * NAME: F. Microcycle
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace uf {
    vector<int> par, sz;
    void build(int n) {
        par.clear(), sz.clear();
        par.resize(n+1), sz.resize(n+1, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        return par[v] == v ? v : find(par[v]);
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);

        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);

        par[b] = a, sz[a] += sz[b];
        return true;
    }
}

vector<vector<int>> adj;
vector<int> ans;
void path(int a, int p, int b) {
    if (a == b) {
        ans.push_back(b);
        return;
    }

    int lsize = ans.size();
    for (auto u: adj[a]) {
        if (u == p) continue;
        path(u, a, b);
        if (ans.size() != lsize) {
            ans.push_back(a);
            return;
        }
    }
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        adj.clear(), adj.resize(n+1);
        ans.clear();
        uf::build(n);

        vector<array<ll, 3>> edges(m);
        for (auto &[w, a, b]: edges) cin >> a >> b >> w;
        sort(edges.begin(), edges.end(), greater<array<ll, 3>>());

        int l = 0;
        for (int i = 0; i < m; i++) {
            auto &[w, a, b] = edges[i];

            if (!uf::join(a, b)) l = i;
            else  adj[a].push_back(b), adj[b].push_back(a);
        }

        path(edges[l][1], 0, edges[l][2]);
        cout << edges[l][0] << " " << ans.size() << endl;
        for (auto u: ans) cout << u << " "; cout << endl;
    }
    return 0;
}
