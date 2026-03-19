/*
 * LINK: https://cses.fi/problemset/task/3359
 * NAME: Minimal Grid Path
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/*
    REASON:
*/

int parent[3002][3002] = {0}; // 0 = up, 1 = right
char lett[3001][3001] = {0};

void path(int n) {
              //lett, count, pos(i, j)
    // priority_queue<array<ll, 5>> pq;
    // pq.push({-lett[1][1], 0, 0, 1, 1});
    priority_queue<array<ll, 5>> pq;
    pq.push({0, -lett[1][1], 0, 1, 1});

    while (!pq.empty()) {
        auto letter = pq.top()[1];
        auto count = pq.top()[2];
        auto i = pq.top()[3];
        auto j = pq.top()[4];
        pq.pop();
        // if (parent[i][j] != -1) {
        //     cout << "i: " << i << ", j: " << j << " letter: " << letter << "  = parent - ";
        //     if (parent[i][j] == 0) cout << "left " << "i: " << i << ", j: " << j-1 << " letter: " << lett[i][j-1] << endl;
        //     if (parent[i][j] == 1) cout << "up   " << "i: " << i-1 << ", j: " << j << " letter: " << lett[i-1][j] << endl;
        // } else {
        //     cout << "i: " << i << ", j: " << j << " letter: " << letter << endl;
        // }

        if (i == n && j == n) break;

        if (j < n) {
            if (parent[i][j+1] == -1) {
                parent[i][j+1] = 0;
                // pq.push({-lett[i][j+1], letter, count+1, i, j+1});
                pq.push({letter, -lett[i][j+1], count+1, i, j+1});
            }
        }

        if (i < n) {
            if (parent[i+1][j] == -1) {
                parent[i+1][j] = 1;
                // pq.push({-lett[i+1][j], letter, count+1, i+1, j});
                pq.push({letter, -lett[i+1][j], count+1, i+1, j});
            }
        }
    }
}

int main(void) {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> lett[i][j];
            parent[i][j] = -1;
        }
    }

    path(n);

    string res;
    for (int i = n, j = n; j > 0 && i > 0; ) {
        res = lett[i][j] + res;
        if (parent[i][j] == 0) j--;
        else                   i--;
    }

    cout << res << endl;
    return 0;
}
