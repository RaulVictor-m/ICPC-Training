/*
 * LINK: https://cses.fi/problemset/task/1668/
 * NAME: Building Teams
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5+3;
const ll MAXM = MAXN*2;

vector<list<int>> graph;
int teams[MAXN] = {0};

bool bfs(int index) {
    queue<int> qu;
    qu.push(index);
    teams[index] = 1;

    while (!qu.empty()) {
        int i = qu.front();
        qu.pop();

        for (auto v: graph[i]) {
            if (teams[v] == 0) {
                qu.push(v);
                teams[v] = teams[i] ^ 0b11;
            }
            else if (teams[v] == teams[i]) return false;
        }
    }

    return true;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (teams[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << teams[i] << " ";
    cout << endl;

    return 0;
}
