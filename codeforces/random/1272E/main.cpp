/*
 * LINK: https://codeforces.com/problemset/problem/1272/E
 * NAME: E. Nearest Opposite Parity
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = INT_MAX/2;
vector<vector<int>> graph;
vector<int> dist, vs;

int main(void) {
    int n; cin >> n;
    dist.resize(n+1), vs.resize(n+1);
    graph.resize(n+1);

    queue<int> oqu, equ;
    for (int i = 1; i <= n; i++) {
        cin >> vs[i];
        int l = i - vs[i], r = i + vs[i];

        if (l > 0) graph[l].push_back(i);
        if (r <= n) graph[r].push_back(i);

        if (vs[i]&1) oqu.push(i); 
        else         equ.push(i);
    }


    while (!oqu.empty()) {
        int v = oqu.front(); oqu.pop();
        for (auto u: graph[v]) {
            if (vs[u]%2 == 1 || dist[u]) continue;

            if (vs[v]%2 == 0)
                oqu.push(u), dist[u] = dist[v]+1;
            else
                oqu.push(u), dist[u] = 1;
        }
    }

    while (!equ.empty()) {
        int v = equ.front(); equ.pop();
        for (auto u: graph[v]) {
            if (vs[u]%2 == 0 || dist[u]) continue;

            if (vs[v]%2 == 1)
                equ.push(u), dist[u] = dist[v]+1;
            else
                equ.push(u), dist[u] = 1;
        }
    }

    for (int i = 1; i <= n; i++) 
        cout << (dist[i]?dist[i]:-1) << ' '; cout << '\n';

    return 0;
}
