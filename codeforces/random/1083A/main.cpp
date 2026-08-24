/*
 * LINK: https://codeforces.com/problemset/problem/1083/A
 * NAME: A. The Fair Nut and the Best Path
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3e5+5;

vector<vector<pair<int, ll>>> adj(N);
vector<ll> wv(N), ans(N);

ll res = 0;
void dfs(int v, int p) {
    ans[v] = wv[v];

    vector<ll> lset;
    for (auto [u, w]: adj[v]) {
        if (u == p) continue;

        dfs(u, v);
        lset.push_back(max(ans[u] - w, 0LL));

        sort(lset.rbegin(), lset.rend());
        if (lset.size() > 2) lset.pop_back();
    }

    if (!lset.empty())
        ans[v] += lset[0];

    if (lset.size() >= 2)
        res = max(res, ans[v]+lset[1]);
    else
        res = max(res, ans[v]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> wv[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        ll w; cin >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    dfs(1, 0);
    cout << res << endl;

    return 0;
}
