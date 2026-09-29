/*
 * LINK: https://codeforces.com/problemset/problem/791/A
 * NAME: A. Bear and Big Brother
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

    int a, b; cin >> a >> b;

    rep(i, 1, 100) 
        if (a*pow(3, i) > b*pow(2, i)) {
            cout << i << endl;
            break;
        }
    return 0;
}

