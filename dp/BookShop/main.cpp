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


int main(void) {

    return 0;
}
