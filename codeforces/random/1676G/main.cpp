/*
 * LINK: https://codeforces.com/problemset/problem/1676/G
 * NAME: G. White-Black Balanced Subtrees
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<array<ll, 2>> col; // black/white
string str;

void dfs(ll i) {
    col[i][str[i-1] == 'W']++;
    for (auto v: graph[i]) {
        dfs(v);
        col[i][0] += col[v][0], col[i][1] += col[v][1];
    }
}

int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        graph.clear(), graph.resize(n+1);
        col.clear(), col.resize(n+1);

        for (int i = 2; i <= n; i++) {
            ll v; cin >> v;
            graph[v].push_back(i);
        }
        cin >> str;

        dfs(1);
        ll count = 0;
        for (int i = 1; i <= n; i++) count += col[i][0] == col[i][1];
        cout << count << endl;
    }
    return 0;
}
