/*
 * LINK: https://codeforces.com/problemset/problem/893/C
 * NAME: C. Rumor
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace dsu {
    vector<ll> parent;
    vector<ll> size;
    vector<ll> money;

    void build (ll n) {
        parent.resize(n+1), money.resize(n+1), size.resize(n+1);
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
        money[a] = min(money[a], money[b]);
    }
}

int main(void) {
    ll n, m; cin >> n >> m;
    dsu::build(n);

    for (int i = 1; i <= n; i++) cin >> dsu::money[i];
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        dsu::join(a, b);
    }

    set<ll> lset;
    for (int i = 1; i <= n; i++) lset.insert(dsu::find(i));

    ll total = 0;
    for (auto v: lset) total += dsu::money[v];

    cout << total << endl;
    return 0;
}
