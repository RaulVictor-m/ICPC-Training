/*
 * LINK: https://codeforces.com/problemset/problem/514/A
 * NAME: A. Chewbacca and Number
*/

#include <bits/stdc++.h>
#include <cstddef>
#include <cstdint>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;
    auto nn = to_string(n);

    for (auto &c: nn) c -= '0', c = min((char)(9-c), (char)c), c += '0';
    if (nn.front() == '0') nn.front() = '9';

    cout << atoll(nn.c_str()) << endl;
    return 0;
}
