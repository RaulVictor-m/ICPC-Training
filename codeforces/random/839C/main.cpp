/*
 * LINK: https://codeforces.com/problemset/problem/839/C
 * NAME: C. Journey
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> d;
double ans = 0;

void dfs(int v, int p, double prob) {
    double sz = adj[v].size() - (p!=0);
    if ((int)sz == 0) ans += (d[v]*prob);

    for (auto u: adj[v]) 
        if (u != p) d[u] = d[v]+1, dfs(u, v, prob/sz);
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1), d.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 1);

    printf("%lf\n", ans);
    return 0;
}
