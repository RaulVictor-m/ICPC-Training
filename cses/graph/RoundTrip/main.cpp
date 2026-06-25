/*
 * LINK: https://cses.fi/problemset/task/1669
 * NAME: Round Trip
 * STATUS: DONE -- REVIEW
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5+3;
const ll MAXM = MAXN*2;

int parent[MAXN] = {0};
int l_count[MAXN] = {0};
vector<list<int>> graph;
deque<int> response;

void fill_res(int a, int b) {
    for (int i = a; i != -1; i = parent[i]) response.push_front(i);
    for (int i = b; i != -1; i = parent[i]) response.push_back(i);
}

int bfs(int index) {
    queue<int> qu;
    qu.push(index);
    l_count[index] = 0;
    parent[index] = -1;

    while (!qu.empty()) {
        int i = qu.front();
        qu.pop();

        for (auto v: graph[i]) {
            if (!parent[v]) {
                qu.push(v);
                l_count[v] = l_count[i] + 1;
                parent[v] = i;
            } else {
                if (v != parent[i] && (l_count[v] + l_count[i]) >= 2) {
                    fill_res(i, v);
                    return l_count[v] + l_count[i];
                }
            }
        }
    }
    return -1;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //looping through disconnected graph
    int res;
    for (int i = 1; i < graph.size(); i++) {
        if (!l_count[i]) {
            res = bfs(i);
            if (res != -1) break;
        }
    }

    if (res == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // finding the inner cycle in the graph response cycle
    for (;response.size() >= 6 && response[1] == response[response.size()-2]; 
        response.pop_back(), response.pop_front());

    cout << response.size() << endl;

    for (auto v: response) {
        cout << v << " ";
    }

    cout << endl;

    return 0;
}
