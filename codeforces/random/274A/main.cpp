/*
 * LINK: https://codeforces.com/problemset/problem/274/A
 * NAME: A. k-Multiple Free Set
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k; cin >> n >> k;
    vector<ll> vs(n);

    for (auto &u: vs) cin >> u;
    sort(vs.begin(), vs.end());

    vector<ll> ans;
    for (auto &u: vs) 
        if ((u%k != 0) || (!binary_search(ans.begin(), ans.end(), u/k)))
            ans.push_back(u);

    cout << ans.size() << endl;
    return 0;
}
