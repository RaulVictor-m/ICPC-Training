/*
 * LINK: https://codeforces.com/problemset/problem/1702/G2
 * NAME: G2. Passable Paths (hard version)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<array<int, 20>> par;
vector<int> ht;

void prelca(int v, int p, int h) {
    par[v][0] = p, ht[v] = h++;
    for (int k = 1; k < 20; k++) par[v][k] = par[par[v][k-1]][k-1];

    for (auto u: adj[v]) if (u != p) prelca(u, v, h);
}

int lca(int a, int b) {
    if (ht[a] > ht[b]) swap(a, b);
    int h = ht[b] - ht[a];

    for (int k = 0; k < 20; k++)
        if ((h>>k)&1) b = par[b][k];

    if (a == b) return a;

    for (int k = 19; k >= 0; k--)
        if (par[a][k] != par[b][k])
            a = par[a][k], b = par[b][k];

    return par[a][0];
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1), par.resize(n+1), ht.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    prelca(1, 0, 0);
    int q; cin >> q;

    vector<int> vs;
    vector<bool> marked(n+1);
    while (q--) {
        int k; cin >> k;

        vs.resize(k);
        for (auto &v: vs) cin >> v;
        sort(vs.begin(), vs.end(), [](int a, int b) {return ht[a] > ht[b];});

        for (auto v: vs)
            if (lca(vs.front(), v) == v) marked[v] = 1;

        int s = -1;
        for (int i = 0; i < k; i++) 
            if (!marked[vs[i]]) {
                s = i;
                break;
            }

        if (s == -1) {
            cout << "Yes\n";
            for (auto v: vs) marked[v] = 0;
            continue;
        }

        for (int i = s; i < k; i++) 
            if (lca(vs[s], vs[i]) == vs[i]) marked[vs[i]] = 1;

        int count = 0;
        for (auto v: vs)
            count += marked[v], marked[v] = 0;

        if (count == k and ht[lca(vs[s], vs[0])] <= ht[vs[k-1]]) 
            cout << "Yes\n";
        else            
            cout << "No\n";
    }

    return 0;
}
