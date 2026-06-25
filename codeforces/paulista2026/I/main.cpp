/*
 * LINK: https://codeforces.com/gym/106598/problem/I
 * NAME: I
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
*/

bool is_valid(const string &str) {
    return str.size() == 11 && str[0] == '1' && str[1] > '0' && str[2] == '9';
}

int main(void) {
    string num; cin >> num;

    if (num.size() >= 11) {
        if (is_valid(num)) {
            cout << 1 << endl;
            cout << num << endl;
            return 0;
        }
        cout << 0 << endl;
        return 0;
    }


    //generating permutations
    set<string> permutations;

    long digits = num.size();
    long missing_digits = 11 - num.size();

    string gen_comb;
    gen_comb.resize(11);

    for (int i = (1<<digits)-1; i < (1 << 11); i++) {
        bitset<11> positions(i);

        if (positions.count() != digits) continue;

        for (int j = 0; j < (1<<missing_digits); j++) {
            bitset<11> comb(j); // 0=1, 1=9

            long num_cursor = 0, comb_cursor = 0;

            for (int k = 0; k < 11; k++) {
                if (positions[k]) gen_comb[k] = num[num_cursor++];
                else              gen_comb[k] = comb[comb_cursor++] ? '9':'1';
            }

            if (is_valid(gen_comb)) permutations.emplace(gen_comb);
        }
    }

    cout << permutations.size() << endl;

    for (auto &str: permutations) cout << str << endl;

    return 0;
}
