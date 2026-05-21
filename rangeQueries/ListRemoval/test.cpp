/*
 * LINK: https://cses.fi/problemset/task/1749
 * NAME: List Removals
 * STATUS: BROKEN - VARIATION
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = (1e5+2)*2;
namespace seg {
    ll seg[MAXN*2] = {0};
    ll n = 0;

    ll join(ll a, ll b) {
        return a + b;
    }

    void build(int size) {
        for (int i = n-1; i > 0; i--) seg[i] = join(seg[i<<1], seg[i<<1|1]);
    }

    void update(int p, int v) {
        for (seg[p+=n]=v; p > 1; p>>=1) seg[p>>1] = join(seg[p], seg[p^1]);
    }

    ll remove(int index) {
        int i = 1;
        while ((i<<1|1) <= 2*n) {
            cout << "from " << i << " to ";
            if (seg[i<<1] >= index) i<<=1;
            else index -= seg[i<<1], i = i<<1|1;
            cout << i << endl;
        }

        cout << " -- i: " << i << endl << endl;
        update(i-n, 0);
        return i-n;
    }

    ll query(int l, int r) {
        ll res = 0;
        for (r+=n, l+=n; l < r; r>>=1, l>>=1) {
            if (r&1) res = join(res, seg[--r]);
            if (l&1) res = join(seg[l++], res);
        }
        return res;
    }
}

int main(void) {
    ll n; cin >> n;
    vector<ll> vals(++n);

    seg::n = n;
    for (int i = 1; i < n; seg::seg[(i+n)-1] = 1, i++) cin >> vals[i];
    seg::build(n);
    for (int i = 0; i < n; i++) cout << seg::seg[i+n] << " ";cout << endl;

    for (int t = 1; t < n; t++) {
        ll i; cin >> i;

        ll l = 0, r = n, index = 0;

        index = seg::remove(i);

        // cout << vals[index] << " ";
    }
    cout << endl;

    return 0;
}
