/*
 * LINK: https://cses.fi/problemset/task/1687
 * NAME: Company Queries I
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

vector<vector<int>> adj;
vector<int> st, ans;
vector<vector<pair<int, int>>> q;

void dfs(int v) {
    st.pb(v);
    for (auto [k, i]: q[v]) 
        ans[i] = st[st.size()-1-k];

    for (auto u: adj[v]) dfs(u);
    st.pop_back();
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    st.resize(n+1, -1);
    adj.resize(n+1), q.resize(n+1), ans.resize(m);

    rep (i, 2, n+1) {
        int p; cin >> p;
        adj[p].pb(i);
    }

    rep (i, 0, m) {
        int a, k; cin >> a >> k;
        q[a].pb({k, i});
    }

    dfs(1);
    rep (i, 0, m) cout << ans[i] << "\n";
    return 0;
}

