/*
 * LINK: https://codeforces.com/problemset/problem/1144/F
 * NAME: F. Graph Without Long Directed Paths
*/
import std;

void main() {
    int n, m; readf("%d %d\n", &n, &m);

    auto adj = new int[][](n+1);
    auto edges = new int[2][](m);

    foreach (i; 0..m) {
        int a, b; readf("%d %d\n", &a, &b);
        adj[a] ~= b, adj[b] ~= a;

        edges[i] = [a, b];
    }

    auto vis = new bool[](n+1), col = new bool[](n+1);

    bool dfs(int v) {
        bool f = true;
        foreach (u; adj[v]) {
            if (!vis[u])
                vis[u] = 1, col[u] = col[v]^1, f = dfs(u);
            else if (col[u] != (col[v]^1)) return false;

            if (!f) return false;
        }

        return true;
    }

    if (dfs(1)) {
        writeln("YES");
        foreach (e; edges) write(col[e[0]] ? 0 : 1);
        writeln;

    } else writeln("NO");
}
