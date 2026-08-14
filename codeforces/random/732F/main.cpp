/*
 * LINK: https://codeforces.com/problemset/problem/732/F
 * NAME: F. Tourist Reform
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 4e5+5;

vector<vector<pair<int, int>>> adj(N), cadj(N);
vector<bool> dead(N);
vector<pair<int, int>> ed(N);
vector<int> dlst, tin(N), low(N), comp(N), compSZ(N);

stack<int> st;
int t = 1, cp = 1;
void bridge(int v, int p) {
    tin[v] = low[v] = t++;
    st.push(v);

    for (auto [u, e]: adj[v]) {
        if (u == p) continue;
        if (tin[u]) {
            ed[e] = {u, v};
            low[v] = min(low[v], tin[u]);
        } else {
            ed[e] = {v, u};
            bridge(u, v);
            low[v] = min(low[u], low[v]);
            if (low[u] > tin[v]) dead[e] = 1, dlst.push_back(e);
        }
    }

    if (tin[v] == low[v]) {
        int top, sz = 0;
        do {
            top = st.top();
            st.pop();

            comp[top] = cp;
            sz++;
        } while (top != v);

        compSZ[cp++] = sz;
    }
}

void dirDead(int v, int p) {
    for (auto [u, e]: cadj[v]) {
        if (u == p) continue;
        if (comp[ed[e].first] == v) swap(ed[e].first, ed[e].second);
        dirDead(u, v);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        ed[i] = {a, b};
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }

    bridge(1, 0);

    for (auto e: dlst) {
        auto [a, b] = ed[e];
        if (comp[a] != comp[b]) {
            cadj[comp[a]].emplace_back(comp[b], e);
            cadj[comp[b]].emplace_back(comp[a], e);
        }
    }

    int big_comp = max_element(compSZ.begin(), compSZ.end()) - compSZ.begin();

    cout << compSZ[big_comp] << endl;
    // for (int i = 1; i <= n; i++) cout << comp[i] << " "; cout << endl;
    // for (auto e: dlst) cout << ed[e].first << " " << ed[e].second << endl;

    dirDead(big_comp, 0);
    for (int i = 1; i <= m; i++) cout << ed[i].first << " " << ed[i].second << endl;
    return 0;
}
