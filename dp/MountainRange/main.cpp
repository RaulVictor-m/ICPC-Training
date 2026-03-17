/*
 * LINK: https://cses.fi/problemset/task/3314
 * NAME: Mountain Range
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

    for these algorithm you basically just find the maximum in a range
    and see if there are more places to go on the range to the right
    or the range to the left by the same means(selecting the range and finding max)

    the only expection is when you encounter values that are the same
    but the way you deal with them is basically to just exclude the first from the
    result of that side, meaning you dont sum 1 to that side, imagening that in 
    its either best to take the repeated mountain side or the other side.

    since the reapeaded and the first share the middle with exactly the same result 
    for both it shouldnt matter, so you can just let the repeaded part do the middle 
    to simplify

    obs: kind hard to explain these one.
         My implementation uses a segtree with a pair of <value, index>
         so that is easier and faster to compute max values in ranges
*/

const ll MAXN = 1e5*2+1;

namespace seg {
    pair<ll, ll>seg[MAXN*2]; // value/index
    ll n;

    #define join(a, b) std::max((a), (b));

    void build() {
        for (ll i = n-1; i > 0; i--)  seg[i] = join(seg[i<<1], seg[i<<1|1]);
    }

    void update(ll pos, pair<ll, ll> val) {
        for (seg[pos += n] = val; pos > 1; pos >>= 1) 
            seg[pos>>1] = join(seg[pos], seg[pos^1]);
    }

    pair<ll, ll> query(ll l, ll r) {
        pair<ll, ll> res(0, 0);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = join(res, seg[l++]);
            if (r&1) res = join(res, seg[--r]);
        }
        return res;
    }
}

ll dpRec(ll begin, ll end) {
    if (begin == (end - 1)) return 1;
    auto bigest = seg::query(begin, end); //bigest value/index
    ll b_idx = bigest.second;

    ll right = 0;
    ll left = 0;

    if (b_idx+1 < end) {
        auto bigest_r = seg::query(b_idx+1, end);

        right = dpRec(b_idx+1, end);
        if (bigest.first != bigest_r.first) 
            right++;
    }

    if (begin < b_idx) {
        auto bigest_l = seg::query(begin, b_idx);

        left = dpRec(begin, b_idx);
        if (bigest.first != bigest_l.first) 
            left++;
    }

    return max(right, left);
}

int main(void) {
    ll n; cin >> n;
    seg::n = n;

    for (ll i = 0; i < n; i++) {
        cin >> seg::seg[n+i].first;
        seg::seg[n+i].second = i;
    }

    seg::build();

    cout << dpRec(0, n) << endl;

    return 0;
}
