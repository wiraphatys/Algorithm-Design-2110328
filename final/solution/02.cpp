#include <bits/stdc++.h>
using namespace std;

const int MOD = 32717;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<int> A(k), C(k + 1, 0);
    for (int i = 1; i <= k; ++i) cin >> C[i];
    for (int i = 0; i < k; ++i) cin >> A[i];

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < k; ++i) dp[i] = A[i] % MOD;

    for (int i = k; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i] = (dp[i] + (C[j] * dp[i - j]) % MOD) % MOD;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}