/*
 * LINK: https://codeforces.com/problemset/problem/1594/D
 * NAME: D. The Number of Imposters
*/

import std;

void main() {
    int t = readln.chomp.to!int;
    test: while (t--) {
        int n, m; readf("%d %d\n", &n, &m);

        auto adj = new int[][](n+1);

        foreach (i; 0..m) {
            int a, b;
            char[] c;
            readf("%d %d %s\n", &a, &b, &c);

            if (c == "imposter") {
                adj[a] ~= b, adj[b] ~= a;
            } else {
                adj[a] ~= cast(int)adj.length;
                adj[b] ~= cast(int)adj.length;
                adj ~= [a, b];
            }
        }

        auto col = new bool[](adj.length);
        auto vis = new bool[](adj.length);

        int[2] c;
        bool dfs(int v) {
            c[col[v]] += v <= n;

            vis[v] = 1;
            bool f = 1;

            foreach (u; adj[v]) {
                if (!vis[u]) col[u] = col[v]^1, f = dfs(u);
                else if (col[u] == col[v]) return false;
                if (!f) return false;
            }
 
            return true;
        }

        int mx = 0;
        foreach (v; 1..n+1) {
            if (!vis[v] && !dfs(cast(int)v)) {
                writeln(-1);
                continue test;
            }
            mx += max(c.tupleof), c[] = 0;
        }

        writeln(mx);
    }
}
