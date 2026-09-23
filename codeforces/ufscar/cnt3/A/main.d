/*
 * LINK: https://codeforces.com/group/jlSbN106ET/contest/717777/problem/A
 * NAME: A. Building an Aquarium
*/

import std;

void main() {
    int t = readln.chomp.to!int;
    while (t--) {
        long n, x; readf("%d %d\n", &n, &x);
        auto ht = readln.split.to!(long[]);

        bool ok(long m) {
            long acc = 0;
            foreach (v; ht)
                if ((acc += max(m-v, 0L)) > x) return false;

            return true;
        }

        long l = 1, r = 10L^^18L;
        while (l <= r) {
            long m = (l+r)/2;
            if (ok(m)) l = m+1;
            else r = m-1;
        }
        writeln(l-1);
    }
}
