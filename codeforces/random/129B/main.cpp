/*
 * LINK: https://codeforces.com/problemset/problem/129/B
 * NAME: B. Students and Shoelaces
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m; cin >> n >> m;
    vector<set<ll>> graph(n+1);

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<ll> dists(n+1);
    queue<ll> qu;

    for (int i = 1; i <= n; i++)
        if (graph[i].size() == 1) qu.push(i), dists[i] = 1;

    ll lmax = 0;
    while (!qu.empty()) {
        auto i = qu.front();
        qu.pop();

        if (graph[i].empty()) continue;
        lmax = max(lmax, dists[i]);

        auto it = graph[i].begin();
        auto v = *it;
        graph[i].erase(it);
        graph[v].erase(i);

        if (!dists[v] && graph[v].size() == 1) {
            qu.push(v);
            dists[v] = dists[i]+1;
        }
    }

    cout << lmax << endl;
    return 0;
}
