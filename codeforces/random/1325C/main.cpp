/*
 * LINK: https://codeforces.com/problemset/problem/1325/C
 * NAME: C. Ehab and Path-etic MEXs
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> graph;
vector<int> edges;

int main(void) {
    int n; cin >> n;
    graph.resize(n+1), edges.resize(n, -1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }

    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() >= 3) {
            edges[graph[i][0].second] = t++;
            edges[graph[i][1].second] = t++;
            edges[graph[i][2].second] = t++;
            break;
        }
    }

    for (auto g: graph)
        for (auto [v, e]: g) 
            if (edges[e] == -1) edges[e] = t++;


    for (int i = 1; i < n; i++) cout << edges[i] << '\n';

    return 0;
}
