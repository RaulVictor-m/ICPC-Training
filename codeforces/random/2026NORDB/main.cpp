/*
 * LINK: https://codeforces.com/gym/106667/problem/B
 * NAME: B. Good Spotlights
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    string line; cin >> line;
    bitset<32> num(line);
    int v = num.to_ulong();

    bool f = 0;
    for (int i = 0, j = 0; j < 9; i++, i%=8 , j += f) {
        if ((i ^ (i>>1)) == v) f = 1;
        if (f) cout << bitset<3>(i ^ (i>>1)) << endl;
    }
    return 0;
}
