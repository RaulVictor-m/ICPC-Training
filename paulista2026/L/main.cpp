/*
 * LINK: https://codeforces.com/gym/106598/problem/L
 * NAME: L
*/

#include <bits/stdc++.h>
#include <type_traits>

using namespace std;
typedef long long ll;

/*
    REASON:

*/

vector<int> vals;
int dpMem[501][501] = {0};

int dp(int l, int r) {
    if (l >= r-1) return 0;

    auto &ans = dpMem[l][r];
    if (ans != -1) return ans;

    // computing for first seq
    vector<long> lmap(501);
    vector<char> seq;
    for (int i = 0; i < vals.size(); i++) {
        if (vals[i] >= l && vals[i] < r) {
            lmap[vals[i]] = seq.size();
            seq.push_back(vals[i] != l ?'D':'X');
        }
    }

    long points = 0; // first seq has not alternation

    // computing all sequences and DPs on the way
    for (int i = l; i < r; i++) {
        ans = max((long)ans, points + dp(l, i) + dp (i+1, r));

        int p = lmap[i];

        if (p > 0 && p < seq.size()-1 && seq[p-1] != seq[p+1])
            points--;

        seq[p] = 'E';

        if (p > 0 && seq[p-1] != seq[p]) points++;
        if (p < seq.size()-1 && seq[p+1] != seq[p]) points++;

        p = lmap[i+1];
        if (p > 0 && seq[p-1] != seq[p]) points--;
        if (p < seq.size()-1 && seq[p+1] != seq[p]) points--;

        seq[p] = 'X';
        if (p > 0 && p < seq.size()-1 && seq[p-1] != seq[p+1])
            points++;

        // cout << "l " << l << " r " << r << " root " << i << " ";
        // for (auto c: seq) cout << c; cout << "  " << points << endl;
    }

    return ans;
}

int main(void) {
    int n; cin >> n;
    vals.resize(n);

    for (int i = 0; i < n; i++) cin >> vals[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) dpMem[i][j] = -1;

    cout << dp(0, n) << endl;

    return 0;
}
