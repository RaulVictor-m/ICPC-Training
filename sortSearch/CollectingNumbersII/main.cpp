/*
 * LINK: https://cses.fi/problemset/task/2217
 * NAME: Collecting Numbers II
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        https://www.geeksforgeeks.org/dsa/cses-solutions-collecting-numbers-ii/
*/

int main(void) {
    long n, q, res = 1; cin >> n >> q;

    vector<long> v(n+2);
    vector<long> l(n+1);
    v.back() = LONG_MAX/3;

    for (long i = 1, j; i <= n; i++) {
        cin >> j;
        v[j] = i;
        l[i] = j;
    }

    for (long i = 1; i < v.size(); i++) 
        if (v[i] < v[i-1]) res++;

    set<pair<long, long>> swaps;
    while (q--) {
        long a, b; cin >> a >> b;

        swaps.insert({l[a], l[a]+1});
        swaps.insert({l[a]-1, l[a]});
        swaps.insert({l[b], l[b]+1});
        swaps.insert({l[b]-1, l[b]});

        for (auto [sa, sb]: swaps)
            if (v[sa] > v[sb]) res--;

        swap(l[a], l[b]);
        v[l[a]] = a;
        v[l[b]] = b;

        for (auto [sa, sb]: swaps)
            if (v[sa] > v[sb]) res++;

        cout << res << endl;
        swaps.clear();
    }

    return 0;
}
