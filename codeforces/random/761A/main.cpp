/*
 * LINK: https://codeforces.com/problemset/problem/761/A
 * NAME: A. Dasha and Stairs
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int a, b; cin >> a >> b;
    if (abs(a-b) > 1 || (!a && !b))  cout << "NO\n";
    else                             cout << "YES\n";
    return 0;
}
