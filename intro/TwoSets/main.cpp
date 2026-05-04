/*
 * LINK: https://cses.fi/problemset/task/1092
 * NAME: Two Sets
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        sum the biggest number till the remaining is 
        smaller than the biggest, in which case you just sum
        the remaining
        and that is one sequence done, no you just take the other
        numbers for the other sequence
*/

const ll MAXN = 1e6+1;
bool used[MAXN] = {0};

int main(void) {
    ll n; cin >> n;
    ll sum = ((n*(n+1))/2);
    if (sum % 2) {
        cout << "NO" << endl;
        return 0;
    }

    sum /= 2;

    ll l_count = 0;
    for (ll i = n; i > 0; i--) {
        l_count++;
        if (sum <= i) {
            used[sum] = 1;
            break;
        }
        sum -= i; used[i] = 1;
    }

    cout << "YES" << endl;

    cout << l_count << endl;
    for (int i = n; i > 0; i--) if (used[i]) cout << i << " "; cout << endl;
    cout << n - l_count << endl;
    for (int i = n; i > 0; i--) if (!used[i]) cout << i << " "; cout << endl;

    return 0;
}
