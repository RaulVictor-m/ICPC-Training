/*
 * LINK: https://codeforces.com/problemset/problem/1098/A
 * NAME: A. Sum in the tree
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

vector<vector<int>> adj;
vector<int> s;

ll dfs(int v, ll pref) {
    if (adj[v].empty()) return max(s[v] - pref, 0LL);

    ll mn = LINF;
    if (s[v] == -1) 
        for (auto u: adj[v]) mn = min(mn, s[u]-pref);
    else mn = s[v] - pref;

    if (mn < 0) return -1;

    ll total = mn;
    for (auto u: adj[v]) {
        ll res = dfs(u, pref+mn);
        if (res == -1) return -1;
        total += res;
    }

    return total;
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;

    adj.resize(n+1), s.resize(n+1);

    rep(i, 2, n+1) {
        int p; cin >> p;
        adj[p].pb(i);
    }
    rep(i, 1, n+1) cin >> s[i];

    cout << dfs(1, 0) << endl;
    return 0;
}

