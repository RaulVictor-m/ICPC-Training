/*
 * LINK: https://cses.fi/problemset/task/1195
 * NAME: Flight Discount
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5+3;
const ll MAXM = MAXN*2;
const ll INF = LONG_LONG_MAX/3;

vector<array<ll, 2>> prices;
vector<list<array<ll, 2>>> graph;

ll dijkstra() {
                        //-cost, node, is_discounted
    priority_queue<array<ll, 3>> qu;
    qu.push({0, 1, 0});
    prices[1] = {0, 0};

    while (!qu.empty()) {
        auto [cost, i, is_disc] = qu.top();
        cost *= -1;
        qu.pop();

        if (cost > prices[i][is_disc]) continue;

        for (auto [j, c] : graph[i]) {
            if (is_disc == 0) {
                if (prices[j][0] > c+cost) {
                    prices[j][0] = c+cost;
                    qu.push({-(c+cost), j, 0});
                }

                if (prices[j][1] > ((c/2)+cost)) {
                    prices[j][1] = (c/2)+cost;
                    qu.push({-((c/2)+cost), j, 1});
                }

            } else if (prices[j][1] > c+cost) {
                    prices[j][1] = c+cost;
                    qu.push({-(c+cost), j, 1});
            }

        }
    }

    return prices.back()[1];
}

int main(void) {
    int n, m; cin >> n >> m;
    prices.resize(n+1, {INF, INF});
    graph.resize(n+1);

    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        // graph[b].push_back({a, c});
    }

    cout << dijkstra() << endl;

    return 0;
}
