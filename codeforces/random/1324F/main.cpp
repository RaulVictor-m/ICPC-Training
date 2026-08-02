/*
 * LINK: https://codeforces.com/problemset/problem/1324/F
 * NAME: F. Maximum White Subtree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> dp, ans;
vector<bool> col;

void dUp(int v, int p) {
    ans[v] = max(dp[v], dp[v] + (ans[p] - max(dp[v], 0)));

    for (auto u: adj[v])
        if (u != p) dUp(u, v);
}

void dDown(int v, int p) {
    dp[v] = (col[v] ? 1 : -1);
    for (auto u: adj[v])
        if (u != p) dDown(u, v), dp[v] = max(dp[v], dp[v]+dp[u]);
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1);
    dp.resize(n+1), ans.resize(n+1), col.resize(n+1);

    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        col[i] = v;
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dDown(1, 0);
    dUp(1, 0);

    for (int v = 1; v <= n; v++)
        cout << ans[v] << ' ';

    cout << '\n';

    return 0;
}
