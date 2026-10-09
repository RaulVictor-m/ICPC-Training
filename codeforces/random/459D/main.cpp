/*
 * LINK: https://codeforces.com/problemset/problem/459/D
 * NAME: D. Pashmak and Parmida's problem
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

const int MAXN = 1e6+1;

namespace seg {
    int t[MAXN*2];
    void add(int v, int tl, int tr, int p, int x) {
        t[v] += x;
        if (tl == tr) return;
        int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;

        if (p <= tm) add(vl, tl, tm, p, x);
        else         add(vr, tm+1, tr, p, x);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l and tr == r) return t[v];

        int tm = (tl+tr)/2, vl = v+1, vr = v+(tm-tl+1)*2;

        return query(vl, tl, tm, l, min(tm, r)) +
               query(vr, tm+1, tr, max(tm+1, l), r);
    }
}

void compress(vector<int>& vs) {
    auto lset = vs;
    sort(all(lset));
    unique(all(lset));

    for (auto &v: vs)
        v = lower_bound(all(lset), v) - lset.begin();
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;

    vector<int> vs(n+1), cnt(n+1);
    rep(i, 1, n+1) cin >> vs[i];
    compress(vs);

    vector<int> jans;

    rrep(i, n, 1) 
        jans.pb(++cnt[vs[i]]), seg::add(0, 0, n, jans.back(), 1);

    cnt.assign(n+1, 0);

    ll total = 0;
    rep(i, 1, n+1) {
        seg::add(0, 0, n, jans.back(), -1), jans.pop_back();
        total += seg::query(0, 0, n, 0, cnt[vs[i]]++);
    }

    cout << total;
    return 0;
}

