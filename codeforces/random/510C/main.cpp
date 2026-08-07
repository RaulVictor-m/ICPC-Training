/*
 * LINK: https://codeforces.com/problemset/problem/510/C
 * NAME: C. Fox And Names
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int n; cin >> n;
    vector<int> adj[26] = {}, deg(26);

    string l1, l2; cin >> l1;
    for (int i = 1; i < n; i++) {
        cin >> l2;
        int ci = 0;
        while (ci < min(l1.size(), l2.size()) && l1[ci] == l2[ci]) ci++;

        if (min(l2.size(), l1.size()) == ci) {
            if (l1.size() > l2.size()) {
                cout << "Impossible\n";
                return 0;
            } else 
                continue;
        }

        adj[l1[ci]-'a'].push_back(l2[ci]-'a');
        deg[l2[ci]-'a']++;
        swap(l2, l1);
    }

    queue<int> qu;
    for (int i = 0; i < 26; i++) if (!deg[i]) qu.push(i);

    string ans;
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();

        ans.push_back((char)(v+'a'));
        for (auto u: adj[v]) 
            if (!(--deg[u])) qu.push(u);
    }

    if (ans.size() != 26) {
        cout << "Impossible\n";
        return 0;
    }

    for (auto u: ans) cout << u;
    cout << endl;
    return 0;
}
