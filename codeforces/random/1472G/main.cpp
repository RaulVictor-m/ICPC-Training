/*
 * LINK: https://codeforces.com/problemset/problem/1472/G
 * NAME: G. Moving to the Capital
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<int> dist, ans;

void dp(int v) {
    ans[v] = dist[v];
    for (auto u: graph[v]) {
        if (dist[u] <= dist[v]) ans[v] = min(ans[v], dist[u]);
        else {
            if (ans[u] == -1) dp(u);
            ans[v] = min(ans[u], ans[v]);
        }
    }
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        graph.clear(), dist.clear(), ans.clear();
        graph.resize(n+1), dist.resize(n+1, -1), ans.resize(n+1, -1);

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
        }

        queue<int> qu;
        qu.push(1); dist[1] = 0;

        while (!qu.empty()) {
            int i = qu.front(); qu.pop();
            for (auto u: graph[i])
                if (dist[u] == -1) qu.push(u), dist[u] = dist[i]+1;
        }

        for (int i = 1; i <= n; i++) {
            if (ans[i] == -1) dp(i);
            cout << ans[i] << ' ';
        } 

        cout << '\n';
    }
    return 0;
}

