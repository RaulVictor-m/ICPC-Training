/*
 * LINK: https://cses.fi/problemset/task/2162
 * NAME: Josephus Problem I
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

vector<int> par(2e5+1);
int find(int v) {
    return par[v] = (par[v] == v ? v : find(par[v]));
}
int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;

    iota(all(par), 0);

    int cur = 0;
    rep(i, 0, n) {
        cur = find((find(cur)+1)%n);
        cout << cur+1 << " ";
        par[cur] = (cur+1)%n;
    }

    return 0;
}

