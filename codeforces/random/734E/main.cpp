/*
 * LINK: https://codeforces.com/problemset/problem/734/E
 * NAME: E. Anton and Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> d1, d2, col;

void d(int v, int p, vector<int>& dt) {
    for (auto u: adj[v]) 
        if (u != p)  dt[u] = dt[v] + (col[u]!=col[v]), d(u, v, dt);
}

int main(void) {
    int n; cin >> n;

    adj.resize(n+1), d1.resize(n+1), d2.resize(n+1), col.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> col[i];

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    d(1, 0, d1);
    int da = max_element(d1.begin(), d1.end()) - d1.begin();
    d(da, 0, d2);
    int dim = *max_element(d2.begin(), d2.end());

    cout << ((dim+1)/2) << endl;
    return 0;
}
