/*
 * LINK: https://codeforces.com/problemset/problem/1605/D
 * NAME: D. Treelabeling
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
array<vector<int>, 2> col;

void color(int v, int p, int c) {
    col[c].push_back(v);
    for (auto u: adj[v])
        if (u != p) color(u, v, c^1);
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.clear(), adj.resize(n+1);
        col[0].clear(), col[1].clear();

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        color(1, 0, 0);

        if (col[0].size() > col[1].size()) swap(col[0], col[1]);

        bitset<32> w(col[0].size());

        vector<int> ans(n+1);
        for (int i = 1; i <= n; i++) {
            int mi = 31-__builtin_clz(i);
            if (w[mi]) 
                ans[col[0].back()] = i, col[0].pop_back();
            else       
                ans[col[1].back()] = i, col[1].pop_back();
        }

        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
