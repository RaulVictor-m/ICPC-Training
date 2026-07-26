/*
 * LINK: https://codeforces.com/problemset/problem/1404/B
 * NAME: B. Tree Tag
*/

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<int> dist;

void dists(int v, int p, int h) {
    dist[v] = h++;
    for (auto u: graph[v]) if (u != p) dists(u, v, h);
}

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, a0, b0, da, db; cin >> n >> a0 >> b0 >> da >> db;
        graph.clear(), dist.clear();
        graph.resize(n+1), dist.resize(n+1);

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int d1, d2; // diameter

        if (db <= da*2) goto alice; // outrun

        dists(a0, 0, 0);
        if (dist[b0] <= da) goto alice; // win in first turn

        d1 = max_element(dist.begin(), dist.end()) - dist.begin();
        dist.assign(n+1, 0);
        dists(d1, 0, 0);

        d2 = max_element(dist.begin(), dist.end()) - dist.begin();

        if (dist[d2] <= da*2) goto alice; // diameter is too small to run

        cout << "Bob\n";
        continue;

        alice:
            cout << "Alice\n";
    }
    return 0;
}
