/*
 * LINK: https://codeforces.com/problemset/problem/600/E
 * NAME: E. Lomsat gelral
*/

#include <bits/stdc++.h>

using namespace std;
#define int int64_t

/*
 * Just apply small to large while merging the answers in the dfs
*/

vector<vector<int>> graph;
vector<int> col;
vector<map<int, int>> frq;
vector<int> m_frq;
vector<int> c_sum;
vector<int> ans;

void s2l(int v, int p) {
    m_frq[v] = 1;
    c_sum[v] = col[v];
    frq[v][col[v]]++;

    for (auto u: graph[v]) {
        if (u == p) continue;
        s2l(u, v);
        auto &f1 = frq[v];
        auto &f2 = frq[u];
        auto &mfrq = m_frq[v];
        auto &csum = c_sum[v];

        if (f1.size() < f2.size()) 
            swap(f1, f2), swap(mfrq, m_frq[u]), swap(csum, c_sum[u]);

        for (auto [cl, f]: f2) {
            int fq = (f1[cl] += f);

            if      (mfrq < fq)  mfrq = fq, csum = cl;
            else if (fq == mfrq) csum += cl;
        }
    }
    ans[v] = c_sum[v];
}

int32_t main(void) {
    int n; cin >> n;
    graph.resize(n+1), col.resize(n+1), frq.resize(n+1), m_frq.resize(n+1);
    c_sum.resize(n+1), ans.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> col[i];

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    s2l(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " "; cout << endl;

    return 0;
}
