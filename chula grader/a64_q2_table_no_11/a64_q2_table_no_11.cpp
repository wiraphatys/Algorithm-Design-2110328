#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int main() {
    int n;
    cin >> n;
    int dp[2][2][2] = {0};
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    int i = 2;
    while (i <= n) {
        int k = i % 2;
        dp[k][0][0] = (dp[1 - k][0][0] + dp[1 - k][0][1] + dp[1 - k][1][0]) % MOD;
        dp[k][0][1] = (dp[1 - k][0][0] + dp[1 - k][1][0]) % MOD;
        dp[k][1][0] = (dp[1 - k][0][0] + dp[1 - k][0][1]) % MOD;
        i++;
    }
    int result = (dp[n % 2][0][0] + dp[n % 2][0][1] + dp[n % 2][1][0]) % MOD;
    cout << result << endl;
    return 0;
}
