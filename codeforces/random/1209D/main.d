/*
 * LINK: https://codeforces.com/problemset/problem/1209/D
 * NAME: D. Cow and Snacks
*/

import std;

void main() {
    int n, m, c = 0; readf("%d %d\n", &n, &m);

    auto par = iota(0, n+1).array;
    int find(int v) => par[v] == v ? v : (par[v] = find(par[v]));

    foreach(i; 0..m) {
        int a, b; readf("%d %d\n", &a, &b);
        a = find(a), b = find(b);

        par[a] = b, c += (a == b);
    }

    writeln(c);
}
