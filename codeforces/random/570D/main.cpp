/*
 * LINK: https://codeforces.com/problemset/problem/570/D
 * NAME: D. Tree Requests
*/

#include <bits/stdc++.h>

using namespace std;
typedef int ll;

const ll MAXN = 5e5+1;

vector<ll> graph[MAXN];
ll tin[MAXN], tout[MAXN], ht[MAXN];
vector<ll> h_list[MAXN];
vector<ll> h_pref[MAXN]; // odd amount preffix with XOR mask for letters
ll timer = 1;

void dfs(ll v, ll h = 1) {
    tin[v] = timer++;
    h_list[h].push_back(v), ht[v] = h++;

    for (auto u: graph[v]) dfs(u, h);
    tout[v] = timer++;
}

ll cmask(char c) {
    return 1<<(c-'a');
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        ll v; cin >> v;
        graph[v].push_back(i);
    }

    string str; cin >> str;

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (h_list[i].size() == 0) continue;

        h_pref[i].resize(h_list[i].size());
        h_pref[i][0] = cmask(str[h_list[i][0]-1]);

        for (int j = 1; j < h_pref[i].size(); j++) {
            char c = str[h_list[i][j]-1];
            h_pref[i][j] = cmask(c)^h_pref[i][j-1];
        }
    }

    while (m--) {
        ll v, h; cin >> v >> h;

        ll l = lower_bound(h_list[h].begin(), h_list[h].end(), v, 
                        [](ll a, ll b) { return tin[a] < tin[b]; }) - h_list[h].begin();

        ll r = upper_bound(h_list[h].begin(), h_list[h].end(), v, 
                        [](ll a, ll b) { return tout[a] < tout[b]; }) - h_list[h].begin();
        if (ht[v] > h || !r) {
            cout << "Yes\n";
            continue;
        }

        ll oddCount = 0;
        if (!l) oddCount = __builtin_popcount((unsigned)(h_pref[h][r-1]));
        else    oddCount = __builtin_popcount((unsigned)(h_pref[h][r-1]^h_pref[h][l-1]));

        // cout << oddCount << endl;
        if (oddCount > 1) cout << "No\n";
        else              cout << "Yes\n";
    }
    return 0;
}
