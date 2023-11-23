#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> p(m), h(m), t(k);
    for (int i = 0; i < m; ++i) cin >> p[i];
    for (int i = 0; i < m; ++i) cin >> h[i];
    for (int i = 0; i < k; ++i) cin >> t[i];

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[i] - w <= p[j] && p[j] <= t[i] + w) {
                if (h[j] != 0) {
                    --h[j]; break;
                }
            }
        }
    }
    
    int sum = 0;
    for (auto &e : h) sum += e;
    cout << sum;
    return 0;
}