/*
 * LINK: https://cses.fi/problemset/task/1202
 * NAME: Investigation
 * STATUS: BROKEN by one test case
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

vector<list<array<ll, 2>>> graph;
vector<ll> dists;
vector<ll> lcount;
vector<ll> maxf;
vector<ll> minf;
const ll INF = LONG_LONG_MAX/3;
const ll MOD = 1e9+7;

void dijkstra() {
                      // -cost, count, i, 
    priority_queue<array<ll, 3>> qu;
    qu.push({0, 0, 1});
                      //cost, count
    dists[1] = 0, lcount[1] = 1, maxf[1] = 0, minf[1] = 0;

    while(!qu.empty()) {
        auto [cost, count, i] = qu.top();
        cost*=-1;
        qu.pop();

        if (cost > dists[i]) continue;

        for (auto [v, c]: graph[i]) {
            const auto t_cost = (c+cost);

            if (t_cost == dists[v]) {
                lcount[v] = (lcount[i] + lcount[v])%MOD;
                maxf[v] = max(maxf[v], minf[i] + 1);
                minf[v] = min(minf[v], minf[i] + 1);

            } else if (t_cost < dists[v]){
                lcount[v] = lcount[i];
                maxf[v] = max(maxf[i] + 1, count+1);
                minf[v] = min(minf[i] + 1, count+1);
                dists[v] = t_cost;

                qu.push({-t_cost, count+1, v});
            }
        }
    }
}

int main(void) {
    int n, m; cin >> n >> m;

    graph.resize(n+1);
    dists.resize(n+1, INF);
    maxf.resize(n+1, -INF);
    minf.resize(n+1, INF);
    lcount.resize(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra();

    cout << dists.back() << " ";
    cout << lcount.back() << " ";
    cout << minf.back() << " ";
    cout << maxf.back() << endl;

    return 0;
}
