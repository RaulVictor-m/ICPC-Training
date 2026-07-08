#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    vector<ll> vs;
    vs.reserve(1e6+2);

    ll n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ll v; cin >> v;
        for (int j = 0; j < v; j++) vs.push_back(i);
    }

    ll q; cin >> q;
    while (q--) {
        ll v; cin >> v;
        cout << vs[v-1] << endl;
    }
    return 0;
}
