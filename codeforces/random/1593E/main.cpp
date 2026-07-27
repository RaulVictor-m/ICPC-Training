/*
 * LINK: https://codeforces.com/problemset/problem/1593/E
 * NAME: E. Gardener and Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1);

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++, deg[b]++;
        }

        queue<int> qu;
        vector<int> dist(n+1, -1);
        for (int i = 1; i <= n; i++)
            if (deg[i] <= 1) 
                qu.push(i), dist[i] = 1;

        while (!qu.empty()) {
            int v = qu.front(); qu.pop();

            if (dist[v] < k)
                for (auto u: adj[v]) {
                    deg[u]--;
                    if (deg[u] <= 1 && dist[u] == -1)
                        dist[u] = dist[v]+1, qu.push(u);
                }
        }

        int count = 0;
        for (auto v: dist) count += v==-1;
        cout << count-1 << endl;
    }
    return 0;
}
