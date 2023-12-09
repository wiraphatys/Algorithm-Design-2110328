#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, m, k, x;
    ll sum = 0;
    cin >> n >> m >> k;
    vector<ll> s(n+1), cost(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        sum += x;
        s[i] = sum;
        cost[i] = s[i]+i*k;
    }
    while (m--) {
        int start, budget;
        cin >> start >> budget;
        int t = cost[start];
        budget += t;
        auto it = --(upper_bound(cost.begin(), cost.end(), budget));
        auto idx = it - cost.begin();
        cout << s[idx]-s[start] << "\n";
    }
    return 0;
}