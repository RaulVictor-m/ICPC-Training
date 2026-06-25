/*
 * LINK: https://codeforces.com/gym/106598/problem/B
 * NAME: B
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
*/

int main(void) {
    unsigned long n, c, k; cin >> n >> c >> k;
    unsigned long cc = 1, kc = 1;
    unsigned long qo = (k/c);

    unsigned long last; cin >> last; n--;
    while (n--) {
        unsigned long v; cin >> v;
        if ((v-last) <= (qo+1)) cc += (v-last);
        else              cc++, kc++;
        last = v;
    }

    cout << (c*cc)+(k*kc) << endl;
    return 0;
}
