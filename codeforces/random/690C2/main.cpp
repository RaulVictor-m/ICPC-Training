/*
 * LINK: https://codeforces.com/problemset/problem/690/C2
 * NAME: C2. Brain Network (medium)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> d1, d2;

void d(int v, int p, vector<int>& dt) {
    for (auto u: adj[v]) 
        if (u != p) dt[u] = dt[v]+1, d(u, v, dt);
}

int main(void) {
    int n, m; cin >> n >> m;
    adj.resize(n+1),  d1.resize(n+1),  d2.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    d(1, 0, d1);
    int da = max_element(d1.begin(), d1.end()) - d1.begin();

    d(da, 0, d2);
    cout << (*max_element(d2.begin(), d2.end())) << endl;

    return 0;
}
