/*
 * LINK: https://codeforces.com/problemset/problem/277/A
 * NAME: A. Learning Languages
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

    void join(ll a, ll b) {
        a = find(a), b = find(b);

        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
}

int main(void) {
    ll n, m; cin >> n >> m;
    dsu::build(n+m);

    ll count = 0;
    for (int i = 0; i < n; i++) {
        ll c; cin >> c;
        count += c;
        for (int j = 0; j < c; j++) {
            ll v; cin >> v;
            dsu::join(i, (v-1)+n);
        }
    }

    if (!count) {
        cout << n << endl;
        return 0;
    }

    set<ll> lset;
    for (int i = 0; i < n; i++) lset.insert(dsu::find(i));

    cout << lset.size() - 1 << endl;
    return 0;
}
