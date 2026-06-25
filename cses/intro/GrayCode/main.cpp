/*
 * LINK: https://cses.fi/problemset/task/2205
 * NAME: Gray Code
*/

#include <bits/stdc++.h>
#include <functional>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    int n; cin >> n;

    for (int i = 0; i < (1<<n); i++) printf("%0*b\n", n, i^(i>>1));

    return 0;
}
