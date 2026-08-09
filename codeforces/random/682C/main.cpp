/*
 * LINK: https://codeforces.com/problemset/problem/682/C
 * NAME: C. Alyona and the Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> adj;
vector<ll> dt, vs, sz;

void pre(int v, int p) {
    sz[v] = 1;
    for (auto [u, w]: adj[v])
        if (u != p)
            dt[u] = max(dt[v]+w, w), pre(u, v), sz[v]+=sz[u];
}

int solve(int v, int p) {
    int tot = 0;
    for (auto [u, w]: adj[v]) {
        if (u != p) {
            if (dt[u] > vs[u]) tot += sz[u];
            else               tot += solve(u, v);
        }
    }

    return tot;
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1), dt.resize(n+1), vs.resize(n+1), sz.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> vs[i];

    for (int i = 2; i <= n; i++) {
        int v, w; cin >> v >> w;
        adj[v].emplace_back(i, w);
        adj[i].emplace_back(v, w);
    }
    pre(1, 0);
    cout << solve(1, 0) << endl;

    return 0;
}
