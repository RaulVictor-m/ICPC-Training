/*
 * LINK: https://codeforces.com/problemset/problem/1296/F
 * NAME: F. Berland Beauty
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> par;

void dfs(int v, int p, int P) {
    for (auto [u, e]: adj[v])
        if (u != p) par[P][u] = {v, e}, dfs(u, v, P);
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1), par.resize(n+1, vector<pair<int, int>>(n+1));
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for (int i = 1; i <= n; i++) dfs(i, 0, i);

    int m; cin >> m;
    vector<array<int, 3>> q(m);
    vector<int> vs(n, 1e6);

    for (auto &[w, a, b]: q) cin >> a >> b >> w;
    sort(q.begin(), q.end());

    for (auto &[w, a, b]: q) {
        int c = b;
        while (c != a)
            vs[par[a][c].second] = w, c = par[a][c].first;
    }

    for (auto &[w, a, b]: q) {
        int c = b, m = INT_MAX;
        while (c != a)
            m = min(m, vs[par[a][c].second]), c = par[a][c].first;

        if (m > w) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 1; i < n; i++) cout << vs[i] << " "; cout << endl;

    return 0;
}
