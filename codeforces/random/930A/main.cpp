/*
 * LINK: https://codeforces.com/problemset/problem/930/A
 * NAME: A. Peculiar apple-tree
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

    int n, v, mx = 0; cin >> n;
    vector<int> dep(n+1), cnt(n+1);

    rep(i, 2, n+1) 
        cin >> v, mx = max(mx, dep[i] = dep[v]+1), cnt[dep[i]]^=1;

    int res = 0;
    rep(i, 0, mx+1) res += cnt[i];

    cout << res+1 << endl;
    return 0;
}

