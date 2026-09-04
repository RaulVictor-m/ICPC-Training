/*
 * LINK: https://codeforces.com/problemset/problem/112/A
 * NAME: A. Petya and Strings
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;

int main(void) {
    string s1, s2; cin >> s1 >> s2;
    for (auto [a, b]: rv::zip(s1, s2)) a = tolower(a), b = tolower(b);

    if (s1 < s2) cout << -1;
    else if (s2 == s1) cout << 0;
    else cout << 1;
    return 0;
}
