/*
 * LINK: https://codeforces.com/problemset/problem/321/C
 * NAME: C. Ciel the Commander
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
vector<ll> sz;
vector<char> letters;
vector<bool> dead;

void csize(ll i, ll p = 0) {
    sz[i] = 1;
    for (auto v: graph[i]) {
        if (p == v || dead[v]) continue;
        csize(v, i), sz[i] += sz[v];
    }
}

ll decomp(ll i, ll treesz, ll p = 0) {
    for (auto v: graph[i]) 
        if (p != v && !dead[v] && sz[v]*2 > treesz) 
            return decomp(v, treesz, i);
    return i;
}

void solve(ll i, ll let = 'A') {
    csize(i);
    ll cent = decomp(i, sz[i]);
    letters[cent] = let;
    dead[cent] = 1;

    for (auto v: graph[cent])
        if (!dead[v]) solve(v, let+1);
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1), letters.resize(n+1), sz.resize(n+1), dead.resize(n+1);

    for (ll i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1);
    for (int i = 1; i <= n; i++) cout << letters[i] << " "; cout << endl;

    return 0;
}
