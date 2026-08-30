/*
 * LINK: https://codeforces.com/problemset/problem/158/A
 * NAME: A. Next Round
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n, k, c = 0; cin >> n >> k;
    vector<int> vs(n);
    for (auto &v: vs) cin >> v;
    for (int i = 0; i < n; i++) {
        if (vs[i] >= vs[k-1] && vs[i]) c++;
        else break;
    }
    cout << c << endl;
    return 0;
}
