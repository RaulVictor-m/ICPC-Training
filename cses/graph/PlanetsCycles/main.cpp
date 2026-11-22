/*
 * LINK: https://cses.fi/problemset/task/1751
 * NAME: Planets Cycles
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> adj, ans, vis, deg;
void prop(int v, int t) {
    if (!vis[v]) vis[v] = 1, prop(adj[v], t+1), ans[v] = ans[adj[v]];
    else ans[v] = t;
}

void dfs(int v) {
    if (!ans[v]) dfs(adj[v]), ans[v] = ans[adj[v]]+1;
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;

    adj.resize(n+1), ans.resize(n+1), vis.resize(n+1), deg.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> adj[i], deg[adj[i]]++;

    queue<int> qu;
    for (int i = 1; i <= n; i++) 
        if (!deg[i]) qu.push(i);

    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        vis[v] = -1;

        if ((--deg[adj[v]]) == 0) qu.push(adj[v]);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) prop(i, 0);

    for (int i = 1; i <= n; i++) 
        if (vis[i] == -1) dfs(i);


    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;

    return 0;
}

