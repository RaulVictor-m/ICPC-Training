/*
 * LINK: https://codeforces.com/problemset/problem/863/E
 * NAME: E. Turn Off The TV
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
    vector<int> t((2e5+2)*3*2);
    int n;
    void build(int sz) {
        n = sz;
        for (int i = n-1; i > 0; i--) t[i] = min(t[i<<1], t[i<<1|1]);
    }

    int query(int l, int r) {
        int res = INF;
        for (l += n, r += n; l < r; l>>=1, r>>=1) {
            if (r&1) res = min(res, t[--r]);
            if (l&1) res = min(res, t[l++]);
        }
        return res;
    }
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    vector<pair<int, int>> q(n);
    vector<int> lset;

    for (auto &[a, b]: q) 
        cin >> a >> b, lset.pb(a), lset.pb(b), lset.pb(b+1);

    sort(all(lset));
    lset.resize(unique(all(lset)) - lset.begin());

    for (auto &[a, b]: q) 
        a = lower_bound(all(lset), a) - lset.begin(),
        b = lower_bound(all(lset), b) - lset.begin();

    for (auto &[a, b]: q) 
        seg::t[a+lset.size()]++, seg::t[b+1+lset.size()]--;

    rep(i, 1, lset.size())
        seg::t[i+lset.size()] += seg::t[i+lset.size()-1];

    seg::build(lset.size());

    rep(i, 0, n) {
        auto [a, b] = q[i];
        int res = seg::query(a, b+1);

        if (res == 0) {
            cout << -1 << endl;
            return 0;
        }

        if (res >= 2) {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;

    return 0;
}

