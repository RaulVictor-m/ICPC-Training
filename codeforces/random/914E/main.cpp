/*
 * LINK: https://codeforces.com/problemset/problem/914/E
 * NAME: E. Palindromes in a Tree
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int int64_t

const int N = 2e5+5;

vector<vector<int>> adj(N);
vector<int> let(N), ans(N), sz(N), frq(1<<20|1), cnt(N);
vector<bool> dead(N);

void csz(int v, int p) {
    sz[v] = 1;
    for (auto u: adj[v])
        if (!dead[u] && u != p) 
            csz(u, v), sz[v] += sz[u];
}

int centroid(int v, int p, int tsz) {
    for (auto u: adj[v])
        if (!dead[u] && u != p && sz[u]*2 > tsz)
            return centroid(u, v, tsz);
    return v;
}

void solve(int v, int p, int mask) {
    mask ^= let[v];
    cnt[v] += frq[mask];
    for (int k = 0; k < 20; k++)
        cnt[v] += frq[mask^(1<<k)];

    for (auto u: adj[v])
        if (!dead[u] && u != p) solve(u, v, mask);
}

void add(int v, int p, int mask) {
    mask ^= let[v];
    frq[mask]++;
    for (auto u: adj[v])
        if (!dead[u] && u != p) add(u, v, mask);
}

void clear(int v, int p, int mask) {
    mask ^= let[v];
    frq[mask] = 0;
    for (auto u: adj[v])
        if (!dead[u] && u != p) clear(u, v, mask);
}

void clearC(int v, int p) {
    cnt[v] = 0;
    for (auto u: adj[v])
        if (!dead[u] && u != p) clearC(u, v);
}

void prop(int v, int p) {
    for (auto u: adj[v])
        if (!dead[u] && u != p) 
            prop(u, v), cnt[v] += cnt[u];
    ans[v] += cnt[v];
}

void decomp(int v) {
    csz(v, 0);
    int cent = centroid(v, 0, sz[v]);
    dead[cent] = 1;

    frq[let[cent]]++;
    for (auto u: adj[cent])
        if (!dead[u]) solve(u, 0, 0), add(u, 0, let[cent]);

    cnt[cent] += frq[0];
    for (int k = 0; k < 20; k++)
        cnt[cent] += frq[(1<<k)];

    frq[let[cent]]--;
    for (auto u: adj[cent])
        if (!dead[u]) clear(u, 0, let[cent]);

    reverse(adj[cent].begin(), adj[cent].end());

    for (auto u: adj[cent])
        if (!dead[u]) solve(u, 0, 0), add(u, 0, let[cent]);

    prop(cent, 0);
    ans[cent] -= cnt[cent]/2;

    for (auto u: adj[cent])
        if (!dead[u]) clear(u, 0, let[cent]), clearC(u, 0);

    cnt[cent] = 0;

    for (auto u: adj[cent])
        if (!dead[u]) decomp(u);
}

int32_t main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    string line; cin >> line;
    for (int i = 1; i <= n; i++)
        let[i] = 1<<(line[i-1]-'a');

    decomp(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
    return 0;
}
