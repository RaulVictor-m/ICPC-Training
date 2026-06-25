/*
 * LINK: https://cses.fi/problemset/task/1745
 * NAME: Money Sums
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        This is a rushed solution 
        because i think i already solved similar problems in this repo

        Ideia:
            dp[x] = max(dp[x], dp[x - item_val]);

        them you just have 1 in all the places where you can make a coin
        as the max value is 1000 just iterate through 
        count the 1s and print them
*/


int main(void) {
    int n; cin >> n;

    ll dp[100001] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        ll coin; cin >> coin;

        for (int x = 100000; x >= coin;  x--) {
            dp[x] = max(dp[x], dp[x - coin]);
        }
    }

    ll count = 0;
    for (size_t x = 1; x <= 100000; x++) count += dp[x];

    cout << count << endl;

    for (int x = 1; x <= 100000; x++) if (dp[x]) cout << x << " ";
    cout << endl;
    return 0;
}
