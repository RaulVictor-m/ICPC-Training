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
        the think here is, the algorithm is just a bfs
        where you add the value to the right and down from the node

        you save the smallest letter at that distance from the beggining
        and this has to be set while adding the nodes to the queue not when visiting

        and then before you add any of its neighbors you check if its current letter
        is smaller or equal to the smallest letter at that distance
        because if its bigger its path should be discarted

        kinda confusing exercise
        hope this makes some sense
*/

char dp[6002] = {0}; // 0 = up, 1 = right
char lett[3001][3001] = {0};
bool visited[3001][3001] = {0};

void path(int n) {
    queue<array<int, 4>> qu;
    qu.push({0, lett[1][1], 1, 1});
    dp[0] = lett[1][1];

    while (!qu.empty()) {
        int count = qu.front()[0];
        char letter = qu.front()[1];
        int i = qu.front()[2];
        int j = qu.front()[3];
        qu.pop();

        if (visited[i][j]) continue;
        visited[i][j] = 1;

        if (dp[count] < letter) continue;

        if (i < n) {
            qu.push({count+1, lett[i+1][j], i+1, j});
            dp[count+1] = min(dp[count+1], lett[i+1][j]);
        }

        if (j < n) {
            qu.push({count+1, lett[i][j+1], i, j+1});
            dp[count+1] = min(dp[count+1], lett[i][j+1]);
        }
    }
}

int main(void) {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> lett[i][j];
        }
    }

    for (int i = 0; i <= n*2; i++) dp[i] = CHAR_MAX;

    path(n);

    dp[n*2 - 1] = 0;
    cout << dp << endl;
    return 0;
}
