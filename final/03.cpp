#include <bits/stdc++.h>
using namespace std;

vector<string> result;
int r, c;

void solve(int a, int b, string ans, vector<vector<int> > &v, vector<vector<bool> > visited) {
    visited[a][b] = true;
    if (a > r+2 || a < 1 || b > c+2 || b < 1) return;
    if (visited[r][c]) {
        result.push_back(ans);
        return;
    }
    if (b+1 < c+1 && v[a][b+1] == 0) {
        if (!visited[a][b+1]) {
            solve(a, b + 1, ans + 'A', v, visited);
        }
    }
    if (a+1 < r+1 && v[a+1][b] == 0) {
        if (!visited[a+1][b]) {
            solve(a + 1, b, ans + 'B', v, visited);
        }
    }
    if (a-1 >= 1 && v[a-1][b] == 0) {
        if (!visited[a-1][b]) {
            solve(a - 1, b, ans + 'C', v, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    // int grid[r+2][c+2];
    vector<vector<int> > grid(r + 2, vector<int>(c + 2, 2));
    // for (int j = 0; j < c+2; ++j) {
    //     grid[0][j] = 2;
    //     grid[r+1][j] = 2;
    // }
    // for (int i = 0; i < r+2; ++i) {
    //     grid[i][0] = 2;
    //     grid[i][c+1] = 2;
    // }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> grid[i][j];
        }
    }
    // for (int i = 0; i <= r+1; ++i) {
    //     for (int j = 0; j <= c+1; ++j) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    vector<vector<bool> > visited(r+2, vector<bool>(c+2, false));
    string str = "";
    solve(1, 1, str, grid, visited);
    for (auto &e : result) cout << e << endl;
    cout << "DONE";
    return 0;
}