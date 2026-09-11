#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; cin >> n >> m;

    vector<ll> vs(n+1);

    vector<pair<int, int>> par(n+1);
    for (int i = 1; i <= n; i++) cin >> vs[i], par[i] = {i, 0};

    auto find = [&](auto &&self, int v) -> pair<int, int> {
        if (par[v].first == v) return par[v];
        int dist = par[v].second;
        par[v] = self(self, par[v].first);
        par[v].second += dist;
        return par[v];
    };

    // vector<int> nxt(m), hd(n+1, -1), q(m);
    vector<vector<pair<int, int>>> q(n+1);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        // q[i] = l;
        // nxt[i] = hd[r];
        // hd[r] = i;
        q[r].push_back({l, i});
    }

    vector<int> ans(m);
    vector<int> st;
    for (int r = 1; r <= n; r++) {
        while (!st.empty() && vs[st.back()] < vs[r])
            par[st.back()] = {r, 1}, st.pop_back();

        st.push_back(r);

        // for (int e = hd[r]; e != -1; e = nxt[e])
        //     ans[e] = find(find, q[e]).second+1;
        for (auto [l, id]: q[r])
            ans[id] = find(find, l).second+1;
    }

    for (auto u: ans) cout << u << '\n';
    return 0;
}
