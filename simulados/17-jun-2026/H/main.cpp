/*
 * LINK: https://codeforces.com/gym/103960/problem/H
 * NAME: Habilitando a Movimentacao
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        slipt the graph in strongly connected components 
        and the answer is max(sources, sinks)

*/
vector<bool> vis;

void dfs(long i, vector<vector<long>> &g, vector<long> &out) {
    if (vis[i]) return;
    vis[i] = 1;

    for (auto v: g[i]) dfs(v, g, out);
    out.push_back(i);
}

int main(void) {
    long n, m; cin >> n >> m;
    vis.resize(n+1);
    vector<vector<long>> graph(n+1), rgraph(n+1);

    for (int i = 0; i < m; i++) {
        long a, b; cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    // node tout
    vector<long> tout; 
    for (int i = 1; i <= n; i++) dfs(i, graph, tout);

    reverse(tout.begin(), tout.end());

    // slip SCC
    vis.assign(n+1, 0);
    vector<long> root(n+1), scc;
    long sccs_count = 0;
    for (auto t: tout) {
        if (vis[t]) continue;
        dfs(t, rgraph, scc);

        sccs_count++; //index from 1
        for (auto c: scc) root[c] = sccs_count; 
        scc.clear();
    }

    // already a connected graph
    if (sccs_count == 1) {
        cout << 0 << endl;
        return 0;
    }

    // count ins and outs in condensation graph
    vector<bool> in(sccs_count+1), out(sccs_count+1);
    for (long i = 1; i < graph.size(); i++)
        for (auto j: graph[i])
            if (root[i] != root[j])
                in[root[j]] = 1, out[root[i]] = 1;


    //sinks sources count
    long cIn = 0, cOut = 0;
    for (int i = 1; i <= sccs_count; i++)  cIn += in[i], cOut += out[i];
    cout << max(sccs_count-cIn, sccs_count-cOut);
    return 0;
}
