/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/C
 * NAME: C. Cards
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5*2+2;
namespace seg {
    array<ll, 2> t[maxn*2] = {};
    int n;
    void build(int num) {
        n=num;
        for (int i = n-1; i > 0; i--) t[i] = max(t[i<<1|1], t[i<<1]);
    }

    array<ll, 2> query(int l, int r) {
        array<ll, 2> res = {};
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (l&1) res = max(res, t[l++]);
            if (r&1) res = max(t[--r], res);
        }
        return res;
    }
}

int main(void) {
    int n; cin >> n;
    vector<int> indexes(maxn, 0);
    for (int i = 0; i < n; i++) {
        cin >> seg::t[n+i][0];
        seg::t[n+i][1] = i+1;
    }
    seg::build(n);

    for (int i = 0, start = 0; i < n && start < n; i++) {
        if (indexes[seg::t[n+i][0]] > start && indexes[seg::t[n+i][0]]) {
            start = indexes[seg::t[n+i][0]], indexes[seg::t[n+i][0]] = i+1;
        }
        else indexes[seg::t[n+i][0]] = i;

        array<ll, 2> v = seg::query(start, i+1);
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}
