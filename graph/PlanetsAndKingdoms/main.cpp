/*
 * LINK: https://cses.fi/problemset/task/1683
 * NAME: Planets and Kingdoms
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    https://cp-algorithms.com/graph/strongly-connected-components.html
    this link is the reference algorithm for the problem
*/

vector<vector<int>> graph;
vector<vector<int>> rgraph;
vector<bool> visited;
vector<int> t_out;
vector<int> component;
vector<int> resp;

void dfs(int i, const vector<vector<int>> &g, vector<int> &out) {
    if (visited[i]) return;
    visited[i] = 1;

    for (auto v: g[i]) dfs(v, g, out);
    out.push_back(i);
}

int main(void) {
    int n, q; cin >> n >> q;
    graph.resize(n+1);
    rgraph.resize(n+1);
    visited.resize(n+1, 0);
    component.reserve(n);
    t_out.reserve(n);
    resp.resize(n+1);

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) dfs(i, graph, t_out);
    visited.assign(n+1, 0);

    int lcount = 1;
    for (int i = n-1; i >= 0; i--) {
        dfs(t_out[i], rgraph, component);
        if (!component.empty()) {
            for (int e: component) {
                resp[e] = lcount;
            }
            lcount++;
        }
        component.clear();
    }

    cout << lcount - 1<< endl;;
    for (int i = 1; i <= n; i++) cout << resp[i] << " "; cout << endl;
    return 0;
}
