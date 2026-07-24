/*
 * LINK: https://codeforces.com/problemset/problem/1131/F
 * NAME: F. Asya And Kittens
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// small to large with dsu to merge the components

namespace dsu {
    vector<int> par;
    vector<vector<int>> lst;

    void build(int n) {
        par.resize(n+1), lst.resize(n+1);
        for (int i = 1; i < par.size(); i++) par[i] = i, lst[i].push_back(i);
    }

    int find(int i) {
        return par[i] == i ? i : find(par[i]);
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (lst[a].size() < lst[b].size()) swap(a, b);

        par[b] = a;
        lst[a].insert(lst[a].end(), lst[b].begin(), lst[b].end());
    }
}

int main(void) {
    int n; cin >> n;
    dsu::build(n);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        dsu::join(a, b);
    }

    for (auto v: dsu::lst[dsu::find(1)])
        cout << v << " "; cout << endl;

    return 0;
}
