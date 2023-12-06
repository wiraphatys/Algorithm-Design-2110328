#include <bits/stdc++.h>
using namespace std;

int MOD = 32717;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    vector<int> A(k), C(k+1, 0);
    for (int i = 1; i <= k; ++i) cin >> C[i];
    for (int i = 0; i < k; ++i) cin >> A[i];
    vector<int> dp(n+1, 0);
    int idx = 0;
    while (idx < k) {
        dp[idx] = A[idx] % MOD;
        ++idx;
    }
    for (int i = idx; i <= n+1; ++i) {
        int count = 1, num = i-1;
        while (count <= k) {
            dp[i] = (dp[i] + (C[count]*dp[num]) % MOD) % MOD;
            num--, count++;
        }
    }
    cout << dp[n];
}