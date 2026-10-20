/*
 * LINK: https://codeforces.com/problemset/problem/546/A
 * NAME: A. Soldier and Bananas
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

    ll k, n, w; cin >> k >> n >> w;
    cout << max(w*(w+1)*k/2 - n, 0LL) << endl;
    return 0;
}

