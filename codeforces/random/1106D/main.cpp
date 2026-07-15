/*
 * LINK: https://codeforces.com/problemset/problem/1106/D
 * NAME: D. Lunar New Year and a Wander
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> graph(n+1);

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> vis(n+1);
    priority_queue<ll> qu;
    qu.push(-1);
    vis[1] = 1;

    vector<ll> ans;
    while (!qu.empty()) {
        ll i = -qu.top();
        qu.pop();

        ans.push_back(i);

        for (auto v: graph[i]) {
            if (!vis[v]) {
                qu.push(-v);
                vis[v] = 1;
            }
        }
    }

    for (auto v: ans) cout << v << " "; cout << endl;

    return 0;
}
