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
vector<ll> pref;
vector<ll> ans;

void dfs(int v, ll acc) {
    ans[v] = upper_bound(pref.begin(), pref.end(), acc) - pref.begin() -1;

    for (auto [u, a, b]: adj[v]) {
        pref.push_back(b+pref.back());
        dfs(u, acc+a);
        pref.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    pref.resize(1);

    while (t--) {
        int n; cin >> n;
        adj.clear(), adj.resize(n+1);
        ans.clear(), ans.resize(n+1);

        for (int i = 2; i <= n; i++) {
            ll a, b, c; cin >> a >> b >> c;
            adj[a].push_back({i, b, c});
        }

        dfs(1, 0);

        for (int i = 2; i <= n; i++) cout << ans[i] << " ";

        cout << endl;

    }
    return 0;
}
