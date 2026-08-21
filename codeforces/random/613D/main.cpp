/*
 * LINK: https://codeforces.com/problemset/problem/613/D
 * NAME: D. Kingdom and its Cities
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+1;

vector<vector<int>> adj(N);
vector<array<int, 20>> par(N);
vector<int> tin(N), tout(N);
vector<bool> mark(N);

int t = 1;
void pre(int v, int p) {
    for (int k = 1; k < 20; k++) 
        par[v][k] = par[par[v][k-1]][k-1];
    tin[v] = t++;
    for (auto u: adj[v])
        if (u != p) par[u][0] = v, pre(u, v);
    tout[v] = t-1;
}

int lca(int a, int b) {
    if (tin[a] > tin[b]) swap(a, b);
    if (tout[b] <= tout[a]) return a;

    for (int k = 19; k >= 0; k--)
        if (tout[b] > tout[par[a][k]]) a = par[a][k];

    return a = par[a][0];
}

pair<int, bool> solve(int v) {
    int res = 0;
    int child = 0;
    for (auto u: adj[v]) {
        auto [r, m] = solve(u);
        res += r;
        if (m) child++;
    }

    if (mark[v]) return {res+child, 1};
    else if (child > 1) return {res+1, false};

    return {res, child == 1};
}

int main(void) {
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pre(1, 0);
    tout[0] = 1e9;

    int q; cin >> q;

    adj.clear();
    adj.resize(n+1);
    vector<int> vs(n);

    while (q--) {
        int k; cin >> k;
        vs.resize(k);
        for (auto &u: vs) {
            cin >> u;
            mark[u] = 1;
        }

        sort(vs.begin(), vs.end(), [](int a, int b) {return tin[a] < tin[b];});

        int sz = vs.size();
        bool no = false;
        for (auto &u: vs) if (mark[par[u][0]]) no = true;
        if (no) {
            for (auto &u: vs) mark[u] = 0;
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < sz-1; i++)
            vs.push_back(lca(vs[i], vs[i+1]));


        sort(vs.begin(), vs.end(), [](int a, int b) {return tin[a] < tin[b];});
        vs.resize(unique(vs.begin(), vs.end()) - vs.begin());

        stack<int> st;
        st.push(vs.front());

        for (int i = 1; i < vs.size();i++) {
            while (tout[st.top()] < tin[vs[i]]) st.pop();
            adj[st.top()].push_back(vs[i]);
            st.push(vs[i]);
        }
        cout << solve(vs.front()).first << endl;

        for (auto u: vs) {
            if (!adj.empty()) adj[u].clear();
            mark[u] = 0;
        }
    }
    return 0;
}
