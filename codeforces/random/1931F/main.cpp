/*
 * LINK: https://codeforces.com/problemset/problem/1931/F
 * NAME: F. Chat Screenshots
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<set<int>> adj; //dag
vector<int> tout; 
vector<bool> vis; 

int t = 1;
void tsort(int v) {
    vis[v] = 1;
    for (auto u: adj[v]) if (!vis[u]) tsort(u);
    tout[v] = t++;
}

int main(void) {
    int test; cin >> test;
    while (test--) {
        int n, k; cin >> n >> k;
        adj.clear(), adj.resize(n+1);
        tout.clear(), tout.resize(n+1);
        vis.clear(), vis.resize(n+1);
        t = 1;

        while (k--) {
            int l; cin >> l;
            if (n > 1) cin >> l;
            for (int i = 3; i <= n; i++) {
                int v; cin >> v;
                adj[l].insert(v), l = v;
            }
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i]) tsort(i);

        for (int v = 1; v <= n; v++)
            for (auto u: adj[v])
                if (tout[u] > tout[v]) goto no;

        cout << "YES\n"; continue;
        no: cout << "NO\n";
    }
    return 0;
}
