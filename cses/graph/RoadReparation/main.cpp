/*
 * LINK: https://cses.fi/problemset/task/1675
 * NAME: Road Reparation
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        https://cp-algorithms.com/graph/mst_kruskal.html
        https://cp-algorithms.com/data_structures/disjoint_set_union.html
*/

const ll MAXN = 1e5+2;
const ll MAXM = MAXN*2;
namespace dsu {
    ll parent[MAXN] = {0};
    ll size[MAXN] = {0};
    ll n = 0;

    void build() {
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    ll find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void join(int a, int b, int c) {
        a = find(a), b = find(b);

        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);

        parent[b] = a;
        size[a] += size[b] + c;
    }
}

vector<array<ll, 3>> edges;

int main(void) {
    int n, m; cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }

    sort(edges.begin(), edges.end());
    dsu::n = n; dsu::build();


    for (auto [c, a, b]: edges) {
        dsu::join(a, b, c);
    }

    int father = dsu::find(1);
    for (int i = 2; i <= n; i++) {
        if (dsu::find(i) != father) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << dsu::size[father] << endl;

    return 0;
}
