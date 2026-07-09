/*
 * LINK: https://codeforces.com/problemset/problem/522/A
 * NAME: A. Reposts
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;

    ll lmax = 0;
    map<string, ll> lmap;
    string name[3]; 
    while (n--) {
        cin >> name[1] >> name[0] >> name[2];
        for (auto &str: name) for (auto &c: str) 
            if (c >= 'A' && c <= 'Z') c+=32;

        lmap[name[1]] = max(lmap[name[2]]+1, lmap[name[1]]);
        lmax = max(lmap[name[1]], lmax);
    }

    cout << lmax+1 << endl;
    return 0;
}
