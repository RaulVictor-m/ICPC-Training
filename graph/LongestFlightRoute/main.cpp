/*
 * LINK: https://cses.fi/problemset/task/1680
 * NAME: Longest Flight Route
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

vector<list<int>> graph;
vector<int> dists;
vector<int> g_son;

int dfs(int i) {
    if (dists[i] != -1) return dists[i];
    if (i == graph.size()-1) return 1;

    dists[i] = 0;
    for (auto v: graph[i]) {
        int val = dfs(v);
        if (val && val >= dists[i]) {
            dists[i] = val+1;
            g_son[i] = v;
        }
    }

    return dists[i];
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);
    dists.resize(n+1, -1);
    g_son.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    int res = dfs(1);

    if (!res) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << res << endl;
    for (int i = 1; i != 0; i = g_son[i]) cout << i << " "; cout << endl;
    return 0;
}
