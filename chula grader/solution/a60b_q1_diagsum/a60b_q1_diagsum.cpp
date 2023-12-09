#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, maxVal = -1000;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    int c = n, len = n;
    int row = 0, col = 0;
    while (c--) {
        vector<int> v(len), u(len);
        int sv = 0, su = 0;
        for (int i = row, j = col, k = 0; k < len; ++i,++j,++k) {
            sv += arr[i][j]; su += arr[j][i];
            v[k] = sv; u[k] = su;
        }
        auto a = max_element(v.begin(), v.end()), b = min_element(v.begin(), v.end());
        auto c = max_element(u.begin(), u.end()), d = min_element(u.begin(), u.end());
        int maxV = (*b < 0 && a - b > 0) ? (*a - *b) : *a;
        int maxU = (*d < 0 && c - d > 0) ? (*c - *d) : *c;
        int temp = max(maxV, maxU);
        maxVal = (temp > maxVal) ? temp : maxVal;
        len--; col++;
    }
    printf("%d", maxVal);
    return 0;
}