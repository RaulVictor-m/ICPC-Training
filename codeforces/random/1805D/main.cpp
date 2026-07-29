/*
 * LINK: https://codeforces.com/problemset/problem/1805/D
 * NAME: D. A Wide, Wide Graph
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// find the two diameter vertices a, b
// from them calculate for every v: d_v = max(dist(v, a), dist(v, b))
// and from there you know that at every k if d_v >= k
// v is inside the main component of G_k and all the other vertices
// are single vertex components

vector<vector<int>> adj;
vector<int> d1, d2, d;

void dists(int v, int p, vector<int>& dist) {
    for (auto u: adj[v]) 
        if (u != p)
            dist[u] = dist[v] + 1, dists(u, v, dist);
}

int main(void) {
    int n; cin >> n;

    adj.resize(n+1), d.resize(n+1);
    d1.resize(n+1), d2.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dists(1, 0, d);
    int da = max_element(d.begin(), d.end()) - d.begin();
    dists(da, 0, d1);
    int db = max_element(d1.begin(), d1.end()) - d1.begin();
    dists(db, 0, d2);

    vector<int> lk(n+1), ans;
    for (int i = 1; i <= n; i++)
        d[i] = max(d1[i], d2[i]), lk[d[i]]++;

    int total = n;
    for (int i = n; i > 0; i--) {
        total-=lk[i];
        ans.push_back(total+(total!=n));
    }

    reverse(ans.begin(), ans.end());
    for (auto v: ans) cout << v << ' '; cout << '\n';

    return 0;
}
