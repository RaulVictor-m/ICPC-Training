/*
 * LINK: https://cses.fi/problemset/task/1679
 * NAME: Course Schedule
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

vector<list<ll>> graph;
vector<int> done;
vector<ll> res;

bool dfs(int i) {
    if (done[i] == 2) return true;
    if (done[i] == 1) return false;

    done[i] = 1;
    for (auto v: graph[i]) {
        if (!dfs(v)) return false;
    }

    done[i] = 2;
    res.push_back(i);
    return true;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);
    done.resize(n+1);
    done.reserve(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1; i < graph.size(); i++) {
        if (!dfs(i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (auto v: res) cout << v << " "; cout << endl;

    return 0;
}
