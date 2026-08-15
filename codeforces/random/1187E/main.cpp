/*
 * LINK: https://codeforces.com/problemset/problem/1187/E
 * NAME: E. Tree Painting
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+5;

vector<vector<int>> adj(N);
vector<ll> ans(N), sz(N);

ll res = 0, trsz = 0;
void pre(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;
        pre(u, v);
        sz[v] += sz[u];
        res += ans[u];
    }
    res += sz[v];
}

void reroot(int v, int p) {
    for (auto u: adj[v]) {
        if (u == p) continue;
        ans[u] = ans[v] - sz[u] + (trsz - sz[u]);
        reroot(u, v);
    }
}

int main(void) {
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pre(1, 0);
    trsz = sz[1];
    ans[1] = res;

    reroot(1, 0);

    cout << (*max_element(ans.begin(), ans.end())) << endl;
    return 0;
}
