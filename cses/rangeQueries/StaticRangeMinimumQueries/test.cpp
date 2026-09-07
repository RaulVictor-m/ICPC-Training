#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> vs(n), par(n);
    iota(par.begin(), par.end(), 0);

    auto find = [&par](auto&& self, int v) -> int {
        return par[v] = (v == par[v] ? v : self(self, par[v]));
    };

    for (auto &u: vs) cin >> u;

    vector<vector<pair<int, int>>> q(n);
    vector<int> ans(m);

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        q[--r].push_back({--l, i});
    }

    stack<int> st;
    for (int r = 0; r < n; r++) {
        while (!st.empty() && vs[st.top()] > vs[r])
            par[st.top()] = r, st.pop();

        st.push(r);

        for (auto [l, id]: q[r]) ans[id] = vs[find(find, l)];
    }

    for (auto u: ans) cout << u << '\n';
    return 0;
}
