/*
 * LINK: https://codeforces.com/problemset/problem/771/A
 * NAME: A. Bear and Friendship Condition
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5;

vector<vector<int>> adj(N);
vector<bool> vis(N);

pair<ll, ll> dfs(ll v) {
    vis[v] = 1;
    pair<ll, ll> ans = {1, 0};
    for (auto u: adj[v]) {
        ans.second++;
        if (vis[u]) continue;
        auto res = dfs(u);
        ans.first += res.first;

        ans.second += res.second;
    }
    return ans;
}


int main(void) {
    ll n, m; cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for (ll i = 1; i <= n; i++) 
        if (!vis[i]) {
            auto res = dfs(i);
            if (res.first*(res.first-1) != res.second) {
                cout << "NO\n";
                return 0;
            }
        }

    cout << "YES\n";
    return 0;
}
