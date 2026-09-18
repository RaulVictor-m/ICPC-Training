/*
 * LINK: https://codeforces.com/problemset/problem/1850/H
 * NAME: H. The Third Letter
*/

import std;

void main() {
    int t = readln.chomp.to!int;
    test: while (t--) {
        int n, m; readf("%d %d\n", &n, &m);

        auto adj = new int[2][][](n+1);
        foreach (i; 0..m) {
            int a, b, w; readf("%d %d %d\n", &a, &b, &w);
            adj[a] ~= [b, -w], adj[b] ~= [a, w];
        }

        auto vis = new int[](n+1), dist = new long[](n+1);

        bool dfs(int v) {
            vis[v] = 1;
            foreach (e; adj[v]) {
                auto u = e[0], w = cast(long)e[1];

                if (!vis[u]) {
                    dist[u] = dist[v]+w;
                    if (!dfs(u)) return false;
                } else {
                    if (dist[u] != dist[v]+w) return false;
                }
            }
            return true;
        }

        foreach (v; 1..n+1) {
            if (!vis[v] && !dfs(v)) {
                writeln("NO");
                continue test;
            }
        }
        writeln("YES");
    }
}
