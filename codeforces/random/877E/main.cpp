/*
 * LINK: https://codeforces.com/problemset/problem/877/E
 * NAME: E. Danil and a Part-time Job
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

namespace seg {
    int t[N*4];
    bool mk[N*4];

    void build(int v, int tl, int tr, vector<int>& vs) {
        if (tl == tr) t[v] = vs[tl];
        else {
            int tm = (tl+tr)/2;
            build(v*2, tl, tm, vs), build(v*2+1, tm+1, tr, vs);
            t[v] =  t[v*2] + t[v*2+1];
        }
    }

    void push(int v, int l, int r) {
        if (mk[v]) {
            int m = (l+r)/2;
            t[v*2] = (m - l + 1) - t[v*2];
            t[v*2+1] = (r - m) - t[v*2+1];

            mk[v] = 0, mk[v*2] = !mk[v*2], mk[v*2+1] = !mk[v*2+1];
        }
    }

    void inv(int v, int tl, int tr, int l, int r) {
        if (l > r) return;
        if (tl == l and tr == r) {
            t[v] = (r - l + 1) - t[v];
            mk[v] = !mk[v];
        } else {
            int tm = (tl+tr)/2;
            push(v, tl, tr);
            inv(v*2, tl, tm, l, min(r, tm)), inv(v*2+1, tm+1, tr, max(l, tm+1), r);
            t[v] =  t[v*2] + t[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)  return 0;
        if (tl == l and tr == r) return t[v];

        push(v, tl, tr);
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

vector<vector<int>> graph;
vector<int> tin, tout, col;
int t = 1;

void euler(int v, int p = 0) {
    tin[v] = t++;
    for (auto u: graph[v]) if (u != p) euler(u, v);
    tout[v] = t-1;
}

int main(void) {
    int n; cin >> n;
    graph.resize(n+1), tin.resize(n+1), tout.resize(n+1);
    col.resize(n+1);

    for (int i = 2; i <= n; i++) {
        int v; cin >> v;
        graph[v].push_back(i);
    }

    euler(1);
    for (int i = 1; i <= n; i++) cin >> col[tin[i]];
    seg::build(1, 1, n, col);

    int q; cin >> q;
    while (q--) {
        string type; cin >> type;
        int v; cin >> v;
        if (type == "pow") {
            seg::inv(1, 1, n, tin[v], tout[v]);
        } else {
            cout << seg::query(1, 1, n, tin[v], tout[v]) << '\n';
        }
    }
    return 0;
}
