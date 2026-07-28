/*
 * LINK: https://codeforces.com/problemset/problem/1714/G
 * NAME: G. Path Prefixes
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// just keep a dinamic prefix sum on the path to the node
// and pop as i leave the node


vector<vector<array<ll, 3>>> adj;
vector<ll> prefa, prefb;
vector<ll> ans;

void dfs(int v) {
    if (v != 1) {
        auto len = upper_bound(prefb.begin(), prefb.end(), prefa.back()) - prefb.begin();
        ans[v] = len-1;
    }

    for (auto [u, a, b]: adj[v]) {
        prefa.push_back(a+prefa.back());
        prefb.push_back(b+prefb.back());
        dfs(u);
        prefa.pop_back();
        prefb.pop_back();
    }
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.clear(), adj.resize(n+1);
        ans.clear(), ans.resize(n+1);
        prefa.resize(1), prefb.resize(1);

        for (int i = 2; i <= n; i++) {
            ll a, b, c; cin >> a >> b >> c;
            adj[a].push_back({i, b, c});
        }

        dfs(1);

        for (int i = 2; i <= n; i++) cout << ans[i] << " ";

        cout << endl;

    }
    return 0;
}
