#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(k+1, 0);
    for (int i = 1; i <= k; ++i) {
        cin >> arr[i];
    }
    vector<int> DP(n+1, 0);
    DP[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - arr[j] >= 0)
                DP[i] = (DP[i] + DP[i - arr[j]]) % 1000003;
        }
    }
    cout << DP[n];
    return 0;
}