/*
 * LINK: https://cses.fi/problemset/task/1619
 * NAME: Restaurant Customers
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        In here i did a more complex solution
        its basically a coord compression or the times
        then i just put start value as 1 and end value as
        -1 in a prefix sum and compute the prefix at the end

        them its just a matter of finding the maximum point in the 
        prefix sum 

        however there is a much better and simpler solution i found later
        https://www.geeksforgeeks.org/dsa/cses-solutions-restaurant-customers/
*/


int main(void) {
    ll n; cin >> n;
    vector<array<ll, 2>> vals(n);

    for (auto &v: vals) cin >> v[0] >> v[1];

    // compress
    vector<ll> lset(n*2);
    for (int i = 0; i < n*2; i++) lset[i] = vals[i/2][i%2];

    sort(lset.begin(), lset.end());
    lset.resize(unique(lset.begin(), lset.end()) - lset.begin());

    unordered_map<ll, ll> lmap;
    lmap.reserve(lset.size());

    for (int i = 1; i <= lset.size(); i++) lmap[lset[i-1]] = i;
    for (auto &v: vals) v[0] = lmap[v[0]], v[1] = lmap[v[1]];

    // solve
    vector<ll> prefix((2e5+2)*2);

    for (auto &v: vals) prefix[v[0]]++, prefix[v[1]+1]--;
    for (int i = 1; i < prefix.size(); i++) prefix[i] += prefix[i-1];

    ll lmax = 0;
    for (auto v: prefix) lmax = max(lmax, v);
    cout << lmax << endl;
    return 0;
}
