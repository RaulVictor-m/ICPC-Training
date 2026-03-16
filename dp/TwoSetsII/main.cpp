/*
 * LINK: https://cses.fi/problemset/task/1093
 * NAME: Two Sets II
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

        sum = 1+2+3+...+n;

        if sum is odd its impossible to have to equal sets

            dp[i][j] = dp[i-1][j - i] + dp[i-1][j];

        which is the same as

            dp[j] = dp[j-i] + dp[j] 

            obs: for these 1d matrix, you need to iterate backwards
            to avoid summing the number with itself 


        the answer at the end is going to be at
        dp[n-1][sum/2] 
        which is the same as dp[n][sum]/2
        because you can imagine the number N has to be in one of the two sets
        so if you compute all the dp for the value of the sum/2 without N
        its exactly half because the other half is going to need the number N
        to be done complete


*/
const ll MOD = 1e9 + 7;

ll dp[((500*501)/2)+2] = {0};

void dpI(ll n) {
    for (int i = 1; i <= n; i++) {
        for (int j = (i*(i+1))/2; j >= i; j--) {
            dp[j] = (dp[j - i] + dp[j]) % MOD;
        }
    }
}

int main(void) {
    ll n; cin >> n;
    ll sum = ((n*(n+1))/2);
    if (sum % 2 != 0) { cout << 0; return 0; }

    dp[0] = 1;
    dpI(n-1);
    cout <<  dp[sum/2]<< endl;

    return 0;
}
