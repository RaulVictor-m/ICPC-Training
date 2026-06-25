/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/E
 * NAME: E. Exploring the Terrain
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mat[502][502] = {0};
ll marker[502][502] = {0};
array<ll, 2> v[502*502][2] = {};
int main(void) {
    ll n, m, t, s1 = 0, s2 = 0; cin >> n >> m >> t;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];

    for (int i = 0; i < t; i++) cin >> v[i][0][0] >> v[i][0][1];
    for (int i = 0; i < t; i++) cin >> v[i][1][0] >> v[i][1][1];

    for (int i = 0; i < t; i++) {
        marker[v[i][0][0]][v[i][0][1]] = 0b1;
        marker[v[i][0][0]][v[i][0][1]+1] = 0b1;
        marker[v[i][0][0]][v[i][0][1]-1] = 0b1;
        marker[v[i][0][0]+1][v[i][0][1]] = 0b1;
        marker[v[i][0][0]-1][v[i][0][1]] = 0b1;

        if (!marker[v[i][1][0]][v[i][1][1]]) {
            s1 += mat[v[i][1][0]][v[i][1][1]];
            mat[v[i][1][0]][v[i][1][1]] = 0;
        }
        else marker[v[i][1][0]][v[i][1][1]] = 0;

        if (!marker[v[i][1][0]][v[i][1][1]+1]) {
            s1 += mat[v[i][1][0]][v[i][1][1]+1];
            mat[v[i][1][0]][v[i][1][1]+1] = 0;
        }
        else marker[v[i][1][0]][v[i][1][1]+1] = 0;

        if (!marker[v[i][1][0]][v[i][1][1]-1]) {
            s1 += mat[v[i][1][0]][v[i][1][1]-1];
            mat[v[i][1][0]][v[i][1][1]-1] = 0;
        }
        else marker[v[i][1][0]][v[i][1][1]-1] = 0;

        if (!marker[v[i][1][0]+1][v[i][1][1]]) {
            s1 += mat[v[i][1][0]+1][v[i][1][1]];
            mat[v[i][1][0]+1][v[i][1][1]] = 0;
        }
        else marker[v[i][1][0]+1][v[i][1][1]] = 0;

        if (!marker[v[i][1][0]-1][v[i][1][1]]) {
            s1 += mat[v[i][1][0]-1][v[i][1][1]];
            mat[v[i][1][0]-1][v[i][1][1]] = 0;
        }
        else marker[v[i][1][0]-1][v[i][1][1]] = 0;

        if (marker[v[i][0][0]][v[i][0][1]]) {
            s2 += mat[v[i][0][0]][v[i][0][1]];
            mat[v[i][0][0]][v[i][0][1]] = 0;
        }
        if (marker[v[i][0][0]][v[i][0][1]+1]) {
            s2 += mat[v[i][0][0]][v[i][0][1]+1];
            mat[v[i][0][0]][v[i][0][1]+1] = 0;
        }
        if (marker[v[i][0][0]][v[i][0][1]-1]) {
            s2 += mat[v[i][0][0]][v[i][0][1]-1];
            mat[v[i][0][0]][v[i][0][1]-1] = 0;
        }
        if (marker[v[i][0][0]+1][v[i][0][1]]) {
            s2 += mat[v[i][0][0]+1][v[i][0][1]];
            mat[v[i][0][0]+1][v[i][0][1]] = 0;
        }
        if (marker[v[i][0][0]-1][v[i][0][1]]) {
            s2 += mat[v[i][0][0]-1][v[i][0][1]];
            mat[v[i][0][0]-1][v[i][0][1]] = 0;
        }

        marker[v[i][0][0]][v[i][0][1]] = 0b0;
        marker[v[i][0][0]][v[i][0][1]+1] = 0b0;
        marker[v[i][0][0]][v[i][0][1]-1] = 0b0;
        marker[v[i][0][0]+1][v[i][0][1]] = 0b0;
        marker[v[i][0][0]-1][v[i][0][1]] = 0b0;
    }

    cout << s2 << " " << s1 << endl;
    return 0;
}
