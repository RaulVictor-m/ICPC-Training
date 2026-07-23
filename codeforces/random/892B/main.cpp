/*
 * LINK: https://codeforces.com/problemset/problem/892/B
 * NAME: B. Wrath
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    vector<int> vs(n);

    for (auto &v: vs) cin >> v;
    reverse(vs.begin(), vs.end());

    int len = 0, count = 0;
    for (auto v: vs) {
        if (!len) count++; else len--;
        len = max(len, v);
    }

    cout << count << '\n';
    return 0;
}
