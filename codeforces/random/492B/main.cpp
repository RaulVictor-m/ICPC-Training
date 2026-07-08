/*
 * LINK: https://codeforces.com/problemset/problem/492/B
 * NAME: Vanya and Lanters
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    long n; double k; cin >> n >> k;

    vector<double> vals(n);
    for (auto &v: vals) cin >> v;
    sort(vals.begin(), vals.end());

    double mdist = vals.front();
    mdist = max(mdist, (k - vals.back()));

    for (int i = 1; i < n; i++) {
        mdist = max(mdist, (vals[i] - vals[i-1])/2);
    }

    printf("%.9lf\n", mdist);
    return 0;
}
