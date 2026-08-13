/*
 * LINK: https://codeforces.com/problemset/problem/474/F
 * NAME: F. Ant colony
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+5;

namespace seg {
    struct Data {ll gdc, min, minc;};
    vector<Data> t(N*2);

    ll gdc(ll a, ll b) {
        return b ? gdc(b, a%b) : a;
    }

    Data join(Data a, Data b) {
        Data res;
        res.gdc = gdc(a.gdc, b.gdc);
        if (a.min < b.min) res.min = a.min, res.minc = a.minc;
        else if (a.min > b.min) res.min = b.min, res.minc = b.minc;
        else                    res.min = a.min, res.minc = b.minc+a.minc;
        return res;
    }

    void build(int n) {
        for (int i = n-1; i > 0; i--) t[i] = join(t[i<<1], t[i<<1|1]);
    }

    Data query(int l, int r, int n) {
        Data res = {0, (ll)1e10, 1};
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (l&1) res = join(res, t[l++]);
            if (r&1) res = join(res, t[--r]);
        }
        return res;
    }
}

int main(void) {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        seg::t[i+n] = {v, v, 1};
    }
    seg::build(n);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        auto v = seg::query(l-1, r, n);
        if (v.gdc != v.min) cout << (r-l+1) << endl;
        else cout << (r-l+1)-v.minc << endl;
    }

    return 0;
}

