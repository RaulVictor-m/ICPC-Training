/*
 * LINK: https://codeforces.com/gym/106598/problem/D
 * NAME: D
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    REASON:
*/

#define stars "____________________________________________________"

int main(void) {
    int n; cin >> n;

    printf("%*s%.*s\n", n, "", n+1, stars);
    for (int i = 0; i < n-1; i++) 
        printf("%*s/%*s\\\n", n-1-i, "", n+1+i*2, "");

    printf("/%.*s%*s\\%.*s\n", n, stars, n+n-1, "", n+1, stars);

    for (int i = n-1; i > 0; i--) 
        printf("%*s\\%*s/\n", (n+1)+(n-1-i), "", n+1+i*2, "");

    printf("%*s\\%.*s/\n",n*2, "", n+1, stars);

    return 0;
}
