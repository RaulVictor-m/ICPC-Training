/*
 * LINK: https://codeforces.com/problemset/problem/1881/F
 * NAME: F. Minimum Maximum Distance
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> d1, d;
vector<bool> mark;

void dists(int v, int p, int d, vector<int>& dist) {
    if (mark[v]) dist[v] = d;
    for (auto u: adj[v]) 
        if (u != p) dists(u, v, d+1, dist);
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        adj.clear(), adj.resize(n+1);
        d1.clear(), d1.resize(n+1),
        d.clear(), d.resize(n+1);
        mark.clear(), mark.resize(n+1);

        for (int i = 0; i < k; i++) {
            int v; cin >> v;
            mark[v] = 1;
        }

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dists(1, 0, 0, d);
        int da = max_element(d.begin(), d.end()) - d.begin();
        dists(da, 0, 0, d1);
        int db = max_element(d1.begin(), d1.end()) - d1.begin();

        cout << (d1[db]+1)/2 << endl;
    }
    return 0;
}
