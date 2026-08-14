/*
 * LINK: https://codeforces.com/problemset/problem/915/E
 * NAME: E. Physical Education Lessons
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3e5+5;

namespace seg {
    ll t[N*4], s[N*4];
    bool mk[N*4], lz[N*4];

    void build(int v, int tl, int tr, vector<ll>& vs) {
        if (tl == tr) {
            t[v] = s[v] = vs[tl];
            return;
        }

        int tm = (tl+tr)/2, vl = v+1, vr = v + (tm-tl+1)*2;

        build(vl, tl, tm, vs), build(vr, tm+1, tr, vs);
        s[v] = t[v] = t[vl]+t[vr];
    }

    inline void push(int v, int vl, int vr) {
        if (mk[v]) {
            t[vl] = lz[v] ? s[vl] : 0;
            t[vr] = lz[v] ? s[vr] : 0;

            mk[vl] = mk[vr] = 1;
            lz[vl] = lz[vr] = lz[v];
            mk[v] = 0;
        }
    }

    void inv(int v, int tl, int tr, int l, int r, bool f) {
        if (l > r) return;
        if (tl == l and tr == r) {
            t[v] = f ? s[v] : 0;
            mk[v] = 1, lz[v] = f;
            return;
        }

        int tm = (tl+tr)/2, vl = v+1, vr = v + (tm-tl+1)*2;
        push(v, vl, vr);
        inv(vl, tl, tm, l, min(r, tm), f); 
        inv(vr, tm+1, tr, max(l, tm+1), r, f);
        t[v] = t[vl]+t[vr];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q; cin >> n >> q;

    vector<ll> lset;
    lset.reserve(q*2+2);
    vector<array<ll, 3>> queries(q);

    lset.push_back(1);
    lset.push_back(n+1);
    for (auto &[l, r, k]: queries) {
        cin >> l >> r >> k;
        lset.push_back(l);
        lset.push_back(r+1);
    }

    // compression
    sort(lset.begin(), lset.end());
    lset.resize(unique(lset.begin(), lset.end())-lset.begin());

    for (auto &[l, r, k]: queries) {
        l = lower_bound(lset.begin(), lset.end(), l) - lset.begin();
        r = lower_bound(lset.begin(), lset.end(), r+1) - lset.begin();
    }

    // values
    vector<ll> vs(lset.size()-1);
    for (int i = 0; i < lset.size()-1; i++) {
        vs[i] = (lset[i+1]) - lset[i];
    }

    int lst = vs.size()-1;
    seg::build(1, 0, lst, vs);

    for (auto &[l, r, k]: queries) {
        seg::inv(1, 0, lst, l, r-1, k==2);
        cout << seg::t[1] << endl;
    }
    return 0;
}
