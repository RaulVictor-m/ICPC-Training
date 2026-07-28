/*
 * LINK: https://codeforces.com/problemset/problem/1739/D
 * NAME: D. Reset K Edges
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> ht, v_order, hth, pref;
vector<bool> dead;

void precalc(int v, int h = 0) {
    ht[v] = h++;
    for (auto u: adj[v]) precalc(u, h);
}

void hth_ans(int v, int h) {
    if (pref.size() >= h) hth[v] = pref[pref.size()-h];
    pref.push_back(v);
    for (auto u: adj[v]) hth_ans(u, h);
    pref.pop_back();
}

void mark(int v) {
    dead[v] = 1;
    for (auto u: adj[v]) if (!dead[u]) mark(u);
}

bool cuth(int h, int k) {
    hth.clear(), hth.resize(ht.size());
    dead.clear(), dead.resize(ht.size());

    if (h == 1) iota(hth.begin(), hth.end(), 0);
    else        hth_ans(1, h-1);

    for (auto i: v_order) {
        if (dead[i] || ht[i] <= h) continue;
        if (!k) return 0;
        mark(hth[i]), k--;
    }

    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        adj.clear(),  adj.resize(n+1);
        ht.clear(), ht.resize(n+1);

        for (int i = 2; i <= n; i++) {
            int v; cin >> v;
            adj[v].push_back(i);
        }

        precalc(1);

        v_order.clear(), v_order.resize(n);
        iota(v_order.begin(), v_order.end(), 1);
        sort(v_order.begin(), v_order.end(), 
                      [](int a, int b) { return ht[a] > ht[b]; });


        int h = ht[v_order.front()];
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l+r)/2;
            if (cuth(mid, k)) h = mid, r = mid-1;
            else l = mid+1;
        }

        cout << h << '\n';
    }
    return 0;
}
