/*
 * LINK: https://cses.fi/problemset/task/1676
 * NAME: Road Construction
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5+2;
const ll MAXM = MAXN*2;

namespace dsu {
    ll parent[MAXN] = {0};
    ll size[MAXN] = {0};
    ll max_size = 0;
    ll n_comps = 0;

    void build(int n) {
        n_comps = n;
        for (int i = 1; i <= n; i++) parent[i] = i, size[i] = 1;
    }

    ll find(int a) {
        return parent[a] == a ? (a) : (parent[a] = find(parent[a]));
    }

    void join(int a, int b) {
        a = find(a), b = find(b);

        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        max_size = max(size[a], max_size);
        n_comps--;
    }
}

int main(void) {
    int n, m; cin >> n >> m;
    dsu::build(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        dsu::join(a, b);
        cout << dsu::n_comps << " " << dsu::max_size << endl;
    }
    return 0;
}
