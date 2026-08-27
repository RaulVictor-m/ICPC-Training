/*
 * LINK: https://codeforces.com/gym/105904/problem/B
 * NAME: B. Bicycle in Ibirapuera
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

vector<vector<pair<int, int>>> adj;
vector<int> d(1e5+2);
bool check(vector<int> &dist, int start) {
    priority_queue<pair<int, int>> pq;
    d.assign(dist.size(), 1e9);

    d[1] = -start;
    pq.push({start, 1});

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        w = -w;
        pq.pop();

        if (v == (dist.size()-1)) return 1;
        if (d[v] < w) continue;

        for (auto [u, wu]: adj[v]) {
            if (dist[u] >= w+wu && d[u] > w+wu) {
                d[u] = w+wu;
                pq.push({-(w+wu), u});
            }
        }
    }

    return 0;
}

int32_t main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;

    adj.resize(n+1);
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<int> dist(n+1, 1e9);
    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= k; i++) {
        int v; cin >> v;
        pq.push({0, v});
        dist[v] = 0;
    }

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        w = -w;
        pq.pop();

        if (dist[v] < w) continue;

        for (auto [u, wu]: adj[v]) {
            if (dist[u] > w+wu*2) {
                dist[u] = w+wu*2;
                pq.push({-(w+wu*2), u});
            }
        }
    }

    int l = 0, r = 5e9, ans = 0;
    while (l <= r) {
        int mid = (l+r)/2;

        if (check(dist, mid)) r = mid-1, ans = mid;
        else                  l = mid+1;
    }

    cout << ans << endl;
    return 0;
}
