/*
 * LINK: https://codeforces.com/problemset/problem/580/B
 * NAME: B. Kefa and Company
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// after sorting based on money, its a subsegment

int main(void) {
    ll n, d; cin >> n >> d;

    vector<pair<ll, ll>> vs(n);
    for (auto &[a, b]: vs) cin >> a >> b;

    sort(vs.begin(), vs.end());

    ll i = 1, j = 0, csum = vs.front().second, msum = vs.front().second;
    while (i < vs.size()) {
        if (vs[i].first - d < vs[j].first)
            csum += vs[i++].second;
        else
            csum -= vs[j++].second;

        msum = max(csum, msum);
    }

    cout << msum << endl;
    return 0;
}
