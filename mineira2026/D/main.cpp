/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/D
 * NAME: D. Dubious Dates
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int d, m; cin >> d >> m;
    if (d <= 12 && d != m) cout << "DATA INCERTA" << endl;
    else                   cout << "DATA SEGURA" << endl;
    return 0;
}
