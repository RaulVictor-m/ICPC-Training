/*
 * LINK: https://cses.fi/problemset/task/1691
 * NAME: Mail Delivery
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    https://cp-algorithms.com/graph/euler_path.html
    just finding the eulirian path
*/

vector<unordered_set<int>> graph;
vector<long> ans;

void euler (long i) {
    while (!graph[i].empty()) {
        long v = (*graph[i].begin());
        graph[i].erase(graph[i].begin());
        graph[v].erase(i);
        euler(v);
    }

    ans.push_back(i);
};

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);

    vector<long> deg(n+1);

    for (int i = 1; i <= m; i++) {
        long a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
        deg[a]++; deg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    euler(1);
    for (int i = 1; i <= n; i++) {
        if (graph[i].size()) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    // path
    for (auto v: ans) cout << v << " "; cout << endl;

    return 0;
}
