/*
 * LINK: https://codeforces.com/problemset/problem/52/C
 * NAME: C. Circular RMQ
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int N = 2e5+5;

namespace seg {
    int t[N*4], lz[N*4];

    void build(int v, int tl, int tr, vector<int>& vs) {
        if (tl == tr) {
            t[v] = vs[tl];
            return;
        }

        int tm = (tl+tr)/2;
        build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
        t[v] = min(t[v*2], t[v*2+1]);
    }

    void push(int v) {
        t[v*2] += lz[v], t[v*2+1] += lz[v];
        lz[v*2] += lz[v], lz[v*2+1] += lz[v];
        lz[v] = 0;
    }

    void add(int v, int tl, int tr, int l, int r, int x) {
        if (l > r) return;
        if (tl == l and tr == r) t[v] += x, lz[v] += x;
        else {
            push(v);
            int tm = (tl+tr)/2;
            add(v*2, tl, tm, l, min(r, tm), x);
            add(v*2+1, tm+1, tr, max(l, tm+1), r, x);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 1e9;
        if (tl == l and tr == r) return t[v];

        push(v);
        int tm = (tl+tr)/2;
        return min(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

int32_t main(void) {
    int n; cin >> n;

    vector<int> vs(n);
    for (int i = 0; i < n; i++) cin >> vs[i];

    seg::build(1, 0, n-1, vs);

    int q; cin >> q;
    string line; getline(cin, line);
    while (q--) {
        getline(cin, line);
        stringstream ss(line);

        vector<int> t;
        for (int v; ss >> v;) t.push_back(v);

        if (t.size() == 3) {
            if (t[0] > t[1]) {
                seg::add(1, 0, n-1, 0, t[1], t[2]);
                seg::add(1, 0, n-1, t[0], n-1, t[2]);
            } else {
                seg::add(1, 0, n-1, t[0], t[1], t[2]);
            }
        } else {
            if (t[0] > t[1]) {
                cout << min(seg::query(1, 0, n-1, 0, t[1]), 
                            seg::query(1, 0, n-1, t[0], n-1)) << endl;
            } else {
                cout << seg::query(1, 0, n-1, t[0], t[1]) << endl;;
            }
        }
    }
    return 0;
}
