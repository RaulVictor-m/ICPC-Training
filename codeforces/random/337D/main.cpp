/*
 * LINK: https://codeforces.com/problemset/problem/337/D
 * NAME: D. Book of Evil
 * STATUS: REVIEW (very poorly implemented solution)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// VERY HARD, check codeforces suggested tutorial for help

vector<vector<ll>> graph;
vector<bool> marked;
vector<ll> dDown, cdDown, dUp;
const ll INF = LONG_LONG_MAX/2;

void dfsUp(ll i, ll p, ll pp) {
    if (p == 0) {
        dUp[i] = -INF;
    }
    else {
        if ((dDown[p] == dDown[i]+1 && cdDown[p] == 1)) {
            dUp[i] = dUp[p]+1;
            // as the list is sorted
            // it maybe that {i, pp} are the first 2 positions
            // them 3 is the next
            for (int ii = 0; ii < 3 && ii < graph[p].size(); ii++) { 
                ll v = graph[p][ii];
                if (v == pp || v == i) continue;
                dUp[i] = max(dUp[i], dDown[v]+2);
            }

        } else {
            dUp[i] = max(dUp[p]+1, dDown[p]+1);
        }
    }

    if (marked[i] && dUp[i] < 0) dUp[i] = 0;

    for (auto v: graph[i]) if (v!=p) dfsUp(v, i, p);
}

void dfsDown(ll i, ll p) {
    dDown[i] = marked[i] ? 0 : -INF;

    for (auto v: graph[i]) {
        if (v == p) continue;

        dfsDown(v, i);
        if (dDown[i] < (dDown[v]+1)) {
            dDown[i] = dDown[v]+1;
            cdDown[i] = 1;
        } else if (dDown[i] == dDown[v]+1) {
            cdDown[i]++;
        }
    }

    sort (graph[i].begin(), graph[i].end(), 
            [](ll a, ll b) { return dDown[a] > dDown[b]; });
}

int main(void) {
    ll n, m, d; cin >> n >> m >> d;
    graph.resize(n+1), marked.resize(n+1);
    dDown.resize(n+1), cdDown.resize(n+1), dUp.resize(n+1);

    for (int i = 0; i < m; i++) {
        ll v; cin >> v;
        marked[v] = 1;
    }

    for (int i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfsDown(1, 0);
    dfsUp(1, 0, 0);

    ll count = 0;
    for (int i = 1; i <= n; i++) {
        if (dDown[i] <= d && dUp[i] <= d) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
