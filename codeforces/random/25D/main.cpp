/*
 * LINK: https://codeforces.com/problemset/problem/25/D
 * NAME: D. Roads not only in Berland
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace dsu {
    vector<ll> parent;
    vector<ll> size;

    void build (ll n) {
        parent.resize(n+1), size.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        fill(size.begin(), size.end(), 1);
    }

    ll find(ll v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool join(ll a, ll b) {
        a = find(a), b = find(b);

        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        return true;
    }
}
int main(void) {
    ll n; cin >> n;
    dsu::build(n);

    vector<ll> useless;

    vector<pair<ll, ll>> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        auto &[a, b] = edges[i];
        cin >> a >> b;

        if (!dsu::join(a, b))
            useless.push_back(i);
    }

    set<ll> lset;
    for (int i = 1; i <= n; i++) lset.insert(dsu::find(i));

    cout << useless.size() << endl;

    auto it = lset.begin();
    ll u = *it;
    ++it;
    ll i = 0;

    while (it != lset.end()) {
        ll v = *it;
        auto [a, b] = edges[useless[i]];
        cout << a << " " << b << " " << u << " " << v << endl;
        i++, ++it;
    }
    return 0;
}
