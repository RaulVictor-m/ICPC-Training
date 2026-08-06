/*
 * LINK: https://codeforces.com/problemset/problem/982/C
 * NAME: C. Cut 'em all!
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;

int cut = 0;
int cutting(int v, int p) {
    int sz = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;
        int tmp = cutting(u, v);
        if (tmp%2 == 0) cut++;
        else sz += tmp;
    }
    return sz;
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1);

    for (int i = 1; i < n; i++) { 
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (n%2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    cutting(1, 0);
    cout << cut << endl;
    return 0;
}
