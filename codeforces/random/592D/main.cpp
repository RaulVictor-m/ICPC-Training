/*
 * LINK: https://codeforces.com/problemset/problem/592/D
 * NAME: D. Super M
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<bool> dead, mark;
vector<int> d, d1, d2;

bool kill(int v, int p) {
    bool m = mark[v];
    for (auto u: adj[v]) {
        if (u == p) continue;

        if (!kill(u, v)) dead[u] = 1;
        m = m || !dead[u];
    }

    return m;
}

void dist(int v, int p, vector<int>& dt) {
    for (auto u: adj[v])
        if (u != p && !dead[u]) dt[u] = dt[v]+1, dist(u, v, dt);
}

int main(void) {
    int n, m; cin >> n >> m;

    adj.resize(n+1),  d1.resize(n+1),  d2.resize(n+1),  d.resize(n+1);
    dead.resize(n+1),  mark.resize(n+1);
    dead[0] = 1;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int l = 0;
    for (int i = 0; i < m; i++) {
        int v; cin >> v;
        mark[l = v] = 1;
    }

    if (m == 1) {
        cout << l << endl << 0 << endl;
        return 0;
    }
    kill(l, 0);
    dist(l, 0, d);

    int da = max_element(d.begin(), d.end()) -  d.begin();
    dist(da, 0, d1);

    int db = max_element(d1.begin(), d1.end()) -  d1.begin();

    int sz = count(dead.begin(), dead.end(), 0);

    cout << min(da, db) << '\n';
    cout << (sz-1)*2 - d1[db] << '\n';

    return 0;
}
