/*
 * LINK: https://codeforces.com/problemset/problem/1905/B
 * NAME: B. Begginer's Zelda
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> deg(n+1);

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            deg[a]++, deg[b]++;
        }
        int leafs = 0;
        for (auto v: deg) leafs += (v==1);
        cout << (leafs+1)/2 << endl;
    }

    return 0;
}
