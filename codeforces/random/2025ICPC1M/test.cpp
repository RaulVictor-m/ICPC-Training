#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t = 100;
    while (t--) {
        int n = (rand()%15)+1;
        int k = (rand()%15)+1;
        cout << n << ' ' << k << endl;
        for (int i = 0; i < n; i++) {
            cout << (rand()%(50))+1 << ' ';
        }
        cout << endl;

    }
    return 0;
}
