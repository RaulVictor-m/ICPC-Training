/*
 * LINK: https://codeforces.com/problemset/problem/1336/A
 * NAME: A. Linova and Kingdom
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj(3e5);
vector<ll> ans;

int dfs(int v, int p, ll d) {
    ll sz = 1;
    for (auto u: adj[v]) 
        if (u != p) sz += dfs(u, v, d+1);

    ans[v-1] = d-sz;
    return sz;
}

int main(void) {
    int n, k; cin >> n >> k;
    ans.resize(n);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 1);
    sort(ans.begin(), ans.end(), greater<int>());

    ll t = 0;
    for (int i = 0; i < k; i++) t += ans[i];

    cout << t << endl;
    return 0;
}
