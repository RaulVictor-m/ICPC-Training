/*
 * LINK: https://codeforces.com/problemset/problem/4/A
 * NAME: A. Watermelon
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int w; cin >> w;
    if (w%2 == 0 && w != 2) cout << "YES" << endl;
    else                    cout << "NO" << endl;
    return 0;
}
