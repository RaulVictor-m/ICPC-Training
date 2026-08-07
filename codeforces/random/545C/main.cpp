/*
 * LINK: https://codeforces.com/problemset/problem/545/C
 * NAME: C. Woodcutters
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    vector<pair<ll, ll>> vs(n);

    vs.push_back({1e10, 1e10});
    for (auto &[a, b]: vs) cin >> a >> b;

    int c = 1;
    for (int i = 1; i < n; i++) {
        if (vs[i-1].first < vs[i].first - vs[i].second) 
            c++;
        else if (vs[i].first + vs[i].second < vs[i+1].first) 
            c++, vs[i].first = vs[i].first+vs[i].second;
    }

    cout << c << endl;
    return 0;
}
