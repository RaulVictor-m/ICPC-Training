/*
 * LINK: https://codeforces.com/problemset/problem/1320/B
 * NAME: B. Navigation System
*/

import std;

void main() {
    int n, m; readf("%d %d\n", &n, &m);

    auto adj = new int[][](n+1);

    foreach (i; 0..m) {
        int a, b; readf("%d %d\n", &a, &b);
        adj[b] ~= a;
    }

    int pl = readln.chomp.to!int;
    auto path = readln.split.to!(int[]);

    int s = path[0], t = path[$-1];

    int[] qu;
    auto dist = new int[](n+1), cnt = new int[](n+1);
    dist[] = -1, dist[t] = 0;

    qu ~= t;
    while (qu.length) {
        int v = qu[0];
        qu = qu[1..$];

        foreach (u; adj[v]) {
            if (dist[u] == dist[v]+1) cnt[u]++;
            if (dist[u] == -1) qu ~= u, dist[u] = dist[v]+1, cnt[u] = 1;
        }
    }

    int mn = 0, mx = 0;

    foreach (i; 1..path.length) {
        int p = path[i];
        if (dist[p] < dist[s]) mx += (cnt[s] > 1);
        else mx++, mn++;

        s = p;
    }
    writeln(mn, " ", mx);
}
