/*
 * LINK: https://codeforces.com/problemset/problem/1646/D
 * NAME: D. Weight the Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj;

int dfs(int v, int p, int b, vector<int>& vs) {
    int good = 0;

    if (b) vs[v] = 1; 
    else vs[v] = adj[v].size(), good = 1;

    for (auto u: adj[v]) {
        if (u == p) continue;
        good += dfs(u, v, b^1, vs);
    }

    return good;
}

int main(void) {
    int n; cin >> n;
    adj.resize(n+1);

    vector<int> v1(n+1), v2(n+1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int a1 = dfs(1, 0, 0, v1), a2 = dfs(1, 0, 1, v2);
    int s1 = accumulate(v1.begin(), v1.end(), 0);
    int s2 = accumulate(v2.begin(), v2.end(), 0);

    if (a1 < a2) swap(a1, a2), swap(s1, s2), swap(v1, v2);
    else if(a1 == a2 && s1 < s2) swap(s1, s2), swap(v1, v2);

    cout << (a1+(n==2)) << ' ' << s1 << '\n';
    for (int i = 1; i <= n; i++) cout << v1[i] << " ";
    cout << endl;
    return 0;
}
