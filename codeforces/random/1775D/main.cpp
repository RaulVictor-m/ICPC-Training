/*
 * LINK: https://codeforces.com/problemset/problem/1775/D
 * NAME: D. Friendly Spiders
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    vector<vector<int>> spider(4e5);

    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        spider[v].push_back(i);
    }

    int s, t; cin >> s >> t;

    vector<vector<int>> adj(7e5);
    vector<bool> nprime(7e5);
    const int P = 3e5+1;

    for (int i = 2; i <= 3e5; i++) {
        if (nprime[i]) continue;
        for (int j = i; j <= 3e5; j += i) {
            nprime[j] = 1;
            for (auto k: spider[j]) {
                adj[k].push_back(P+i);
                adj[P+i].push_back(k);
            }
        }
    }

    vector<int> par(7e5);
    queue<int> qu;
    qu.push(s);
    par[s] = -1;

    while (!qu.empty()) {
        auto v = qu.front(); qu.pop();
        if (v == t) goto yes;

        for (auto u: adj[v])
            if (!par[u]) par[u] = v, qu.push(u);
    }

    cout << -1 << "\n";
    return 0;

    yes:
        vector<int> ans;
        while (t != -1) {
            if (t < P) ans.push_back(t);
            t = par[t];
        }

        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for (auto v: ans) cout << v << " "; cout << "\n";
    return 0;
}
