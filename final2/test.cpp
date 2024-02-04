#include <iostream>
#include <vector>
using namespace std;

const int MOD = 100000007;

int solve(int row, int col, vector<vector<int> > &g, char latest) {
    if (col == g[0].size() - 1) {
        return 1;
    }
    int result = 0;
    if (row - 1 >= 0 && col + 1 < g[0].size() && g[row - 1][col + 1] == 0 && latest != 'X') {
        result = (result + solve(row - 1, col + 1, g, 'X')) % MOD;
    }
    if (col + 1 < g[0].size() && g[row][col + 1] == 0 && latest != 'Y') {
        result = (result + solve(row, col + 1, g, 'Y')) % MOD;
    }
    if (row + 1 < g.size() && col + 1 < g[0].size() && g[row + 1][col + 1] == 0 && latest != 'Z') {
        result = (result + solve(row + 1, col + 1, g, 'Z')) % MOD;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    vector<vector<int> > g(r, vector<int>(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> g[i][j];
        }
    }
    int totalPaths = 0;
    for (int i = 0; i < r; ++i) {
        totalPaths = (totalPaths + solve(i, 0, g, '#')) % MOD;
    }
    cout << totalPaths << "\n";
    return 0;
}
