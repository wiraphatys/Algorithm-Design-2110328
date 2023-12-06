#include <bits/stdc++.h>
using namespace std;

vector<string> result;
int r, c;
pair<int,int> x, y;


void solve(int a, int b, int ans, vector<vector<int>> &v, vector<vector<bool>> visited)
{
    visited[a][b] = true;
    if (a > r + 2 || a < 1 || b > c + 2 || b < 1)
        return;
    if (visited[y.first][y.second])
    {
        result.push_back(ans);
        return;
    }
    if (b + 1 < c + 1 && v[a][b + 1] == 0)
    {
        if (!visited[a][b + 1])
        {
            solve(a, b + 1, ans+1, v, visited);
        }
    }
    if (a + 1 < r + 1 && v[a + 1][b] == 0)
    {
        if (!visited[a + 1][b])
        {
            solve(a + 1, b, ans+1, v, visited);
        }
    }
    if (a - 1 >= 1 && v[a - 1][b] == 0)
    {
        if (!visited[a - 1][b])
        {
            solve(a - 1, b, ans+1, v, visited);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    vector<vector<int>> grid(r + 2, vector<int>(c + 2, 2));
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            int a; cin >> a;
            if (a == 1) x = make_pair(i,j);
            if (a == 2) y = make_pair(i,j);
            grid[i][j] = a;
        }
    }
    vector<vector<bool>> visited(r + 2, vector<bool>(c + 2, false));
    solve(x.first, x.second, 0, grid, visited);
    cout << *min_element(result.begin(), result.end()) +2;
    return 0;
}