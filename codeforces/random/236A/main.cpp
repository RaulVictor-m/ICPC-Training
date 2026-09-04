/*
 * LINK: https://codeforces.com/problemset/problem/236/A
 * NAME: A. Boy or Girl
*/

#include <bits/stdc++.h>

using namespace std;
namespace rg = std::ranges;
namespace rv = std::views;

typedef long long ll;

int main(void) {
    string in; cin >> in;

    rg::sort(in);
    in.erase(rg::unique(in).begin(), in.end());

    cout << (in.size()&1 ? "IGNORE HIM!\n" : "CHAT WITH HER!\n");
    return 0;
}
