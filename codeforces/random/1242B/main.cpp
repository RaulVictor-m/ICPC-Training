/*
 * LINK: https://codeforces.com/problemset/problem/1242/B
 * NAME: B. 0-1 MST
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> par(1e5+5), vis(1e5+5);

int find(int v) {
    return par[v] = par[v] == v ? v : find(par[v]);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);
    iota(par.begin(), par.end(), 0);

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int c = 0, t = 0;
    for (int i = 1; i <= n; i = find(i)) {
        c++, par[i] = find(i+1);

        stack<int> st;
        st.push(i);

        while (!st.empty()) {
            auto v = st.top();
            st.pop();

            t++;
            for (auto u: adj[v]) vis[u] = t;

            int u = find(i);
            while (u <= n) {
                if (vis[u] != t) 
                    st.push(u), u = par[u] = find(u+1);
                else 
                    u = find(u+1);
            }
        }
    }

    cout << c-1 << endl;
    return 0;
}
