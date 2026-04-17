/*
 * LINK: https://cses.fi/problemset/task/1678
 * NAME: Round Trip II
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5+3;
const ll MAXM = MAXN*2;

int color[MAXN] = {0};

vector<list<int>> graph;
vector<int> answer;

int dfs(int i) {
    if (color[i] == 1) {
        answer.push_back(i);
        return i;
    }
    if (color[i] == 2) return -1;

    color[i] = 1;
    int ans = -1;
    for (auto v: graph[i]) {
        ans = dfs(v);
        if (ans != -1) {
            if (color[ans] == 1) answer.push_back(i);
            break;
        }
    }

    color[i] = 2;
    return ans;
}

int main(void) {
    int n, m; cin >> n >> m;
    graph.resize(n+1);
    answer.reserve(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    //looping through disconnected graph
    int res;
    for (int i = 1; i < graph.size(); i++) {
        if (!color[i]) {
            res = dfs(i);
            if (res != -1) break;
        }
    }

    if (res == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << answer.size() << endl;
    for (int i = answer.size()-1; i >= 0; i--) cout << answer[i] << " ";
    cout << endl;
    return 0;
}
