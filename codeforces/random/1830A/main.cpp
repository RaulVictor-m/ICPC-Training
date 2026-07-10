/*
 * LINK: https://codeforces.com/problemset/problem/1830/A
 * NAME: A. Copil Copac Draws Trees
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> graph; // edge, order in the list
vector<ll> scans;
vector<ll> parent;

/*
    just a simple BFS where you carry the position the edge appear in the 
    original list
    so if the edge you are going to visit, appear after its father in the 
    original list, then its going to be in the same scan
    otherwise its going to be in the next scan
*/


int main(void) {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        graph.clear(), graph.resize(n+1);
        scans.clear(), scans.resize(n+1);
        parent.clear(), parent.resize(n+1);

        for (int i = 1; i < n; i++) {
            ll a, b; cin >> a >> b;
            graph[a].push_back({b, i});
            graph[b].push_back({a, i});
        }

        scans[1] = 1;
        queue<pair<ll, ll>> qu;
        qu.push({1, 0});

        while (!qu.empty()) {
            auto [i, p] = qu.front();
            qu.pop();

            for (auto [v, pos]: graph[i]) {
                if (parent[i] == v) continue;

                if (pos > p) scans[v] = scans[i];
                else scans[v] = scans[i]+1;

                parent[v] = i;
                qu.push({v, pos});
            }
        }
        ll lmax = 0;
        for (auto v: scans) lmax = max(lmax, v);
        cout << lmax << endl;

    }
    return 0;
}
