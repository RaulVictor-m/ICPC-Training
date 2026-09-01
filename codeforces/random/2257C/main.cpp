/*
 * LINK: https://codeforces.com/problemset/problem/2257/C
 * NAME: C. Spying on the Beaver
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> dep(n+1);

        for (int p; auto i : rv::iota(2, n+1)) 
            cin >> p, dep[i] = dep[p]+1;

        int m; cin >> m;
        vector<int> vs(m);
        for (auto &u: vs) cin >> u;

        vs.erase(rg::min_element(vs, {}, [&](int u) {return dep[u];}));

        cout << m-1 << " ";
        for (auto &u: vs) cout << u << " "; cout << endl;

    }
    return 0;
}
