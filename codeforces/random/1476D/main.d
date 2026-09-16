/*
 * LINK: https://codeforces.com/problemset/problem/1476/D
 * NAME: D. Journey
*/

import std;

void main() {
    int t = readln.chomp.to!int;
    while (t--) {
        int n = readln.chomp.to!int;
        string adj = readln.chomp();

        auto dpr = new int[2][](n+1);
        auto dpl = new int[2][](n+1);

        foreach_reverse (i; 0..n)
            if (adj[i] == 'R') dpr[i][0] = dpr[i+1][1] + 1;
            else               dpr[i][1] = dpr[i+1][0] + 1;

        foreach (i; 1..n+1)
            if (adj[i-1] == 'L') dpl[i][0] = dpl[i-1][1] + 1;
            else                 dpl[i][1] = dpl[i-1][0] + 1;

        foreach (i; 0..n+1) write(dpl[i][0]+dpr[i][0]+1, ' ');
        writeln;
    }
}
