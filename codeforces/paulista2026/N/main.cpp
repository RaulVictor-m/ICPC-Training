/*
 * LINK: https://codeforces.com/gym/106598/problem/N
 * NAME: N
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
*/

int main(void) {
    long n; cin >> n;

    vector<long> vb(n+2), va;
    va.reserve(n);

    for (auto &v: vb) cin >> v;
    sort(vb.begin(), vb.end(), greater<long>());

    long s = vb.front(), m = 0;
    if (n == 1) {
        cout << s << " " << s << endl << s << endl;
        return 0;
    }

    long sum = 0;
    for (int i = 1; i < n; i++) {
        va.push_back(s - vb[i]);
        sum += (s - vb[i]);
    }

    m = s-sum;
    va.push_back(m);

    cout << s << " " << m << endl;
    for (auto v: va) cout << v << " "; cout << endl;
    return 0;
}
