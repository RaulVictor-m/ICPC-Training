/*
 * LINK: https://cses.fi/problemset/task/1652
 * NAME: Forest Queries
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        so a basically just compute a prefix of how many tree there are 
        from (1, 1) to (x, y) being 0 < x,y <= n;

        the way to do it, is just a matrix
        where prefix[i][j] = (prefix[i-1][j] + prefix[i][j-1]) which basically
        sum the 2 rectangles (top and behind)
        however this way they would have an overlaping square prefix[i-1][j-1]
        which is removed

        prefix[i][j] = (prefix[i-1][j] + prefix[i][j-1]) - prefix[i-1][j-1];

        them to answer the queries

        we just do a similar process
        we just take the prefix[i][j] and them subtract the rectangles on top and behind
        but sum up the overlap back on so that it isnt subtracted twice
        answer = ((prefix[c][d] - prefix[a-1][d]) - prefix[c][b-1]) + prefix[a-1][b-1];

        used abcd instead of x1, x2, y1, y2, because I am using matrix representation
        so you could think of it as prefix[y][x], which is the inverse of the convention
        and thus can be misleading

*/
const ll MAXN = 1e3+1;

ll prefix[MAXN][MAXN] = {0};

int main(void) {
    ll n, q; cin >> n >> q;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            char c; cin >> c;                                   /*overlap*/
            prefix[i][j] = (prefix[i-1][j] + prefix[i][j-1]) - prefix[i-1][j-1];
            if (c == '*') prefix[i][j]++;
        }
    }

    for (ll i = 0; i < q; i++) {
        ll a, b, c, d; cin >> a >> b >> c >> d;                         /*overlap*/
        ll res = ((prefix[c][d] - prefix[a-1][d]) - prefix[c][b-1]) + prefix[a-1][b-1];
        cout << res << endl;
    }

    return 0;
}
