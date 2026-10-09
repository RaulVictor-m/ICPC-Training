#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
typedef long long ll;

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    // ORDERED SET USES TOO MUCH MEMORYYYYYY
    ordered_set lset;

    int n, q; cin >> n >> q;

    rep(i, 0, n+q) {
        int v; cin >> v;
        if (v < 0) lset.erase(lset.find_by_order(-v-1));
        else       lset.insert(v);
    }

    if (lset.empty()) cout << 0;
    else              cout << (*lset.begin());
    return 0;
}
