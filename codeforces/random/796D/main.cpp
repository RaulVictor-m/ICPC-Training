/*
 * LINK: https://codeforces.com/problemset/problem/796/D
 * NAME: D. Police Stations
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, k, d; cin >> n >> k >> d;

    vector<vector<pair<ll, ll>>> graph(n+1);

    vector<ll> dist(n+1, -1);
    vector<bool> road(n+1);
    queue<ll> qu;

    for (int i = 0; i < k; i++) {
        ll v; cin >> v;
        qu.push(v);
        dist[v] = 0;
    }

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
    }

    ll count = 0;
    while (!qu.empty()) {
        ll i = qu.front();
        qu.pop();

        for (auto [v, c]: graph[i]) {
            if (dist[v] == -1 && dist[i] < d) {
                dist[v] = dist[i] + 1;
                qu.push(v);
                road[c] = 1;
                count++;
            }
        }
    }

    cout << n-1-count << endl;
    for (int i = 1; i < n; i++) 
        if (!road[i]) cout << i << " "; cout << endl;

    return 0;
}
