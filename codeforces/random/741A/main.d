/*
 * LINK: https://codeforces.com/problemset/problem/741/A
 * NAME: A. Arpa's loud Owf and Mehrdad's evil plan
*/

import std;

void main() {
    int n = readln.chomp.to!int;

    auto adj = [0] ~ readln.split.to!(int[]);
    auto deg = new int[](n+1), vis = new bool[](n+1);

    foreach (v; adj) deg[v]++;
    foreach (d; deg)
        if (!d) return writeln(-1);

    int dfs(int v) => vis[v] ? 0 : (vis[v] = 1) + dfs(adj[v]);

    int[] comps;
    foreach (i; 1..n+1)
        if (!vis[i]) comps ~= dfs(i);

    int mn = comps.fold!lcm;
    writeln(mn%2 ? mn : mn/2);
}
