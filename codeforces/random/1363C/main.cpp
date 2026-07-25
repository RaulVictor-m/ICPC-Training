/*
 * LINK: https://codeforces.com/problemset/problem/1363/C
 * NAME: C. Game On Leaves
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> deg(n+1);

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            deg[a]++, deg[b]++;
        }

        if (deg[x] == 1 ||  n < 3)
            cout << "Ayush\n";
        else if (n&1) cout << "Ashish\n";
        else          cout << "Ayush\n";

    }

    return 0;
}
