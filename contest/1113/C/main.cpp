/*
 * LINK: https://codeforces.com/contest/2248/problem/C
 * NAME: C. Maximize the Score
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<ll> vs(n*2);
        for (auto &v: vs) cin >> v;

        priority_queue<array<ll, 4>> pq;

        vector<ll> pos(n+1);
        vector<ll> dead(n+1);

        for (ll i = 0; i < n*2; i++) {
            if (!pos[vs[i]]) pos[vs[i]] = i+1;
            else             pq.push({(i-pos[vs[i]])+2, pos[vs[i]], i, vs[i]});
        }

        ll total = 0;
        queue<int> deads;
        while (!pq.empty()) {
            auto [w, l, r, v] = pq.top();
            pq.pop();

            if (dead[v] == 2) continue;
            if (dead[v] == 1) {
                deads.push(v);
                continue;
            }

            total += w*w;
            for (ll i = l; i <= r; i++) dead[vs[i]]++;
        }
        while (!deads.empty()) {
            auto v = deads.front();
            deads.pop();
            if (dead[v] == 1) total += 1;
        }

        cout << total << endl;
    }
    return 0;
}
