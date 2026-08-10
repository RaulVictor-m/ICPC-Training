/*
 * LINK: https://codeforces.com/problemset/problem/1099/D
 * NAME: D. Sum in the tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<ll> vs;

ll dfs(int v, ll pref) {
    ll sum = 0;
    if (vs[v] > pref) sum += vs[v]-pref, pref = vs[v];

    if (vs[v] == -1) {
        if (adj[v].size()) {
            ll mn = 1e15;
            for (auto u: adj[v]) mn = min(vs[u], mn);

            if (mn < pref) return -1;
            sum += mn-pref, pref = mn;

        } else return 0;

    } else if (vs[v] < pref) return -1;

    for (auto u: adj[v]) {
        ll tmp = dfs(u, pref);
        if (tmp == -1) return -1;
        sum += tmp;
    }

    return sum;
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1), vs.resize(n+1);

    for (int i = 2; i <= n; i++) {
        int v; cin >> v;
        adj[v].push_back(i);
    }

    for (int i = 1; i <= n; i++) cin >> vs[i];
    cout << dfs(1, 0) << endl;

    return 0;
}
