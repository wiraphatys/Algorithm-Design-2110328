#include <iostream>
#include <vector>
using namespace std;

int countWays(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j] += dp[j - i];
        }
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int result = countWays(n);
    cout << result << endl;

    return 0;
}
