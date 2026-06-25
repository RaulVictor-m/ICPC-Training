/*
 * LINK: https://cses.fi/problemset/task/1144
 * NAME: Salary Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        just coord compress all salaries
        and have a segtree with the size of the maximum salary possible
        them you count how many people at it salary inside the seg and print
        the query in the ranges

*/

const ll MAXN = (1e5+2)*2;
const ll MAXQ = (1e5+2)*2;

namespace seg {
    ll seg[(MAXN+(MAXQ*2))*2];
    ll n;

    void build() {
        for (ll i = n-1; i > 0; i--) seg[i] = seg[i<<1] + seg[i<<1|1];
    }

    void add(ll p, ll v) {
        for (seg[p+=n]+=v; p > 1; p >>= 1) seg[p>>1] = seg[p] + seg[p^1];
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) res += seg[--r];
            if (l&1) res += seg[l++];
        }
        return res;
    }
}

ll sals[MAXN] = {0};
pair<char, array<ll, 2>> queries[MAXQ] = {};

vector<ll> lset;
ll n, q;

ll compress() {
    lset.reserve(n+q*2);
    for (ll i = 0; i < n; i++) lset.push_back(sals[i]);
    for (ll i = 0; i < q; i++) {
        if (queries[i].first == '!')
            lset.push_back(queries[i].second[1]);
        else {
            lset.push_back(queries[i].second[1]);
            lset.push_back(queries[i].second[0]);
        }
    }

    sort(lset.begin(), lset.end());
    lset.resize(unique(lset.begin(), lset.end()) - lset.begin());

    for (ll i = 0; i < n; i++) 
        sals[i] = lower_bound(lset.begin(), lset.end(), sals[i]) - lset.begin();

    for (ll i = 0; i < q; i++) {
        auto &[c, v] = queries[i];
        if (c == '!')
            v[1] = lower_bound(lset.begin(), lset.end(), v[1]) - lset.begin();
        else 
            v[0] = lower_bound(lset.begin(), lset.end(), v[0]) - lset.begin(),
            v[1] = lower_bound(lset.begin(), lset.end(), v[1]) - lset.begin();
    }

    return lset.size();
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // input 
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
        cin >> sals[i];

    for (ll i = 0; i < q; i++)
        cin >> queries[i].first >> queries[i].second[0] >> queries[i].second[1];

    ll index = compress();
 
    // solve
    seg::n = index;
    for (ll i = 0; i < n; i++) seg::seg[index + sals[i]]++;
    seg::build();

    for (ll i = 0; i < q; i++) {
        if (queries[i].first == '!') {

            seg::add(sals[queries[i].second[0]-1], -1);

            sals[queries[i].second[0]-1] = queries[i].second[1];

            seg::add(queries[i].second[1], +1);

        } else {
            cout << seg::query(queries[i].second[0], queries[i].second[1]+1) << endl;
        }
    }
    std::quick_exit(0);

    return 0;
}
