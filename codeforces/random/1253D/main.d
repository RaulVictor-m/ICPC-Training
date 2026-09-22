/*
 * LINK: https://codeforces.com/problemset/problem/1253/D
 * NAME: D. Harmonious Graph
*/
import std;

void main() {
    int n, m; readf("%d %d\n", &n, &m);
    auto par = iota(0, n+1).array;

    int find(int v) => par[v] != v ? (par[v] = find(par[v])) : v;
    void join(int v, int u) {
        v = find(v), u = find(u), par[min(u, v)] = max(u, v);
    }

    foreach (i; 0..m) {
        int a, b; readf("%d %d\n", &a, &b);
        join(a, b);
    }

    int mx = 1, c = 0;
    foreach (i; 1..n+1) {
        if (i < mx && find(i) != find(mx)) join(i, mx), c++;
        mx = max(mx, find(i));
    }

    writeln(c);
}

