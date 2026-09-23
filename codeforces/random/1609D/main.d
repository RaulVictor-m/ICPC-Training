/*
 * LINK: https://codeforces.com/problemset/problem/1609/D
 * NAME: D. Social Network
*/

import std;

void main() {
    int n, d; readf("%d %d\n", &n, &d);
    auto par = repeat(-1, n+1).array;
    auto frq = [0, n] ~ new int[](n-1);

    int find(int v) => par[v] < 0 ? v : (par[v] = find(par[v]));
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (par[a] > par[b]) swap(a, b);

        frq[-par[b]]--, frq[-par[a]]--;
        par[a] += par[b], par[b] = a;
        frq[-par[a]]++;
    }

    int mx = 0, k = 0;
    int getmax(int k, int i) {
        if (k >= 0 && i > 0) {
            frq[i]--;
            int ans = (frq[i] >= 0 ? getmax(k-1, i)+i : getmax(k, i-1));
            frq[i]++;
            return ans;
        } else return 0;
    }

    foreach (i; 0..d) {
        int a, b; readf("%d %d\n", &a, &b);
        if (find(a) == find(b)) k++;
        else join(a, b);
        writeln(getmax(k, n)-1);
    }
}
