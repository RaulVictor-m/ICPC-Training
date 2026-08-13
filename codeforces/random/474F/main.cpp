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
    vector<Data> t(N*4);

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

    void build(int v, int tl, int tr, vector<ll>& vs) {
        if (tl == tr) {
            t[v] = {vs[tl], vs[tl], 1};
            return;
        }

        int tm = (tl+tr)/2;
        int vl = v*2, vr = v*2+1; 

        build(vl, tl, tm, vs), build(vr, tm+1, tr, vs);
        t[v] = join(t[vl], t[vr]);
    }

    Data query(int v, int tl, int tr, int l, int r) {
        if (l > r) return {0, (ll)1e10, (ll)1e10};

        if (tl == l && tr == r) return t[v];
        int tm = (tl+tr)/2;
        int vl = v*2, vr = v*2+1; 

        return join(query(vl, tl, tm, l, min(r, tm)),
                    query(vr, tm+1, tr, max(tm+1, l), r));
    }
}

int main(void) {
    int n; cin >> n;
    vector<ll> vs(n+1);

    for (int i = 1; i <= n; i++) cin >> vs[i];

    seg::build(1, 1, n, vs);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        auto v = seg::query(1, 1, n, l, r);
        if (v.gdc != v.min) cout << (r-l+1) << endl;
        else cout << (r-l+1)-v.minc << endl;
    }

    return 0;
}
