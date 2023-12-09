#include <bits/stdc++.h>
using namespace std;

int r, c;

void solve(int row, int col, vector<vector<int> > &grid, string &ans) {
    grid[row][col] = 1;
    if (row == r - 1 && col == c - 1) {
        cout << ans << "\n";
    }
    else {
        if (col + 1 < c && grid[row][col + 1] == 0) {
            ans += "A";
            solve(c, r, row, col + 1, grid, ans);
            ans.pop_back();
            grid[row][col + 1] = 0;
        }
        if (row + 1 < r && grid[row + 1][col] == 0) {
            ans += "B";
            solve(c, r, row + 1, col, grid, ans);
            ans.pop_back();
            grid[row + 1][col] = 0;
        }
        if (row - 1 >= 0 && grid[row - 1][col] == 0) {
            ans += "C";
            solve(c, r, row - 1, col, grid, ans);
            ans.pop_back();
            grid[row - 1][col] = 0;
        }
    }
}

int main() {
    cin >> r >> c;
    vector<vector<int> > grid(r, vector<int>(c));
    string ans = "";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> grid[i][j];
    }
    solve(0, 0, grid, ans);
    cout << "DONE";
}
