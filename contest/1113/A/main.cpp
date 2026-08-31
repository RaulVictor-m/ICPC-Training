/*
 * LINK: 
 * NAME: 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        string line; cin >> line;

        int f0 = -1, f1 = -1;
        for (int i = 0; i < line.size(); i++) {
            auto c = line[i];

            if (c == '0' && f0 == -1) f0 = i;
            if (c == '1' && f1 == -1) f1 = i;
        }

        for (int i = 0; i < line.size(); i++) {
            auto c = line[i];
            if (i == f0 || i == f1) continue;
            cout << c;
        }
        cout << endl;

    }
    return 0;
}
