/*
 * LINK: https://cses.fi/problemset/task/1686
 * NAME: Coin Colector
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/*
    REASON:

    the ideia is to just split the graph in strongly connected comps
    than you know that there are no cycles in between them
    so you just dfs and find the maximum value from any given
    component like if it is a tree of components 

*/

vector<vector<int>> graph;
vector<vector<int>> rgraph;
vector<pair<ull, vector<int>>> cgraph;
vector<int> visited;
vector<int> vals;
vector<ull> comp_max;

void dfs(vector<vector<int>>& g, int i, vector<int>& out) {
    if (visited[i]) return;

    visited[i] = 1;
    for (auto v: g[i]) dfs(g, v, out);
    out.push_back(i);
}

ull dfs2(int i) {
    if (comp_max[i]) return comp_max[i];

    ull lmax = cgraph[i].first;
    for (auto e: cgraph[i].second) {
        lmax = max(lmax, cgraph[i].first + dfs2(e));
    }

    return comp_max[i] = lmax;
}

int main(void) {
    ull n, m; cin >> n >> m;
    graph.resize(n+1);
    rgraph.resize(n+1);
    visited.resize(n+1);
    vals.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> vals[i];

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    // strongly connected comps
    vector<int> tout;
    tout.reserve(n+1);
    for (int i = 1; i <= n; i++) dfs(graph, i, tout);

    reverse(tout.begin(), tout.end());

    visited.assign(n+1, 0);

    vector<int> component;
    vector<int> cmp_roots;
    vector<ull> cmp_val;
    component.reserve(n+1);
    cmp_roots.resize(n+1);
    cmp_val.resize(n+1);

    cgraph.resize(1);
    cgraph.reserve(n+1);

    int count = 1;
    for (auto i: tout) {
        dfs(rgraph, i, component);

        for (auto c: component) {
            cmp_roots[c] = count;
            cmp_val[count] += vals[c];
        }

        if (!component.empty()) {
            cgraph.push_back({cmp_val[count], {}});
            count++;
        }

        component.clear();
    }

    for (int i = 1; i <= n; i++) {
        for (auto e: graph[i]) {
            if (cmp_roots[i] != cmp_roots[e]) {
                cgraph[cmp_roots[i]].second.push_back(cmp_roots[e]);
            }
        }
    }

    // solve problem
    comp_max.resize(count);
    ull lmax = 0;
    for (int i = 1; i < cgraph.size(); i++) {
        lmax = max(lmax, dfs2(i));
    }

    cout << lmax << endl;

    return 0;
}
