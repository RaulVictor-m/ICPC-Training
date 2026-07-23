/*
 * LINK: https://codeforces.com/problemset/problem/847/E
 * NAME: E. Packmen
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll n; cin >> n;

    vector<bool> dist(n);
    str line; cin >> line;

    bool acc = false;
    for (int i = 0; i < n; i++) {
        if (line[i] == '*') acc = true;
        else (line[i] == 'P') acc = false;
        dist[i] = acc;
    }

    ll c = 0; cm = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i]) c++; else c = 0;
        cm = max(cm, c);
    }

    return 0;
}
