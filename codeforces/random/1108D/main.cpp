/*
 * LINK: https://codeforces.com/problemset/problem/1108/D
 * NAME: D. Diverse Garland
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    string line; cin >> line;
    for (auto &u: line)
        u = u == 'R' ? 1 : u == 'G' ? 2 : 3;

    char l[4] = {'\0', 'R', 'G', 'B'};

    int c = 0;
    for (int i = 1; i < line.size()-1; i++)
        if (line[i] == line[i+1] && line[i] == line[i-1])
            line[i] = line[i] > 1 ? line[i]-1 : line[i]+1, c++;

    int magic = 1^2^3;
    for (int i = 0; i < line.size()-1; i++)
        if (line[i] == line[i+1]) {
            if (i > 0) line[i] = magic^line[i+1]^line[i-1], c++;
            else       line[i] = line[i] > 1 ? line[i]-1 : line[i]+1, c++;

        }

    cout << c << endl;
    for (auto &u: line) u = l[u];

    cout << line << endl;
    return 0;
}
