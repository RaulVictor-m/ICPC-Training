/*
 * LINK: https://codeforces.com/problemset/problem/1572/A
 * NAME: A. Book
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1);

        for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            while (k--) {
                int v; cin >> v;
                deg[i]++, adj[v].push_back(i);
            }
        }

        // topsort
        queue<int> qu;
        vector<int> d(n+1, 1);
        int sz = 0;
        for (int i = 1; i <= n; i++)
            if (!deg[i]) qu.push(i);

        while (!qu.empty()) {
            int v = qu.front();
            qu.pop();
            sz++;

            for (auto u: adj[v])
                if (!(--deg[u])) d[u] = d[v]+(v > u), qu.push(u);
        }

        if (sz < n)
            cout << -1 << endl;
        else {
            cout << (*max_element(d.begin(), d.end())) << endl;
        }
    }
    return 0;
}
