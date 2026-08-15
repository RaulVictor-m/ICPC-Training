/*
 * LINK: https://codeforces.com/problemset/problem/242/E
 * NAME: E. XOR on Segment
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+1;

namespace seg {
    ll t[N*4][20], lz[N*4];

    void apply(int v, int len, ll x) {
        for (int k = 0; k < 20; k++)
            if ((x>>k)&1) t[v][k] = len - t[v][k];
    }

    void build(int v, int tl, int tr, vector<ll>& vs) {
        if (tl == tr) {
            apply(v, 1, vs[tl]);
            return;
        }

        int tm = (tl+tr)/2;
        build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
        for (int k = 0; k < 20; k++)
            t[v][k] = t[v*2][k] + t[v*2+1][k];
    }

    void push(int v, int l, int r) {
        int tm = (l+r)/2;
        lz[v*2] ^= lz[v];
        lz[v*2+1] ^= lz[v];
        apply(v*2, tm-l+1, lz[v]);
        apply(v*2+1, r-tm, lz[v]);
        lz[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, ll x) {
        if (l > r) return;
        if (tl == l and tr == r) {
            lz[v] ^= x, apply(v, tr-tl+1, x);
            return;
        }

        push(v, tl, tr);
        int tm = (tl+tr)/2;
        update(v*2, tl, tm, l, min(r, tm), x);
        update(v*2+1, tm+1, tr, max(tm+1, l), r, x);
        for (int k = 0; k < 20; k++)
            t[v][k] = t[v*2][k] + t[v*2+1][k];
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l and tr == r) {
            ll sum = 0;
            for (int k = 0; k < 20; k++)
                sum += t[v][k]*(1<<k);
            return sum;
        }

        push(v, tl, tr);
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(tm+1, l), r);
    }

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> vs(n+1);

    for (int i = 1; i <= n; i++) cin >> vs[i];
    seg::build(1, 1, n, vs);

    int q; cin >> q;
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            cout << seg::query(1, 1, n, l, r) << '\n';
            continue;
        }

        ll x; cin >> x;
        seg::update(1, 1, n, l, r, x);
    }
    return 0;
}
