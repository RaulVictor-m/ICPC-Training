/*
 * LINK: https://codeforces.com/problemset/problem/2143/C
 * NAME: C. Max Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<bool> vis;
vector<int> ans;

void tsort(int v) {
    if (vis[v]) return; vis[v] = 1;
    for (auto u: graph[v]) tsort(u);
    ans.push_back(v);
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        graph.clear(), vis.clear(), ans.clear();
        graph.resize(n+1), vis.resize(n+1);

        for (int i = 1; i < n; i++) {
            ll a, b, x, y; cin >> a >> b >> x >> y;
            if (x > y) swap(a, b);
            graph[a].push_back(b);
        }

        for (int i = 1; i <= n; i++) tsort(i);

        reverse(ans.begin(), ans.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[ans[i]-1] = i+1;
        for (auto v: res) cout << v << " "; cout << '\n';
    }
    return 0;
}
