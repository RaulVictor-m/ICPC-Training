/*
 * LINK: https://codeforces.com/problemset/problem/2172/M
 * NAME: M. Maximum Distance To Port
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<long>> g(n+1);
    vector<long> ty(n+1), vis(n+1, LONG_MAX/3), tyW(k+1);

    for (int i = 0; i < n; i++) cin >> ty[i+1];
    for (int i = 0; i < m; i++) {
        long a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<long> qu;
    qu.push(1);
    vis[1] = 0;

    while (!qu.empty()) {
        auto i = qu.front();
        qu.pop();

        for (auto v: g[i]) {
            if (vis[v] > vis[i]+1) {
                vis[v] = vis[i]+1;
                qu.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) tyW[ty[i]] = max(vis[i], tyW[ty[i]]);

    for (int i = 1; i <= k; i++) cout << tyW[i] << " "; cout << endl;
    return 0;
}
