/*
 * LINK: https://cses.fi/problemset/task/1073
 * NAME: Towers
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    long n; cin >> n;

    multiset<long> lset;
    for (int i = 0; i < n; i++) {
        long v; cin >> v;

        auto it = lset.upper_bound(v);

        if (it != lset.end()) {
            lset.erase(it);
        }

        lset.insert(v);
    }
    cout << lset.size() << endl;
    return 0;
}
