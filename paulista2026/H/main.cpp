/*
 * LINK: https://codeforces.com/gym/106598/problem/H
 * NAME: H
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
*/

int main(void) {
    long n, sum = 0; cin >> n;
    while (n--) {
        long v; cin >> v;
        sum += v;
        if (sum <= (5*60) && sum > (2*60)) sum += (3*60);
        if (sum <= (15*60) && sum > (12*60)) sum += (3*60);
    }

    cout << sum << endl;
    return 0;
}
