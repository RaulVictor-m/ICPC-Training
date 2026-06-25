/*
 * LINK: https://www.spoj.com/LQDNTDIV/problems/NTMULMAT/?__cf_chl_tk=ekMngL7DmaGCbHNiis8DN94p6snaiCjcg1mNIyG9wuI-1773774850-1.0.1.1-sN2Clc.VoxOFopyQfpdk1i3tvkja7JWk6SRJ4a8CYIM
 * NAME: Multiply Matrixs
 * STATE: UNKNOWN
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

pair<ll, ll> l_list[101] = {};
ll dp[101][101] = {0};

ll dpRec(ll begin, ll end) /* INCLUSIVE */ {
    if (begin == end) return 0;
    if (dp[begin][end] != 0) return dp[begin][end];

    auto bm = l_list[begin];
    auto em = l_list[end];

    ll res = INT_MAX;
    for (int i = begin; i < end; i++) {

        ll right = dpRec(i+1, end);
        ll left  = dpRec(begin, i);

        res = min(res, right + left + bm.first * l_list[i].second * em.second);
    }

    return dp[begin][end] = res;
}

int main(void) {
    int n; cin >> n;

    for (int i = 1; i <= n+1; i++) {
        cin >> l_list[i-1].second;
        l_list[i].first = l_list[i-1].second;
    }

    cout << dpRec(1, n) << endl;
    return 0;
}
