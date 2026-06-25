/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/G
 * NAME: G. Garment Groups
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    long n, g; cin >> n >> g;

    cout << (g-1)*2 + 1 + (n-(g-1)) << endl;
    return 0;
}
