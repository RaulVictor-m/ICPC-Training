/*
 * LINK: https://codeforces.com/gym/106598/problem/A
 * NAME: A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
*/

int main(void) {
    long n, q; cin >> n >> q;
    vector<array<long, 3>> v(n);

    for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1];

    v.back()[2] = 1;
    for (int i = v.size()-2; i >= 0; i--)
        if (v[i][1] == v[i+1][1]) v[i][2] = v[i+1][2]+1;
        else v[i][2] = 1;

    for (auto &[a, b, c]: v) a = -a;

    // solve
    while (q--) {
        long a, b; cin >> a >> b;
        auto it = lower_bound(v.begin(), v.end(), array<long, 3>({-a, 0, 0}));

        if (it == v.end()) {
            cout << -1 << endl;
            continue;
        }

        long i = it - v.begin();

        if (v[i][1] == b) {
            if ((i + v[i][2]) >= (n)) {
                cout << -1 << endl;
                continue;
            }

            i += v[i][2];
        }
        cout << i+1 << endl;
    }
    return 0;
}
