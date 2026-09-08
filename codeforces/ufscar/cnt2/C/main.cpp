/*
 * LINK: https://codeforces.com/group/jlSbN106ET/contest/714583/problem/C
 * NAME: C. Valeriy and Deque
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    deque<ll> vs;
    for (ll i = 0, v; i < n; i++) cin >> v, vs.push_back(v);

    vector<pair<ll, ll>> ans(n*2+2);
    for (ll i = 0; i <= n*2; i++) {
        auto a = vs[0], b = vs[1];
        vs.pop_front(), vs.pop_front();
        vs.push_front(max(a, b)), vs.push_back(min(a, b));
        ans[i] = {a, b};
    }

    while (q--) {
        ll op; cin >> op;
        if (op > vs.size()) op = (op-vs.size())%(vs.size()-1)+n;
        op--;

        cout << ans[op].first << ' ' << ans[op].second << '\n';
    }

    return 0;
}
