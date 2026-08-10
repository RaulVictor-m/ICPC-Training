/*
 * LINK: https://codeforces.com/problemset/problem/587/C
 * NAME: C. Duff in the Army
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<vector<int>> ct;

vector<array<pair<int, vector<int>>, 20>> par;
vector<int> dep;

vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> res;

    int i = 0, j = 0;
    while (res.size() < 10 && (i < a.size() || j < b.size())) {
        int av = i < a.size()? a[i]: 1e9;
        int bv = j < b.size()? b[j]: 1e9;

        if (res.size() > 0 and res.back() == min(av, bv)) res.pop_back();
        if (av < bv) i++, res.push_back(av);
        else         j++, res.push_back(bv);
    }

    return res;
}

void preLCA(int v, int p) {
    par[v][0].first = p;
    vector<int> tmp(0);
    par[v][0].second = merge(ct[v], ct[p]);

    for (int k = 1; k < 20; k++) {
        auto &[i, vs] = par[v][k];
        auto &[l_i, l_vs] = par[v][k-1];

        vs = merge(l_vs, par[l_i][k-1].second);
        i = par[l_i][k-1].first;
    }

    for (auto u: adj[v]) 
        if (u != p) dep[u] = dep[v]+1, preLCA(u, v);
}

vector<int> path(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int h = dep[b] - dep[a];

    vector<int> res = merge(ct[a], ct[b]);
    for (int k = 0; k < 20; k++)
        if ((h>>k)&1)
            res = merge(res, par[b][k].second), b = par[b][k].first;

    if (a == b) return res;

    for (int k = 19; k >= 0; k--) {
        if (par[a][k].first != par[b][k].first) {
            res = merge(res, par[a][k].second);
            res = merge(res, par[b][k].second);
            a = par[a][k].first, b = par[b][k].first;
        }
    }

    res = merge(res, par[a][0].second);
    res = merge(res, par[b][0].second);
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;

    adj.resize(n+1), ct.resize(n+1), dep.resize(n+1), par.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= m; i++) {
        int v; cin >> v;
        ct[v].push_back(i);
    }

    preLCA(1, 0);

    while (q--) {
        int v, u, a; cin >> v >> u >> a;

        auto vs = path(v, u);
        cout << min((int)vs.size(), a) << " ";
        for (int i = 0; i < min((int)vs.size(), a); i++) cout << vs[i] << " ";
        cout << endl;
    }

    return 0;
}
