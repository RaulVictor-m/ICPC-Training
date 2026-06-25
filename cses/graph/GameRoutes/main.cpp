/*
 * LINK: https://cses.fi/problemset/task/1681
 * NAME: Game Routes
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MOD = 1e9+7;
vector<list<int>> graph;
vector<ll> dists;

ll dfs(int i) {
    if (dists[i] != -1) return dists[i];
    if (i == graph.size()-1) return 1;

    dists[i] = 0;
    for (auto v: graph[i]) {
        dists[i] = (dfs(v) + dists[i]) % MOD;
    }

    return dists[i];
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);
    dists.resize(n+1, -1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    cout << dfs(1) << endl;
    return 0;
}
