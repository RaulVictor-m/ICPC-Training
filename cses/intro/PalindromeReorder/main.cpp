/*
 * LINK: https://cses.fi/problemset/task/1755/
 * NAME: Palindrome Reorder
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    string p; cin >> p;

    int counter[27] = {0};
    deque<char> res;

    for (int i = 0; i < p.size(); i++) counter[p[i]-'@']++;

   int odd_count = 0;
    for (int i = 1; i <= 26; i++) 
        if (counter[i] % 2)
            if (odd_count) return printf("NO SOLUTION\n") == 0;
            else           odd_count = i;
 
    while (counter[odd_count]--) res.push_back(odd_count+'@');

    for (int i = 1; i <= 26; i++) 
        for (int j = 0; j < (counter[i]/2); j++) 
            res.push_back(i+'@'), res.push_front(i+'@');

    for (auto v: res) cout << v; cout << endl;

    return 0;
}
