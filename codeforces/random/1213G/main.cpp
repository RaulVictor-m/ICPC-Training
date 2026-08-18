/*
 * LINK: https://codeforces.com/problemset/problem/1213/G
 * NAME: G. Path Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+5;

namespace uf {
    ll par[N], sz[N], cnt = 0;
    void build(int n) {
        for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    }

    int find(int v) {
        return par[v] = (par[v] == v? v : find(par[v]));
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (sz[a] < sz[b]) swap(a, b);

        cnt += sz[a]*sz[b];
        par[b] = a, sz[a] += sz[b];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    uf::build(n);
    vector<array<int, 3>> ed(n-1);
    for (auto &[w, a, b]: ed) cin >> a >> b >> w;

    sort(ed.begin(), ed.end());

    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(q.begin(), q.end());

    vector<ll> ans(m);
    for (auto [v, id]: q) {
        static int i = 0;
        while (i < ed.size() && ed[i][0] <= v) 
            uf::join(ed[i][1], ed[i][2]), i++;

        ans[id] = uf::cnt;
    }

    for (auto u: ans) cout << u << ' '; cout << '\n';
    return 0;
}
