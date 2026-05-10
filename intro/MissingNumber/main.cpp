/*
 * LINK: https://cses.fi/problemset/task/1083
 * NAME: Missing Number
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

const ll MAXN = 1e5*2+1;
bool l_list[MAXN];

int main(void) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        l_list[v] = 1;
    }

    l_list[0] = 1;
    for (int i = 0; i <= n; i++) if (!l_list[i]) {
        cout << i << endl;
        return 0;
    }
    cout << endl;

    return 0;
}
