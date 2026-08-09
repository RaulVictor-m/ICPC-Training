/*
 * LINK: https://codeforces.com/problemset/problem/510/A
 * NAME: A. Fox And Snake
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int r, c; cin >> r >> c;
    vector<string> grid(r, string(c, '.'));

    int i = 0, j = 0;
    while (i < r) {
        if (i%2 == 0) {
            if (j == c-1) {
                while (j >= 0) grid[i][j--] = '#';
                j++;
            } else {
                while (j < c) grid[i][j++] = '#';
                j--;
            }
        } else grid[i][j] = '#';
        i++;
    }

    for (auto line: grid) cout << line << endl;
    return 0;
}
