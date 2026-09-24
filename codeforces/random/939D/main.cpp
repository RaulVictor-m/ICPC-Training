/*
 * LINK: https://codeforces.com/problemset/problem/939/D
 * NAME: D. Love Rescue
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
    string s1, s2; cin >> s1 >> s2;

    vector<int> par(26);
    iota(all(par), 0);
    auto find = [&](this auto& self, int v) -> int { 
        return (v == par[v] ? v : (par[v] = self(par[v])));
    };

    vector<pair<char, char>> out;

    rep(i, 0, n) {
        auto a = s1[i], b = s2[i];
        a = find(a-'a'), b = find(b-'a');

        if (a != b) out.pb({s1[i], s2[i]}), par[b] = a;
    }

    cout << out.size() << endl;
    for (auto [a, b]: out) cout << a << ' ' << b << endl;
    return 0;
}

