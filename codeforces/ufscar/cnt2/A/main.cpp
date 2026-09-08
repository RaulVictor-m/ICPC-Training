/*
 * LINK: https://codeforces.com/group/jlSbN106ET/contest/714583/problem/A
 * NAME: A. Games on the Train
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
        vector<int> vs(n);

        for (auto &u: vs) cin >> u;
        cout << rg::max(vs) - rg::min(vs) + 1 << endl;
    }
    return 0;
}
