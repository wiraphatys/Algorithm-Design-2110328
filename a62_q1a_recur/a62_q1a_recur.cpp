#include <bits/stdc++.h>
using namespace std;

void Solution(vector<vector<int> > &v, int a, int b, int top, int bottom, int left, int right) {
    if (a <= 0) {
        v[top][left] = b;
        return;
    }
    int s = 1 << (a-1);
    Solution(v, a - 1, b, top, top + s, left, left + s);
    Solution(v, a - 1, b - 1, top, top + s, left + s, right);
    Solution(v, a - 1, b + 1, top + s, bottom, left, left + s);
    Solution(v, a - 1, b, top + s, bottom, left + s, right);
}

int main() {
    int a, b;
    cin >> a >> b;
    int s = 1 << a;
    vector<vector<int> > v(s, vector<int>(s, 0));
    Solution(v, a, b, 0, s, 0, s);

    for (int r = 0; r < s; ++r) {
        for (int c = 0; c < s; ++c){ 
            cout << v[r][c] << ' ';
        }
        cout << "\n";
    }
    return 0;
}
