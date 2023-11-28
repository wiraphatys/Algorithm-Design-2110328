#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, m, k, sum = 0;
    cin >> n >> m >> k;
    vector<int> A(n), S(n,0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    S[0] = A[0]+k;
    for (int i = 1; i < n; ++i) S[i] = S[i-1]+A[i]+k;
    while (m--) {
        int left;
        ll budget;
        cin >> left >> budget;
        if (left > 0) budget += S[left-1];
        auto it = --(upper_bound(S.begin(), S.end(), budget));
        int x = it - (S.begin()+left-1);
        int result = (left == 0) ? (*it-k*x) : (*it-(k*x+S[left-1]));
        cout << result << "\n";
    }
    return 0;
}

// A[n] = 1 2 3 4 5
// S[n] = 1 3 6 10 15