/*
 * LINK: 
 * NAME: Distancia dos pontos
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

namespace dsu {
    vector<long> parent;
    vector<double> size;

    void build(long n) {
        parent.resize(n, 0), size.resize(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i, size[i] = 0;
    }

    long find(long p) {
        if (parent[p] == p) return p;
        return parent[p] = find(parent[p]);
    }

    void join(long a, long b, double w) {
        a = find(a), b = find(b);

        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);

        size[a] += size[b] + w;
        parent[b] = a;
        return;
    }
}

int main(void) {
    long test; cin >> test;
    while (test--) {
        long n; cin >> n;
        vector<array<long, 2>> points(n); // x y
        vector<pair<double, array<long, 2>>> edges; // w i - j

        for (auto &p: points) cin >> p[0] >> p[1];

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                double dx = pow(points[i][0]-points[j][0], 2);
                double dy = pow(points[i][1]-points[j][1], 2);

                edges.push_back({sqrt(dx+dy), {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        dsu::build(n);
        for (auto &e: edges) dsu::join(e.second[0], e.second[1], e.first);

        printf("%.4lf\n", dsu::size[dsu::find(0)]);
    }
    return 0;
}
