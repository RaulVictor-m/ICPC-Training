/*
 * LINK: https://codeforces.com/gym/106679/problem/I
 * NAME: I. Inside the Guinea Pig Playpen
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll f, n; cin >> f >> n;

    unordered_map<ll, ll> fr(1e5+1);
    vector<ll> fr_add(n+1);
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        fr[a] = i, fr_add[i] = b;
    }

    vector<vector<ll>> adj(n+1);
    vector<array<ll, 3>> queries;
    queue<pair<ll, ll>> qu;

    for (int i = 1; i <= n; i++) {
        char op; cin >> op;
        if (op == 'D') continue;
        if (op == 'A') {
            ll a, t; cin >> a >> t;

            queries.push_back({a, a+t, i});
            qu.push({i, i});
            continue;
        }

        ll dep; cin >> dep;
        adj[fr[dep]].push_back(i);
    }

    // solving dependencies
    while (!qu.empty()) {
        auto [v, p] = qu.front();
        qu.pop();
        for (auto u: adj[v])
            fr_add[p] += fr_add[u], qu.push({u, p});
    }

    // calculating
    vector<pair<ll, ll>> events;
    for (auto [in, out, v]: queries) {
        events.push_back({in, fr_add[v]});
        events.push_back({out, -fr_add[v]});
    }

    sort(events.begin(), events.end());

    ll mx = 0, cnt = 0;
    for (auto [t, v]: events)
        cnt += v, mx = max(mx, cnt);

    cout << mx << endl;
    return 0;
}
