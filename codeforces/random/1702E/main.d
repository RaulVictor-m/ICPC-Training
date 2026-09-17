/*
 * LINK: https://codeforces.com/problemset/problem/1702/E
 * NAME: E. Split Into Two Sets
*/

import std;

void main() {
    int t = readln.chomp.to!int;
    test: while (t--) {
        int n = readln.chomp.to!int;

        auto adj = new int[][](n+1);
        auto vis = new bool[](n+1), col = new bool[](n+1);

        foreach (i; 0..n) {
            int a, b; readf("%d %d\n", &a, &b);
            adj[a] ~= b, adj[b] ~= a;
        }

        bool dfs(int v) {
            if (adj[v].length > 2) return false;

            vis[v] = 1;
            bool f = 1;
            foreach (u; adj[v]) {
                if (!vis[u]) col[u] = col[v]^1, f = dfs(u);
                else if (col[u] == col[v]) return false;
                if (!f) return false;
            }

            return true;
        }

        foreach (v; 1..n+1)
            if (!vis[v] && !dfs(v)) {
                writeln("NO");
                continue test;
            }
        writeln("YES");
    }
}
