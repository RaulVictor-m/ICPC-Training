/*
 * LINK: https://cses.fi/problemset/task/1141
 * NAME: Playlist
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    long n; cin >> n;

    long lmax = 0, lstart = 0;

    map<long, long> lmap;

    for (int i = 0; i < n; i++) {
        long v; cin >> v;

        if (lmap.count(v) && lmap[v] >= lstart) 
            lstart = lmap[v]+1;

        lmap[v] = i, lmax = max(lmax, i-(lstart-1));
    }
    cout << lmax << endl;
    return 0;
}
