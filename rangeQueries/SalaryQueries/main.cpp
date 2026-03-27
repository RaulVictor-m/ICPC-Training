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
ll n, q;

ll compress1() {
   // compression
    set<ll> lset;
    unordered_map<ll, ll> lmap;
    for (ll i = 0; i < n; i++) lset.insert(sals[i]);
    for (ll i = 0; i < q; i++) {
        if (queries[i].first == '!')
            lset.insert(queries[i].second[1]);
        else {
            lset.insert(queries[i].second[1]);
            lset.insert(queries[i].second[0]);
        }
    }

    ll index = 0;
    for (auto iset: lset) lmap[iset] = index++;

    for (ll i = 0; i < n; i++) sals[i] = lmap[sals[i]];
    for (ll i = 0; i < q; i++) 
        if (queries[i].first == '!')
            queries[i].second[1] = lmap[queries[i].second[1]];
        else 
            queries[i].second[0] = lmap[queries[i].second[0]],
            queries[i].second[1] = lmap[queries[i].second[1]];

    return index;
}
ll compress2() {
    vector<ll> sorted;
    unordered_map<ll, ll> lmap;
    sorted.reserve(n+q*2);
    for (ll i = 0; i < n; i++) sorted.push_back(sals[i]);
    for (ll i = 0; i < q; i++) {
        if (queries[i].first == '!')
            sorted.push_back(queries[i].second[1]);
        else {
            sorted.push_back(queries[i].second[1]);
            sorted.push_back(queries[i].second[0]);
        }
    }

    sort(sorted.begin(), sorted.end());
    sorted.resize(unique(sorted.begin(), sorted.end()) - sorted.begin());

    ll index = 0;
    lmap.reserve(n+(q*2));
    for (auto iset: sorted) lmap[iset] = index++;

    for (ll i = 0; i < n; i++) sals[i] = lmap[sals[i]];
    for (ll i = 0; i < q; i++) 
        if (queries[i].first == '!')
            queries[i].second[1] = lmap[queries[i].second[1]];
        else 
            queries[i].second[0] = lmap[queries[i].second[0]],
            queries[i].second[1] = lmap[queries[i].second[1]];

    return index;
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

    ll index = compress2();
 
    // solve
    // cout << "aqui " << endl;
    seg::n = index;
    for (ll i = 0; i < n; i++) seg::seg[index + sals[i]]++;
    seg::build();


    // cout << "aqui 2" << endl;
    for (ll i = 0; i < q; i++) {
        if (queries[i].first == '!') {

            seg::add(sals[queries[i].second[0]-1], -1);

            sals[queries[i].second[0]-1] = queries[i].second[1];

            seg::add(queries[i].second[1], +1);

        } else {
            cout << seg::query(queries[i].second[0], queries[i].second[1]+1) << endl;
        }
    }
    // cout << "fora" << endl;

    return 0;
}
    // for (ll i = 0; i < (n+q)*2; i++) {
    //     cout << seg::seg[i] << " ";
    // }
    // cout << endl;
