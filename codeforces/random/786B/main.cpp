/*
 * LINK: https://codeforces.com/problemset/problem/786/B
 * NAME: B. Legacy
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

const int MAXN = 1e5+2;

namespace graph {
    const int tree1 = MAXN, tree2 = tree1+MAXN*2; //in, out
    vector<vector<pair<int, ll>>> adj(MAXN*5);
    vector<ll> dist(MAXN*5, LINF);

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            adj[v+tree1].push_back({tl, 0});
            adj[tl].push_back({v+tree2, 0});
            return;
        }

        int tm = (tl+tr)/2;
        int vl = v+1, vr = v + 2*(tm-tl+1);

        build(vl, tl, tm), build(vr, tm+1, tr);

        adj[v+tree1].push_back({vl+tree1, 0});
        adj[v+tree1].push_back({vr+tree1, 0});

        adj[vl+tree2].push_back({v+tree2, 0});
        adj[vr+tree2].push_back({v+tree2, 0});
    }

    void update(int v, int tl, int tr, int l, int r, int vrt, ll w, bool type) {
        if (l > r) return;
        if (tl == l and tr == r) {
            if (type) adj[vrt].push_back({v+tree1, w});
            else      adj[v+tree2].push_back({vrt, w});
        } else {

            int tm = (tl+tr)/2;
            int vl = v+1, vr = v + 2*(tm-tl+1);

            update(vl, tl, tm, l, min(r, tm), vrt, w, type);
            update(vr, tm+1, tr, max(l, tm+1), r, vrt, w, type);
        }
    }

}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q, s; cin >> n >> q >> s;
    graph::build(1, 1, n);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            ll v, u, w; cin >> v >> u >> w;
            graph::adj[v].push_back({u, w});
        } else if (t == 2) {
            ll v, l, r, w; cin >> v >> l >> r >> w;
            graph::update(1, 1, n, l, r, v, w, 1);
        } else {
            ll v, l, r, w; cin >> v >> l >> r >> w;
            graph::update(1, 1, n, l, r, v, w, 0);
        }
    }

    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});
    graph::dist[s] = 0;

    while (!pq.empty()) {
        using namespace graph;

        auto [w, v] = pq.top();
        w = -w;
        pq.pop();

        if (dist[v] < w) continue;

        for (auto [u, w2]: adj[v]) {
            if (dist[u] > w+w2) {
                dist[u] = w+w2;
                pq.push({-(w+w2), u});
            }
        }
    }

    rep(i, 1, n+1) 
        if (graph::dist[i] < LINF)
            cout << graph::dist[i] << " "; 
        else
            cout << "-1 "; 

    cout << endl;
    return 0;
}

