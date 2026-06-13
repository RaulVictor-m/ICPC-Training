/*
 * LINK: there is no link -- local problem
 * NAME: Indice Carrasco Mamata
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

int main(void) {
    long n; cin >> n;

    unordered_map<string, array<long, 25>> dpmap;
    unordered_map<string, vector<array<long, 3>>> vals;

    while (n--) {
        string name; cin >> name;
        long a, b, w; cin >> a >> b >> w;
        vals[name].push_back({b, a, w});
    }

    for (auto &v: vals) sort(v.second.begin(), v.second.end());

    for (auto &query: vals) {
        for (auto [b, a, w]: query.second) {
            auto &dp = dpmap[query.first];
            for (int t = 24; t >= b; t--) dp[t] = max(dp[t], (dp[t]-dp[b])+w+dp[a]);
        }
    }

    long sum = 0;
    for (auto &v: dpmap) sum += v.second[24];
    cout << sum << endl;
    return 0;
}
