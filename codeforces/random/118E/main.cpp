/*
 * LINK: https://codeforces.com/problemset/problem/118/E
 * NAME: E. Bertown roads
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> adj;
vector<int> tin, low;
vector<pair<int, int>> edges;

int t = 1;
bool bridges(ll v, ll p = 0) {
   tin[v] = low[v] = t++;
 
   for (auto &[u, e]: adj[v]) {
       if (u == p) continue;
       if (tin[u]) {
           low[v] = min(low[v], tin[u]);
           edges[e] = {u, v};

       } else {
           edges[e] = {v, u};

           if (!bridges(u, v)) return false;
           low[v] = min(low[v], low[u]);
           if (low[u] > tin[v]) return false;
       }
   }
   return true;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    adj.resize(n+1), low.resize(n+1), tin.resize(n+1), edges.resize(m+1);

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }

    if (bridges(1, 0)) 
        for (int i = 1; i <= m; i++) 
            cout << edges[i].first << " " << edges[i].second << endl;
    else cout << 0 << endl;

    return 0;
}
