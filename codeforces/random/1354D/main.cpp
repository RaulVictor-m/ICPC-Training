/*
 * LINK: https://codeforces.com/problemset/problem/1354/D
 * NAME: D. Multiset
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

const int MAXN = 1e6;

namespace seg {
    int t[MAXN*2] = {};

    void add(int v, int tl, int tr, int p) {
        t[v]++;
        if (tl == tr) return;

        int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;

        if (p <= tm) add(vl, tl, tm, p);
        else         add(vr, tm+1, tr, p);
    }

    int rem(int v, int tl, int tr, int x) {
        t[v]--;
        if (tl == tr) return tl;

        int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;

        if (x <= t[vl])  return rem(vl, tl, tm, x);
        else             return rem(vr, tm+1, tr, x-t[vl]);
    }
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;

    rep(i, 0, n+q) {
        int v; cin >> v;
        if (v > 0) seg::add(0, 1, n, v);
        else       seg::rem(0, 1, n, -v);
    }

    if (seg::t[0] > 0) cout << seg::rem(0, 1, n, 1);
    else               cout << 0;
    return 0;
}

