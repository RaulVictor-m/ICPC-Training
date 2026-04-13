/*
 * LINK: https://cses.fi/problemset/task/1667
 * NAME: Message Route
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/
const ll MAXN = 1e5+3;
const ll MAXM = MAXN*2;

int visited[MAXN] = {0};
vector<list<int>> graph;

int bfs() {
    queue<array<int, 3>> qu;
    qu.push({1, 1, -1});

    while (!qu.empty()) {
        int i = qu.front()[0];
        int count = qu.front()[1];
        int parent = qu.front()[2];
        qu.pop();

        if (visited[i]) continue;
        visited[i] = parent;
        if (i == graph.size()-1) return count;

        for (auto v: graph[i]) if (!visited[v]) qu.push({v, count+1, i});
    }
    return -1;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int res = bfs();
    if (res == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << res << endl;
    vector<int> resp;
    resp.reserve(n+1);

    for (int i = n; i > 0; i = visited[i]) {
        resp.push_back(i);
    }

    for (int i = resp.size()-1; i >= 0; i--) {
        cout << resp[i] << " ";
    }

    cout << endl;

    return 0;
}
