/*
 * LINK: https://codeforces.com/problemset/problem/1741/D
 * NAME: D. Masha and a Beautiful Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<array<ll, 2>> tree; // min, max

ll bs(ll l, ll r, ll node) {
    if (l == r) return 0;

    ll mid = (l+r)/2;

    ll left = bs(l, mid, node*2);
    ll right = bs(mid+1, r, node*2+1);

    if (left == -1 || right == -1) return -1;

    auto &tr = tree[node*2+1]; // 0: min  1: max
    auto &tl = tree[node*2];
    auto &t = tree[node];

    if (tl[1] < tr[0]) {
        t[0] = tl[0], t[1] = tr[1];
        return left+right;
    }

    if (tl[0] > tr[1]) {
        t[0] = tr[0], t[1] = tl[1];
        return left+right+1;
    }

    return -1;
}

int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll m; cin >> m;
        tree.clear(), tree.resize(m*2);

        for (int i = 0; i < m; i++) {
            cin >> tree[i+m][0];
            tree[i+m][1] = tree[i+m][0];
        }

        cout << bs(0, m-1, 1) << endl;
    }
    return 0;
}
