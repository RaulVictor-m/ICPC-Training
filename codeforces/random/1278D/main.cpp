/*
 * LINK: https://codeforces.com/problemset/problem/1278/D
 * NAME: D. Segment Tree
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

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;

    vector<array<int, 3>> ps(n);
    rep(i, 0, n) cin >> ps[i][0] >> ps[i][1], ps[i][2] = i;
    sort(all(ps));

    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    auto find = [&par](this auto&& self, int v) -> int {
        return par[v] == v ? v : (par[v] = self(par[v]));
    };

    set<pair<int, int>> active;

    int cnt = 0;
    for (auto &[l, r, id]: ps) {

        while (!active.empty() && (*active.begin()).first < l)
            active.erase(active.begin());

        for (auto [jr, jid]: active)
            if (jr > r) break;
            else par[find(jid)] = find(id), cnt++;

        active.insert({r, id});
        if (cnt >= n) break;
    }

    rep(i, 0, n-1) if (find(i) != find(i+1) || cnt >= n) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" <<  endl;
    return 0;
}

