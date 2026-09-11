/*
 * LINK: https://codeforces.com/problemset/problem/1975/E
 * NAME:  E. Chain Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> par(n+1), col(n+1), bcnt(n+1), bfq(4);
        vector<vector<int>> adj(n+1);

        for (int i = 1; i <= n; i++) cin >> col[i];
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        [&](this auto &&self, int v) -> void {
            for (auto u: adj[v]) 
                if (u != par[v]) par[u] = v, self(u);
        }(1);

        for (int i = 1; i <= n; i++)
            if (col[i]) ++bcnt[par[i]];

        int v2 = 0;
        for (int i = 1; i <= n; i++) {
            if (col[i]) bfq[min(bcnt[i], 3)]++;
            if (col[i] && bcnt[i] == 2) v2 ^= i;
        }

        while (q--) {
            int u; cin >> u;

            if (col[u]) { 
                --bfq[min(bcnt[u], 3)];
                if (col[par[u]] && (bcnt[par[u]] == 2 || bcnt[par[u]] == 3)) 
                    v2 ^= par[u];
                col[u] = 0, bcnt[par[u]]--;

                if (col[par[u]]) 
                    bfq[min(bcnt[par[u]], 3)]++, bfq[min(bcnt[par[u]]+1, 3)]--;

                if (bcnt[u] == 2) v2 ^= u;

            } else {
                bfq[min(bcnt[u], 3)]++;
                if (col[par[u]] && (bcnt[par[u]] == 2 || bcnt[par[u]] == 1)) 
                    v2 ^= par[u];
                col[u] = 1, bcnt[par[u]]++;

                if (col[par[u]]) 
                    bfq[min(bcnt[par[u]], 3)]++, bfq[min(bcnt[par[u]]-1, 3)]--;

                if (bcnt[u] == 2) v2 ^= u;
            }

            if (bfq[0] >= 1 && bfq[2] <= 1 && bfq[0] <= bfq[2]+1 && !bfq[3] &&
                (!bfq[2] || !col[par[v2]]))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

        }

    }
    return 0;
}

