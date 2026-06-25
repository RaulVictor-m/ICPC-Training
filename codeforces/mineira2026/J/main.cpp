/*
 * LINK: https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/J
 * NAME: J. Just the Betas
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    long n; cin >> n;
    vector <long> vals(1e6+1);
    vector <long> primes(1e6+1);
    primes[1] = 1;

    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        vals[v]++;
    }

    for (int i = 2; i < ((1e6+2)/2); i++) {
        for (int j = i*2; !primes[i] && j <= ((1e6+2)/2); j+=i) {
            primes[j] = 1;
            vals[i] += vals[j];
        }
    }

    long lmax = 0;
    for (int i = 1; i <= 1e6+1; i++) if (vals[lmax] < vals[i]) lmax = i;

    cout << lmax << endl;
    return 0;
}
