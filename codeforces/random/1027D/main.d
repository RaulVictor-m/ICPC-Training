/*
 * LINK: https://codeforces.com/problemset/problem/1027/D
 * NAME: D. Mouse Hunt
*/

import std;

void main() {
    int n; readf("%d\n", &n);
    long[] ws = [0L] ~ readln.split.to!(long[]);
    int[] adj = [0] ~ readln.split.to!(int[]);

    long sum = 0;
    bool[] vis = new bool[](n+1);
    int[] deg = new int[](n+1);

    foreach (i, e; adj) {
        if (i == e) sum += ws[i], ws[i] = 0;
        deg[e]++;
    }

    void remV(int v) {
        if (deg[v] >= 1 || vis[v]) return;
        deg[adj[v]]--, remV(adj[v]), vis[v] = 1;
    }

    foreach (i, e; deg)
        if (e == 0) remV(cast(int)i);

    long dfs(int v) {
        if (vis[v]) return 0;
        vis[v] = 1;

        long res = min(ws[v], dfs(adj[v]));
        if (!res) res = ws[v];

        return res;
    }

    foreach(i; 1 .. n+1) sum += dfs(i);
    writeln(sum);
}
