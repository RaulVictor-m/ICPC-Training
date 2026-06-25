#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    int res = 0;

    for (int i = 1; i < n; i++) {
        int v; cin >> v;
        res = res ^ v ^ i;
    }

    cout << (res ^ n) << endl;

    return 0;
}
