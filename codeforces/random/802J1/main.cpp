/*
 * LINK: https://codeforces.com/problemset/problem/802/J1
 * NAME: J1. Send the Fool Further! (easy)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<array<ll, 2>>> graph; //vertex and cost
ll dfs(ll i, ll p) {
    ll lmax = 0;

    for (auto [v, c]: graph[i]) {
        if (v == p) continue;
        lmax = max(lmax, dfs(v, i)+c);
    }

    return lmax;
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n);

    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cout << dfs(0, -1) << endl;
    return 0;
}
