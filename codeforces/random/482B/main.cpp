/*
 * LINK: https://codeforces.com/problemset/problem/482/B
 * NAME: B. Interesting Array
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
    vector<int> t(4e5+5), lz(4e5+5);

    void push(int v) {
        t[v*2] |= lz[v], t[v*2+1] |= lz[v];
        lz[v*2] |= lz[v], lz[v*2+1] |= lz[v];
        lz[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l > r) return;
        if (tl == l and tr == r)
            t[v] |= x, lz[v] |= x;
        else {
            push(v);
            int tm = (tl+tr)/2;
            update(v*2, tl, tm, l, min(tm, r), x);
            update(v*2+1, tm+1, tr, max(tm+1, l), r, x);
            t[v] = t[v*2] & t[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0x7FFFFFFF;
        if (tl == l and tr == r) return t[v];

        push(v);
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(tm, r)) &
        query(v*2+1, tm+1, tr, max(tm+1, l), r);
    }
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; cin >> n >> m;

    vector<array<ll, 3>> q(m);
    for (auto &[a, b, c]: q) cin >> a >> b >> c;

    for (auto &[a, b, c]: q)
        seg::update(1, 1, n, a, b, c);

    for (auto &[a, b, c]: q) {
        int x = seg::query(1, 1, n, a, b);
        if (x != c) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES" << endl;
    rep(i, 1, n+1)
        cout << seg::query(1, 1, n, i, i) << " ";

    return 0;
}

