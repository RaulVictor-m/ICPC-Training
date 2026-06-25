/*
 * LINK: https://cses.fi/problemset/task/3304
 * NAME: Visible Building Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    long n, q; cin >> n >> q;

    vector<long> vals(n);
    vector<pair<long, long>> seg(n*2);
    vector<long> next_biggest(n, 0);
    vector<long> biggest_count(n, 0);

    for (auto &v: vals) cin >> v;

    // NEXT BIGGEST FINDING
    stack<pair<long, long>> st;

    st.push({vals.front(), 0}); // val, index

    for (int i = 1; i < n; i++) {
        if (st.top().first >= vals[i]) {
            st.push({vals[i], i});
            continue;
        }

        while (!st.empty() && st.top().first < vals[i]) {
            auto [v, j] = st.top();
            st.pop();

            next_biggest[j] = i - j;
        }

        st.push({vals[i], i});
    }

    while (!st.empty()) {
        auto [v, j] = st.top(); st.pop();
        next_biggest[j] = 0;
    }

    // HOW MANY BIGGEST FOWARD
    for (int i = n-1; i >= 0; i--) {
        if (next_biggest[i]) {
            biggest_count[i] = biggest_count[i+next_biggest[i]] + 1;
        }
    }

    // SEG
    for (int i = 0; i < n; i++) seg[i+n].first = vals[i], seg[i+n].second = i;
    for (int i = n-1; i > 0; i--) seg[i] = max(seg[i<<1|1], seg[i<<1]);

    // QUERIES
    while (q--) {
        long l, r; cin >> l >> r;

        long total = biggest_count[l-1];

        pair<long, long> endr = {};
        for (l+=n-1, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) endr = max(seg[--r], endr);
            if (l&1) endr = max(endr, seg[l++]);
        }

        total -= biggest_count[endr.second];

        cout << total+1 << endl;
    }

    return 0;
}
