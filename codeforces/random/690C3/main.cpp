/*
 * LINK: https://codeforces.com/problemset/problem/690/C3
 * NAME: C3. Brain Network (hard)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> ht;
vector<array<int, 20>> par;

int dist(int a, int b) {
    if (ht[a] > ht[b]) swap(a, b);
    int h = ht[b] - ht[a];

    for (int k = 0; k < 20; k++)
        if ((h>>k)&1) b = par[b][k];

    if (a == b) return h;

    int h0 = ht[a];

    for (int k = 19; k >= 0; k--)
        if (par[a][k] != par[b][k])
            a = par[a][k], b = par[b][k];

    return h + (h0 - ht[par[a][0]])*2;
}

int main(void) {
    int n; cin >> n;

    ht.resize(n+1), par.resize(n+1);

    int da = 1, db = 1, ans = 0;
    for (int i = 2; i <= n; i++) {
        cin >> par[i][0];

        ht[i] = ht[par[i][0]] + 1;
        for (int k = 1; k < 20; k++) par[i][k] = par[par[i][k-1]][k-1];

        int da2i = dist(da, i), db2i = dist(db, i);

        if (da2i < db2i) swap(da2i, db2i), swap(da, db);

        if (da2i > ans) db = i, ans = da2i;
        cout << ans << endl;
    }
    return 0;
}
