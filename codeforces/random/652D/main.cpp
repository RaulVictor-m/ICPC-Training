/*
 * LINK: https://codeforces.com/problemset/problem/652/D
 * NAME: D. Nested Segments
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

namespace seg {
    vector<int> t(8e5+5);

    void update(int v, int tl, int tr, int p, int x) {
        t[v] += x;
        if (tl == tr) return;

        int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;

        if (p <= tm) update(vl, tl, tm, p, x);
        else         update(vr, tm+1, tr, p, x);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l and tr == r) return t[v];

        int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;

        return query(vl, tl, tm, l, min(tm, r)) + 
        query(vr, tm+1, tr, max(l, tm+1), r);
    }
}

void compress(auto& vs) {
    vector<int> lset;
    lset.reserve(vs.size()*2);

    for (auto &[a, b, c]: vs) lset.pb(a), lset.pb(b);

    sort(all(lset));
    lset.erase(unique(all(lset)), lset.end());

    for (auto &[a, b, c]: vs) {
        a = lower_bound(all(lset), a) - lset.begin();
        b = lower_bound(all(lset), b) - lset.begin();
    }
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;

    vector<array<int, 3>> vs(n);
    rep(i, 0, n) cin >> vs[i][1] >> vs[i][0], vs[i][2] = i;
    compress(vs);

    for (auto &[a, b, c]: vs) seg::update(0, 0, n*2, b, 1);
    sort(rall(vs));

    vector<int> ans(n);
    for (auto &[a, b, c]: vs) {
        seg::update(0, 0, n*2, b, -1);
        ans[c] = seg::query(0, 0, n*2, b, n*2);
    }

    for (auto v: ans) cout << v << endl;
    return 0;
}

