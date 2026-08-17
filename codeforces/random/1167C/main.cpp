/*
 * LINK: https://codeforces.com/problemset/problem/1167/C
 * NAME: C. News Distribution
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+5;

namespace uf {
    int par[N], sz[N];

    void build(int n) {
        for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    }

    int find(int v) {
        return par[v] == v ? v : find(par[v]);
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);

        sz[a] += sz[b], par[b] = a;
    }
}

int main(void) {
    int n, m; cin >> n >> m;

    uf::build(n);

    while (m--) {
        int k; cin >> k;
        if (k--) {
            int v0; cin >> v0;
            while (k--) {
                int v; cin >> v;
                uf::join(v0, v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << uf::sz[uf::find(i)] << ' ';
    cout << '\n';
    return 0;
}
