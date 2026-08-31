/*
 * LINK: https://codeforces.com/gym/105925/problem/D
 * NAME: D
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    int n; cin >> n;

    string S, T; getline(cin, S);

    long sup = 0, col = 0;
    getline(cin, S); // S
    for (auto c: S) sup += (c == '*');

    getline(cin, T); // T
    for (int i = 0; i < T.size(); i++) col += (T[i] != '*' && S[i] == '*');

    printf("%.2f\n", (double)col/sup);
    return 0;
}
