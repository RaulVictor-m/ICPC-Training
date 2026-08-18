/*
 * LINK: https://codeforces.com/problemset/problem/891/C
 * NAME: C. Envy
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+5;

namespace uf {
    ll par[N], sz[N];
    vector<pair<int, ll>> hpar;
    vector<pair<int, ll>> hsz;
    void build(int n) {
        for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    }

    int find(int v) {
        return (par[v] == v ? v : find(par[v]));
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);

        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);

        hpar.push_back({b, par[b]});
        hsz.push_back({a, sz[a]});

        sz[a] += sz[b], par[b] = a;
        return true;
    }

    int snap() {
        return hpar.size();
    }

    void rollback(int snap) {
        while (snap < hpar.size()) {
            sz[hsz.back().first] = hsz.back().second;
            par[hpar.back().first] = hpar.back().second;
            hpar.pop_back();
            hsz.pop_back();
        }
    }
}

vector<array<ll, 3>> ed(N);
vector<bool> alive(N);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    uf::build(n);
    map<ll, vector<pair<int, int>>> graph;

    for (int i = 1; i <= m; i++) {
        auto &[w, a, b] = ed[i];
        cin >> a >> b >> w;

        graph[w].push_back({a, b});
    }


    int q; cin >> q;
    map<ll, vector<pair<int, vector<int>>>> queries;
    for (int id = 1; id <= q; id++) {
        int k; cin >> k;
        map<ll, vector<int>> c_ed;
        while (k--) {
            int e; cin >> e;
            auto &[w, a, b] = ed[e];
            c_ed[w].push_back(e);
        }

        for (auto &[w, lst]: c_ed) 
            queries[w].push_back({id, lst});
    }

    vector<bool> ans(q+1, 1);
    for (auto &[w, lst]: graph) {

        for (auto &[id, lst]: queries[w]) {
            int snap = uf::snap();
            for (auto e: lst) {
                if (!uf::join(ed[e][1], ed[e][2])) {
                    ans[id] = 0;
                    break;
                }
            }
            uf::rollback(snap);
        }

        for (auto &[a, b]: lst) uf::join(a, b);
    }

    for (int i = 1; i <= q; i++) 
        if(ans[i]) cout << "YES\n";
        else       cout << "NO\n";

    return 0;
}
