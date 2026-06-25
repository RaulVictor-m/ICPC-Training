/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/B
 * NAME: B. Bario World
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    vector<int> level;
    vector<int> visited;
    visited.reserve(1e5*5+2);
    level.reserve(1e5*5+2);
    while (t--) {
        int n; cin >> n;
        level.clear();
        visited.clear();
        string str; cin >> str;
        if (str[0] == '.') {
            cout << -1 << endl;
            continue;
        }

        level.push_back(1);
        for (int i = 1; i < n; i++) {
            if (str[i] == str[i-1]) level.back()++;
            else level.push_back(1);
        }
        level.push_back(0);

        queue<int> qu;

        qu.push(0);
        visited.resize(level.size(), -1);
        visited[0] = 0;

        while (!qu.empty()) {
            int i = qu.front();
            int p = level[i];
            qu.pop();

            p -= level[i+1];
            for (int j = i+2; j < level.size() && p > 0; j++) {
                if (j%2 == 0) {
                    if (visited[j] == -1) {
                        visited[j] = visited[i] + 1;
                        qu.push(j);
                    }
                }
                p -= level[j];
            }

            if (p > 0) {
                break;
            }
        }

        cout << visited[(level.size()-1) & (~1)] << endl;
        // for (auto v: level) cout << v << " "; cout << endl;
    }
    return 0;
}
