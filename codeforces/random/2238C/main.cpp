/*
 * LINK: https://codeforces.com/problemset/problem/2238/C
 * NAME: C. Village Guilds
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<long, vector<long>>> graph;

void tsize(long i) {
    long lmax = 1;
    for (auto j: graph[i].second) {
        tsize(j);
        lmax = max(lmax, graph[j].first+1);
    }
    graph[i].first = lmax;

    sort(graph[i].second.begin(), graph[i].second.end(), 
         [](long a, long b) {
             return graph[a].first < graph[b].first;
         });
}

long ans(long i) {
    long total = 1;

    for (auto j: graph[i].second) {
        total += ans(j);
    }

    if (graph[i].second.size() > 1) {
        auto &adj = graph[i].second;
        total += graph[adj[adj.size()-2]].first;
    }

    return total;
}

int main(void) {
    long t; cin >> t;
    while (t--) {
        long n; cin >> n;

        graph.clear(), graph.resize(n);
        for (int i = 1; i < n; i++) {
            long v; cin >> v;
            graph[v-1].second.push_back(i);
        }

        tsize(0);
        cout << ans(0) << endl;
    }
    return 0;
}
