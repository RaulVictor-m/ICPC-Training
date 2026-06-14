/*
 * LINK: 
 * NAME: Espionagem
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:

*/


int main(void) {
    string frase, line;

    while (getline(cin, frase)) {
        long n; cin >> n;
        getline(cin, line); // removing \n

        bool yes = false;
        while (n--) {
            getline(cin, line);
            line += line;

            for (int i = 0; i < 26 && !yes; i++) {

                if (line.find(frase) != string::npos) {
                    yes = true;
                    break;
                };

                for (auto &c: frase) {
                    if (c != ' ') c = (((c-'A')+1) % 26) + 'A';
                }
            }
        }
        if (yes) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
