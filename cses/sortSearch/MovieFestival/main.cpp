/*
 * LINK: https://cses.fi/problemset/task/1629
 * NAME: Movie Festival
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        the only thing to note here is that if you sort by end time
        you know that the first movie that fits in your time is
        always the best option
*/


int main(void) {
    ll n; cin >> n;
    vector<array<ll, 2>> vals(n);

    for (auto &v: vals) cin >> v[1] >> v[0];
    sort(vals.begin(), vals.end());

    ll total = 1;
    for (int i = 0, j = 1; j < n;) {
        if (vals[j][1] >= vals[i][0]) i = j, j++, total++;
        else j++;
    }

    cout << total << endl;
    return 0;
}
