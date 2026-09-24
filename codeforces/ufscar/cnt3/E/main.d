/*
 * LINK: https://codeforces.com/group/jlSbN106ET/contest/717777/problem/E
 * NAME: E. Forever Winter
*/

import std;

void main() {
    int t = readln.chomp.to!int;
    while (t--) {
        int n, m; readf("%d %d\n", &n, &m);
        int[201] deg = 0;
        foreach (i; 0..m) {
            int a, b; readf("%d %d\n", &a, &b);
            deg[a]++, deg[b]++;;
        }

        int y = deg.fold!"a + (b==1)"(0);
        int x = n - y - 1;
        y = y/x;
        writeln(x, " ", y);
    }
}
