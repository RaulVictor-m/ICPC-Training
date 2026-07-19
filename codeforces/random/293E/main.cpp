/*
 * LINK: https://codeforces.com/problemset/problem/293/E
 * NAME: E. Close Vertices
 * STATUS: BROKEN
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> graph;
vector<bool> dead;
vector<ll> sz;
ll length, weight; 

void csz(ll v, ll p = 0) {
    sz[v] = 1;
    for (auto [u, w]: graph[v]) {
        if (u == p || dead[u]) continue;
        csz(u, v), sz[v] += sz[u];
    }
}

ll centroid(ll v, ll treesz, ll p = 0) {
    for (auto [u, w]: graph[v]) 
        if (u != p && !dead[u] && sz[u]*2 > treesz)
            return centroid(u, treesz, v);

    return v;
}

void cDist(ll v, ll p, ll we, ll len, vector<pair<ll, ll>>& dist) {
    if (we > weight || len > length) return;
    dist.emplace_back(len, we);

    for (auto [u, w]: graph[v]) {
        if (u == p || dead[u]) continue;
        cDist(u, v, we+w, len+1, dist);
    }
}


ll ans = 0;
void solve(ll v) {
    csz(v);
    ll cent = centroid(v, sz[v]);
    dead[cent] = 1;

    vector<pair<ll, ll>> tdist;
    vector<pair<ll, ll>> dist;

    // cout << cent << ": ";
    auto cmp = [](pair<ll, ll> a, pair<ll, ll> b) {
        return (b.first > a.first ||  b.second > a.second);
    };
    for (auto [u, w]: graph[cent]) {
        if (dead[u]) continue;
        cDist(u, cent, w, 1, dist);

        ans += dist.size();
        // sort(dist.begin(), dist.end(), cmp);
        // for (auto [l, w2]: dist) cout << "{" << l << " " << w2 << "} "; cout << " = " << ans <<  endl;

        for (auto [l, w2]: dist) {
            // auto it = upper_bound(tdist.begin(), tdist.end(), 
                               // pair<ll, ll>({length-l, weight-w2}), cmp);

            for (auto [l2, w3]: tdist) {
                // cout << length-l << " to " << l2 << " " << weight-w2 << " to " << w3 << endl;
                if (length-l >= l2 && weight-w2 >= w3)
                    ans++;
            }
        }

        tdist.insert(tdist.end(), dist.begin(), dist.end());
        // sort(tdist.begin(), tdist.end(), cmp);
        dist.clear();
    }
    // cout << "ans = " << ans << endl << endl;

    for (auto [u, w]: graph[cent])
        if (!dead[u]) solve(u);
}

int main(void) {
    ll n; cin >> n >> length >> weight;

    graph.resize(n+1), dead.resize(n+1), sz.resize(n+1);

    for (int i = 2; i <= n; i++) {
        ll v, w; cin >> v >> w;
        graph[i].emplace_back(v, w);
        graph[v].emplace_back(i, w);
    }

    solve(1);
    cout << ans << endl;
    return 0;
}
