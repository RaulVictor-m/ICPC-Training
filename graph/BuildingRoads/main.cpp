/*
 * LINK: https://cses.fi/problemset/task/1666
 * NAME: Building Roads
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5+2;
const ll MAXM = MAXN*2;

bool visited[MAXN] = {0};
vector<list<int>> graph;

void dfs(int i) {
    if (visited[i]) return;
    visited[i] = 1;

    for (auto v: graph[i]) dfs(v);
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> roads;
    roads.reserve(n);

    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            roads.push_back(i);
        }
    }

    cout << roads.size() << endl;
    for (auto v: roads) {
        cout << 1 << " " << v << endl;
    }

    return 0;
}
