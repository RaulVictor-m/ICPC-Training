/*
 * LINK: https://codeforces.com/problemset/problem/339/D
 * NAME: D. Xenia and Bit Operations
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = (1<<17)+2;

namespace seg {
    ll t[N*4];

    ll join(ll a, ll b, bool op) {
        if (op == 1) return a|b;
        else         return a^b;
    }

    void build(int v, int tl, int tr, vector<ll> &vs, bool op) {
        if (tl == tr) t[v] = vs[tl];
        else {
            int tm = (tl+tr)/2;
            build(v*2, tl, tm, vs, !op);
            build(v*2+1, tm+1, tr, vs, !op);
            t[v] = join(t[v*2], t[v*2+1], op);
        }
    }

    void update(int v, int tl, int tr, int p, ll val, bool op) {
        if (tl == tr) t[v] = val;
        else {
            int tm = (tl+tr)/2;
            if (p <= tm) update(v*2, tl, tm, p, val, !op);
            else         update(v*2+1, tm+1, tr, p, val, !op);
            t[v] = join(t[v*2], t[v*2+1], op);
        }
    }

    ll query(int v, int tl, int tr, int l, int r, bool op) {
        if (l > r) return 0;
        if (tl == l and tr == r) return t[v];
        int tm = (tl+tr)/2;
        return join(query(v*2, tl, tm, l, min(r, tm), !op), 
        query(v*2+1, tm+1, tr, max(l, tm+1), r, !op), op);
    }
}

int main(void) {
    int n, m; cin >> n >> m;
    int rn = 1<<n;
    bool op = (n%2 == 1);

    vector<ll> vs(rn+1);

    for (int i = 1; i <= rn; i++) cin >> vs[i];
    seg::build(1, 1, rn, vs, op);

    while (m--) {
        ll a, b; cin >> a >> b;
        seg::update(1, 1, rn, a, b, op);
        cout << seg::query(1, 1, rn, 1, rn, op) << '\n';
    }
    return 0;
}
