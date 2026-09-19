/*
 * LINK: https://codeforces.com/problemset/problem/698/B
 * NAME: B. Fix a Tree
*/

import std;

void main() {
    int n = readln.chomp.to!int;
    auto par = [0] ~ readln.split.to!(int[]);

    auto dsu = iota(0, n+1).array;
    int find(int v) => (dsu[v] == v ? v : (dsu[v] = find(dsu[v])));

    int c = 0, root = 0;
    foreach (i; 1..n+1) if (i == par[i]) root = i;

    foreach (i; 1..n+1) {
        if (find(i) == find(par[i])) {
            if (!root) root = i;
            if (root != par[i]) par[i] = root, c++;
        }

        dsu[find(i)] = find(par[i]);
    }

    writeln(c);
    foreach (p; par[1..$]) write(p, " ");
    writeln;
}
