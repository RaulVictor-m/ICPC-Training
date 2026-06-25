/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/L
 * NAME: L. Loading the Dish Rack
 * STATUS: BROKEN
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n, m; cin >> n >> m;
    ll an = n;
    vector<int> ans;
    ans.reserve(n);

    ll offset = 1, step = 2, level_p = 0, t_price = 0, extra = 0;
    while (1) {
        for (int i = 0; i < ((n+1)/2) && m; i++, m--) {
            t_price += level_p;
            ans.push_back((offset+i*step));
            if (m && ((i+1)*2 > (n))) t_price += extra;
        }

        if (m > 0 && n%2 == 0) {
            extra += (level_p/2)+1;
            ans.push_back(an + 1 - extra);
            t_price += level_p+1+(extra-1);
            n--;
            m--;
        }

        if (m <= 0) break;
        if (n <= 0) break;

        step *= 2;
        offset *= 2;
        level_p = (level_p+1) * 2;
        n/=2;
    }

    cout << t_price << endl;
    // cout << ans.size() << endl;
    for (auto v: ans) cout << v << " "; cout << endl;
    return 0;
}
