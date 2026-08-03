/*
 * LINK: https://codeforces.com/problemset/problem/219/D
 * NAME: D. Choosing Capital for Treeland
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, bool>>> adj;
vector<int> ans;

void reroot(int v, int p) {
    for (auto [u, e]: adj[v]) {
        if (u == p) continue;
        ans[u] = ans[v] + (e ? -1 : 1);
        reroot(u, v);
    }
}

int root(int v, int p) {
    int total = 0;
    for (auto [u, e]: adj[v])
        if (u != p) total += (int)e + root(u, v);
    return total;
}

int main(void) {
    int n; cin >> n;

    adj.resize(n+1), ans.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b, 0);
        adj[b].emplace_back(a, 1);
    }

    ans[0] = 1e6;
    ans[1] = root(1, 0);
    reroot(1, 0);

    int minc = *min_element(ans.begin(), ans.end());
    vector<int> roots;

    for (int i = 1; i < ans.size(); i++)
        if (ans[i] == minc) roots.push_back(i);
    cout << minc << '\n';

    for (auto u: roots) cout << u << ' '; cout << '\n';
    return 0;
}
