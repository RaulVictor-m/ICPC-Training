/*
 * LINK: https://codeforces.com/problemset/problem/1535/D
 * NAME: D. Playoff Tournament
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    int rn = 1<<n;

    vector<char> vs(rn); 
    vector<int> seg(rn*2, 1);
    string line; cin >> line;

    for (int i = 0; i < rn; i++) vs[i] = line[i];
    reverse(vs.begin(), vs.end());

    for (int i = rn-1; i > 0; i--) {
        if (vs[i] == '1') seg[i] = seg[i<<1]; else
        if (vs[i] == '0') seg[i] = seg[i<<1|1];
        else              seg[i] = seg[i<<1] + seg[i<<1|1];
    }

    int q; cin >> q;
    while (q--) {
        int vi; char c; cin >> vi >> c;
        vs[vs.size() - vi] = c;

        for (int i = vs.size() - vi; i > 0; i>>=1) {
            if (vs[i] == '1') seg[i] = seg[i<<1]; else
            if (vs[i] == '0') seg[i] = seg[i<<1|1];
            else              seg[i] = seg[i<<1] + seg[i<<1|1];
        }

        cout << seg[1] << endl;
    }

    return 0;
}
