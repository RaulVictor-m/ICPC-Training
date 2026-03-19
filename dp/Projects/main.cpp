/*
 * LINK: https://cses.fi/problemset/task/1140
 * NAME: Projects
 * STATUS: DONE
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
        The key here is that only the last day matter for the dp
        so;
            dp[last_day] = max(dp[1..(first_day-1)] + project_value, dp[1..last_day]);

        so if at the end of these project it has more value them the previuos maximum value
        actived at these spot its going to be choosen

        but as the problem is given its impossible to fit in the dp
        so we coord compress the days
        them we sort by end day of projects
        and lastly to avoid the n^2 time of calculating maximum we store the dp inside a 
        segtree

*/
const ll MAXN = 1e5*2+2;
namespace seg {
    ll seg[2*3*MAXN] = {0};
    ll n;

    #define join(a, b) std::max((a), (b))

    void update(ll p, ll v) {
        for (seg[p+=n]=v; p > 1; p>>=1) seg[p>>1] = join(seg[p], seg[p^1]);
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if (r&1) res = join(res, seg[--r]);
            if (l&1) res = join(res, seg[l++]);
        }
        return res;
    }
}

array<ll, 3> l_list[MAXN] = {0};

ll dpI(ll n) {
    seg::n = (n+1)*2;

    for (ll i = 0; i < n; i++) {
        ll val = max((seg::query(0, l_list[i][1])+l_list[i][2]), seg::query(0, l_list[i][0]+1));

        seg::update(l_list[i][0], val);
    }
    return seg::query(0, l_list[n-1][0]+1);
}

int main(void) {
    ll n; cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> l_list[i][1] >> l_list[i][0] >> l_list[i][2];
    }
    // sorting
    sort(l_list, &l_list[n]);

    // compression
    set<ll> l_set;
    map<ll, ll> l_map;
    ll index = 0;

    for (ll i = 0; i < n; i++) l_set.insert({l_list[i][0], l_list[i][1]});

    for (auto v : l_set) l_map[v] = index++;

    for (ll i = 0; i < n; i++) {
        l_list[i][0] = l_map[l_list[i][0]];
        l_list[i][1] = l_map[l_list[i][1]];
    }

    cout << dpI(n) << endl;

    return 0;
}
