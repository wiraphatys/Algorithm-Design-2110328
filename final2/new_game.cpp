#include <bits/stdc++.h>
using namespace std;

int r, c, MOD = 100000007;
int result = 0;

void solve(int row, int col, vector<vector<int> > &g, string &ans, char latest) {
    g[row][col] = 1;
    if (col == c - 1) {
        result++;
        result = result % MOD;
    }
    else {
        // X -> บนขวา
        if (row - 1 >= 0 && col + 1 < c && g[row - 1][col + 1] == 0 && latest != 'X') {
            ans.push_back('X');
            solve(row - 1, col + 1, g, ans, 'X');
            ans.pop_back();
            g[row - 1][col + 1] = 0;
        }
        // Y -> ขวา
        if (col + 1 < c && g[row][col + 1] == 0 && latest != 'Y') {
            ans.push_back('Y');
            solve(row, col + 1, g, ans, 'Y');
            ans.pop_back();
            g[row][col + 1] = 0;
        }
        // Z -> ล่างขวา
        if (row + 1 < r && col + 1 < c && g[row + 1][col + 1] == 0 && latest != 'Z') {
            ans.push_back('Z');
            solve(row + 1, col + 1, g, ans, 'Z');
            ans.pop_back();
            g[row + 1][col + 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    vector<vector<int> > g(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            cin >> g[i][j];
    }
    for (int i = 0; i < r; ++i) {
        if (g[i][0] == 1) continue;
        string ans = "";
        char latest = '#';
        solve(i, 0, g, ans, latest);
    }
    cout << (result % MOD) << "\n";
    return 0;
}