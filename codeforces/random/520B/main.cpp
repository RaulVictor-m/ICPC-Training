/*
 * LINK: https://codeforces.com/problemset/problem/520/B
 * NAME: B. Two Buttons
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
ll mem[(ll)1e5] = {0};
ll vis[(ll)1e5] = {0};

ll dp(ll n) {
    if (n == m) return 0;
    if (mem[n]) return mem[n];
    if (n > m) return mem[n] = n-m;

    if (vis[n]) return LONG_LONG_MAX/3; // if its visited it should not matter
    vis[n] = 1;

    if (n <= 2) return mem[n] = dp(n*2)+1;

    return mem[n] = min(dp(n*2), dp(n-1))+1;
}

int main(void) {
    cin >> n >> m;
    cout << dp(n) << endl;
    return 0;
}
