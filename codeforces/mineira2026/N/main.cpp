/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/N
 * NAME: N. N-Checkers
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char board[20][20] = {0};

ll rec(ll i, ll j) {
    ll sum = 0;
    if (board[i-1][j+1] == 'P' && !board[i-2][j+2])  {
        board[i-1][j+1] = 0;
        sum = max(sum, rec(i-2,j+2) + 1);
        board[i-1][j+1] = 'P';
    }
    if (board[i+1][j-1] == 'P' && !board[i+2][j-2])  {
        board[i+1][j-1] = 0;
        sum = max(sum, rec(i+2,j-2) + 1);
        board[i+1][j-1] = 'P';
    }
    if (board[i+1][j+1] == 'P' && !board[i+2][j+2])  {
        board[i+1][j+1] = 0;
        sum = max(sum, rec(i+2,j+2) + 1);
        board[i+1][j+1] = 'P';
    }
    if (board[i-1][j-1] == 'P' && !board[i-2][j-2])  {
        board[i-1][j-1] = 0;
        sum = max(sum, rec(i-2,j-2) + 1);
        board[i-1][j-1] = 'P';
    }
    // cout << i << ", " << j << " -- ";
    // cout << sum << endl;
    return sum;
}

int main(void) {
    int n; cin >> n;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= str.size(); j++) {
            if (str[j-1] == 'P') board[i][j] = 'P'; else
            if (str[j-1] == 'B') board[i][j] = 'B';
        }
    }

    for (int i = 0; i <= n+1; i++) 
        board[n+1][i] = board[i][n+1] = board[0][i] = board[i][0] = 1;


    // for (int i = 0; i <= n+1; i++) {
    //     for (int j = 0; j <= n+1; j++) {
    //         if (board[i][j] == 1) cout << "#";
    //         if (board[i][j] == 0) cout << ".";
    //         if (board[i][j] == 'P') cout << "P";
    //         if (board[i][j] == 'B') cout << "B";
    //     }
    //     cout << endl;
    // }
    ll lmax = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 'B') {
                // cout << "TRY -- i = " << i << ", j = " << j << endl;
                board[i][j] = 0;
                lmax = max(lmax, rec(i, j));
                board[i][j] = 'B';
                // cout << "\n--------- " << lmax << endl << endl << endl;
            }
        }
    }

    cout << lmax << endl;
    return 0;
}
