/*
 * LINK: https://codeforces.com/problemset/problem/1463/E
 * NAME: E. Plan of Lectures
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n, k; cin >> n >> k;
    vector<int> par(n+1), nxt(n+1), prv(n+1);

    for (int i = 1; i <= n; i++) cin >> par[i];

    bool no = 0;
    while (k-- && !no) {
        int a, b; cin >> a >> b;
        if (!nxt[a] && !prv[b]) nxt[a] = b, prv[b] = a;
        else no = 1;
    }

    if (no) {
        cout << 0 << endl;
        return 0;
    }

    // spliting components
    vector<vector<int>> comps, adj;
    vector<int> roots(n+1, -1);
    for (int i = 1; i <= n && !no; i++) {
        if (roots[i] == -1 && !prv[i]) {
            comps.push_back({});
            int c = i;
            while (c) {
                if (roots[c] != -1) {
                    no = 1;
                    break;
                }

                roots[c] = comps.size()-1;
                comps.back().push_back(c);
                c = nxt[c];
            }
        }
    }
    for (int i = 1; i <= n && !no; i++) if (roots[i] == -1) no = 1;

    if (no) {
        cout << 0 << endl;
        return 0;
    }

    // condensation graph
    vector<int> deg(comps.size());
    adj.resize(comps.size());
    for (int i = 1; i <= n; i++) {
        if (par[i] && roots[par[i]] != roots[i]) 
            adj[roots[par[i]]].push_back(roots[i]), deg[roots[i]]++;
    }

    // topsort
    queue<int> qu;
    for (int i = 0; i < deg.size(); i++)
        if (deg[i] == 0) qu.push(i);

    vector<int> tsort;
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();

        tsort.push_back(v);

        for (auto u: adj[v])
            if ((--deg[u]) == 0) qu.push(u);
    }

    if (tsort.size() < deg.size()) {
        cout << 0 << endl;
        return 0;
    }

    // final ordering
    vector<int> pos(n+1);
    int p = 0;
    for (auto v: tsort)
        for (auto u: comps[v])
            pos[u] = p++;


    // checking wrong ordering inside comps
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        ans[pos[i]] = i;
        if (pos[par[i]] > pos[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (auto u: ans) cout << u << " "; cout << endl;

    return 0;
}
