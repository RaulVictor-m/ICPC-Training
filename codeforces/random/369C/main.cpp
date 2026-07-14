/*
 * LINK: https://codeforces.com/problemset/problem/369/C
 * NAME: C. Valera and Elections
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, bool>>> graph;
vector<ll> ans;

void dfs(ll i, ll p, bool mark) {
    ll size = ans.size();

    for (auto [v, m]: graph[i]) {
        if (v == p) continue;
        dfs(v, i, m);
    }

    if (mark && ans.size() == size)
        ans.push_back(i);
}

int main(void) {
    ll n; cin >> n;
    graph.resize(n+1);

    for (int i = 1; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c==2});
        graph[b].push_back({a, c==2});
    }

    dfs(1, 0, 0);
    cout << ans.size() << endl;
    for (auto v: ans) cout << v << " "; cout << endl;

    return 0;
}
