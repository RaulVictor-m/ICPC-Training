/*
 * LINK: https://codeforces.com/problemset/problem/330/B
 * NAME: B. Road Construction
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// there is at least 1 node that can construct to every other
// so just use as it root for the tree
// which is a STAR GRAPH

int main(void) {
    ll n, m; cin >> n >> m;

    vector<bool> vis(n+1);

    for (int i = 0; i < m*2; i++) {
        ll v; cin >> v;
        vis[v] = 1;
    }

    ll root = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }

    cout << n-1 << endl;
    for (int i = 1; i <= n; i++) {
        if (i != root) cout << root << " " << i << endl;
    }

    return 0;
}
