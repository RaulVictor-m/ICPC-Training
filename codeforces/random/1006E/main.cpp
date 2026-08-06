/*
 * LINK: https://codeforces.com/problemset/problem/1006/E
 * NAME: E. Military Problem
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> ord, tin, tout;

int t = 1;
void euler(int v) {
    ord.push_back(v), tin[v] = t++;
    for (auto u: adj[v]) euler(u);
    tout[v] = t-1;
}

int main(void) {
    int n, q; cin >> n >> q;

    adj.resize(n+1), ord.resize(1), tin.resize(n+1), tout.resize(n+1);

    for (int i = 2; i <= n; i++) {
        int v; cin >> v;
        adj[v].push_back(i);
    }

    euler(1);

    while (q--) {
        int u, k; cin >> u >> k;
        if (tin[u]+k-1 <= tout[u]) 
            cout << ord[tin[u]+k-1] << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
