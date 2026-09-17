/*
 * LINK: https://codeforces.com/problemset/problem/919/D
 * NAME: D. Substring
*/

import std;
import core.memory;

void main() {
    GC.disable();
    int n, m; readf("%d %d\n", &n, &m);
    char[] let = (" " ~ readln.chomp).to!(char[]);
    foreach (ref c; let) c -= 'a';

    auto adj = new int[][](n+1);
    auto deg = [1] ~ new int[](n);

    foreach (i; 0 .. m) {
        int a, b; readf("%d %d\n", &a, &b);
        adj[a] ~= b, deg[b]++;
    }

    int[] qu;
    auto dp = new int[26][](n+1), cnt = 0;

    foreach (i, d; deg)
        if (!d) qu ~= cast(int)i;

    while (qu.length) {
        int v = qu[0];
        qu = qu[1..$], cnt++;
        dp[v][let[v]]++;

        foreach (u; adj[v]) {
            foreach (k, x; dp[v]) dp[u][k] = max(dp[u][k], x);
            if (!(--deg[u])) qu ~= u;
        }
    }

    int mx = 0;
    foreach (ref rw; dp) mx = max(mx, max(rw.tupleof));

    if (cnt == n) writeln(mx);
    else          writeln(-1);
}

