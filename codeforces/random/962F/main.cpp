/*
 * LINK: https://codeforces.com/problemset/problem/962/F
 * NAME: F. Simple Cycles Edges
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> adj(2e5);
vector<int> tin(2e5), low(2e5);
vector<bool> dead(2e5), vis(2e5);
vector<pair<int, int>> edges(2e5);

stack<int> st;

int t = 1;
void bcc(int v, int p) {
    low[v] = tin[v] = t++;
    for (auto [u, e]: adj[v]) {
        if (u == p) continue;
        if (tin[u]) {
            if (tin[u] < tin[v]) 
                low[v] = min(low[v], tin[u]), st.push(e);
        } else {
            st.push(e);
            bcc(u, v);
            low[v] = min(low[v], low[u]);

            if (low[u] >= tin[v]) {
                int top;
                int vc = 0, ec = 0;
                vector<int> cc_edges;
                do {
                    top = st.top();
                    st.pop();
                    auto [a, b] =  edges[top];

                    vc += !vis[a], vc += !vis[b];
                    vis[a] = vis[b] = 1;
                    ec++;
                    cc_edges.push_back(top);

                } while(top != e);

                for (auto e: cc_edges) {
                    auto [a, b] = edges[e];
                    vis[a] = 0, vis[b] = 0;
                    if (vc != ec) dead[e] = 1;
                }
            }
        }
    }
}



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
        edges[i] = {a, b};
    }

    for (int i = 1; i <= n; i++) if (!tin[i]) bcc(i, 0);
    cout << m - count(dead.begin(), dead.end(), 1) << endl;
    for (int i = 1; i <= m; i++) if (!dead[i]) cout << i << " "; cout << endl;

    return 0;
}
