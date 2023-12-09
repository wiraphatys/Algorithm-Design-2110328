#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    int n,a;
    cin >> n >> a;
    vector<int> chefTime(n);
    for (int i = 0; i < n; ++i) cin >> chefTime[i];
    while (a--) {
        ll x, left = 0, right = 1e12, mid, result = 0;
        cin >> x;
        if (x <= n) {
            cout << "0\n";
            continue;
        }
        while (left <= right) {
            mid = (left+right)/2;
            ll cur = n;
            for (size_t i = 0; i < n; ++i) {
                if (cur >= x) break;
                cur += mid/chefTime[i];
            }
            if (cur >= x) {
                result = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        cout << result << "\n";
    }
    return 0;
}