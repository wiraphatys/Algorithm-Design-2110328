#include <bits/stdc++.h>
using namespace std;

int c = 0, n;

int data_yark_chip_hai(int sum, int i) {
    if (sum > n) return 0;
    else if (sum == n) {
        c++;
        return 0;
    }
    else if (sum < n) {
        for (int j = i; j <= n; ++j) {
            if (sum+j > n) continue;
            data_yark_chip_hai(sum+j, j);
        }
    }
}

int main() {
    cin >> n;
    
    for (auto i = 1; i <= n; ++i) {
        int sum = i;
        data_yark_chip_hai(sum, i);
    }
    cout << c;
    return 0;
}