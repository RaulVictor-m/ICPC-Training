/*
 * LINK: https://codeforces.com/problemset/problem/1611/E1?mobile=false
 * NAME: E1. Escape The Maze (easy version)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        queue<int> qu;
        vector<vector<int>> adj(n+1);
        vector<int> type(n+1); // 1 - friend, 2 - Vlad, 0 - not visited

        for (int i = 0; i < k; i++) {
            int v; cin >> v;
            qu.push(v), type[v] = 1;;
        }
        qu.push(1), type[1] = 2;

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        while (!qu.empty()) {
            auto v = qu.front(); qu.pop();
            if (type[v] == 2 && adj[v].size() == 1 && v != 1) 
                goto yes;

            for (auto u: adj[v])
                if (!type[u]) qu.push(u), type[u] = type[v];
        }

        cout << "no\n";
        continue;

        yes:
            cout << "yes\n";
    }
    return 0;
}
