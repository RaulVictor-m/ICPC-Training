/*
 * LINK: https://codeforces.com/problemset/problem/743/D
 * NAME: D. Chloe and pleasant prizes
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+5;
const ll INF = (1LL<<60);

vector<vector<int>> adj(N);
vector<ll> sub(N), mx(N, -INF), vs(N);

void pre(int v, int p) {
    sub[v] = vs[v];

    for (auto u: adj[v]) {
        if (u == p) continue;
        pre(u, v);
        sub[v] += sub[u];
        mx[v] = max(mx[v], mx[u]);
    }

    mx[v] = max(mx[v], sub[v]);
}

ll ans = -INF;
void solve(int v, int p, ll out) {
    if (out > -INF)
        ans = max(ans, sub[v] + out);

    vector<pair<ll, int>> lset;
    for (auto u: adj[v]) {
        if (u == p) continue;
        lset.emplace_back(mx[u], u);
    }
    sort(lset.rbegin(), lset.rend());

    if (lset.size() >= 2) lset.resize(2);
    else                  lset.emplace_back(-INF, -1);

    for (auto u: adj[v]) {
        if (u == p) continue;
        if (u == lset[0].second) solve(u, v, max(out, lset[1].first));
        else                     solve(u, v, max(out, lset[0].first));
    }
}

int main(void) {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> vs[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pre(1, 0);
    solve(1, 0, -INF);
    if (ans == -INF) cout << "Impossible" << endl;
    else             cout << ans << endl;


    return 0;
}
