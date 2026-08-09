/*
 * LINK: https://codeforces.com/problemset/problem/690/C1
 * NAME: C1. Brain Network (easy)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace uf {
    vector<int> par, sz;
    void build(int n) {
        par.resize(n+1), sz.resize(n+1, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        return par[v] == v? v : find(par[v]);
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);

        par[b] = a, sz[a] += sz[b];
        return true;
    }
}

int main(void) {
    int n, m; cin >> n >> m;
    if (m != n-1) {
        cout << "no\n";
        return 0;
    }

    uf::build(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (!uf::join(a, b)) {
            cout << "no\n";
            return 0;
        }
    }

    cout << "yes\n";
    return 0;
}
