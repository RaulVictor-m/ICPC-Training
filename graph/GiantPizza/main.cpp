/*
 * LINK: https://cses.fi/problemset/task/1684
 * NAME: Giant Pizza
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        https://cp-algorithms.com/graph/2SAT.html
        https://cp-algorithms.com/graph/strongly-connected-components.html

*/

vector<vector<int>> graph, rgraph;
vector<bool> visited;
vector<int> tout; // is basically the time it left dfs SCC algorithm

void dfs(int i, vector<int> &out, vector<vector<int>> &g) {
    if (visited[i]) return;
    visited[i] = 1;

    for (auto e: g[i]) dfs(e, out, g);

    out.push_back(i);
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(m*3);
    rgraph.resize(m*3);
    visited.resize(m*2);
    tout.reserve(m*2);

    for (int i = 0; i < n; i++) {
        int a, b;
        char ap, bp;
        cin >> ap >> a >> bp >> b;

        a = (a-1)<<1, b = (b-1)<<1;
        a |= (ap == '-'), b |= (bp == '-'); // X is even not(X) is odd

        graph[/*not(a)*/ a^1].push_back(b);
        graph[/*not(b)*/ b^1].push_back(a);

        rgraph[b].push_back(/*not(a)*/ a^1);
        rgraph[a].push_back(/*not(b)*/ b^1);
    }

    // connect component
    for (int i = 0; i < m*2; i++) dfs(i, tout, graph);

    visited.assign(m*2, 0);
    reverse(tout.begin(), tout.end());

    vector<int> comp;
    vector<int> i_comp(m*2);
    int comp_count = 0;
    for (auto i: tout) {
        dfs(i, comp, rgraph);

        if (!comp.empty()) {
            for (auto j: comp) i_comp[j] = comp_count;
            comp_count++;
            comp.clear();
        }
    }

    for (int i = 0; i < m*2; i+=2)
        if (i_comp[i] == i_comp[i^1]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

    for (int i = 0; i < m*2; i+=2)
        cout << (i_comp[i] > i_comp[i^1] ? "+ " : "- ");

    cout << endl;
    return 0;
}
