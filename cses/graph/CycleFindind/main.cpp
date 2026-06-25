/*
 * LINK: https://cses.fi/problemset/task/1197
 * NAME: Cycle Finding
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll INF = LONG_LONG_MAX/3;
vector<array<ll, 3>> edges;
vector<ll> dists;
vector<ll> parents;

ll bellman() {
    ll x = 0;
    for (int i = 1; i < dists.size() && x != -1; i++) {
        x = -1;
        for (auto [a, b, c]: edges) {
            if (dists[a] != INF) {
                if (dists[b] > (dists[a] + c)) {
                    x = b;
                    dists[b] = dists[a] + c;
                    parents[b] = a;
                }
            }
        }
    }

    return x;
}
int main(void) {
    int n, m; cin >> n >> m;
    edges.reserve(m);
    dists.resize(n+1, 0);
    parents.resize(n+1, 0);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    ll res = bellman();
    if (res == -1) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    // make sure res is on the decreasing cycle
    for (int i = 1; i < parents.size(); i++) res = parents[res];

    vector<ll> cycle;
    cycle.reserve(n);

    for (ll v = res;;v = parents[v]) {
        cycle.push_back(v);
        if (v == res && cycle.size() > 1) break;
    }

    for (int i = cycle.size()-1; i >= 0; i--) cout << cycle[i] << " ";
    cout << endl;

    return 0;
}
