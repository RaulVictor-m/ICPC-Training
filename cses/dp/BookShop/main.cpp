/*
 * LINK: https://cses.fi/problemset/task/1158
 * NAME: Book Shop
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
    i = item
    j = price
    pr = item-price
    pa = item-pages

        dp[i][j] = max(dp[i-1][j], dp[i-1][j - pr] + pa)

    which can also be 

        dp[j] = max(dp[j], dp[j - pr] + pa)

    but keep in mind that if you do it the second way you
    have to iterate backwards since you can only pick an item once
    which means the items cannot add upon its own previous result 
    computed on the list
*/

const ll MAXX = 1e5+1;
const ll MAXN = 1e4+1;

ll prices[MAXN] = {0};
ll pages[MAXN] = {0};

ll dp[MAXX] = {0};

ll dpI(ll x, ll n) {
    for (ll i = 0; i < n; i++) {
        for (ll j = x; j >= prices[i]; j--) {
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }
    return dp[x];
}

int main(void) {
    ll n, x; cin >> n >> x;

    for (ll i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << dpI(x, n) << endl;
    return 0;
}
