/*
 * LINK: https://codeforces.com/group/jlSbN106ET/contest/714583/problem/F
 * NAME: F. The Brega Game
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;
#define N ((int)(2e5+2))

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    int vs[N], par[N];
    iota(par, par+n+1, 0);

    auto find = [&par](int v) -> int {
        while (v != par[v]) par[v] = par[par[v]], v = par[v];
        return v;
    };

    int q[N], nxt[N], head[N];

    for (int i = 1; i <= n; i++) cin >> vs[i], head[i] = -1;

    for (int i = 0, r, l; i < m; i++) {
        cin >> l >> r;
        q[i] = l, nxt[i] = head[r], head[r] = i;
    }

    bitset<N> ans;
    int st[N], top = -1;
    for (int i = 1; i <= n; i++) {
        while (top != -1 && vs[st[top]] <= vs[i])
            par[st[top--]] = i;

        st[++top] = i;

        for (int j = head[i]; j != -1; j = nxt[j]) {
            const auto l = q[j];
            ans[j] = ((i-l&1) || l == par[l] || i == find(l));
        }
    }

    for (int i = 0; i < m; i++) cout << (ans[i] ? "Adilson\n" : "Reginaldo\n");
    return 0;
}

