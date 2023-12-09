#include <bits/stdc++.h>
using namespace std;

int R, C;
char M[5003][5003];
bool visited[5003][5003];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q, next_q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> M[i][j];
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (M[i][j] == '1') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int ans = 0;
    while (true) {
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && ny >= 1 && nx <= R && ny <= C) {
                    if (M[nx][ny] == '2') {
                        cout << ans + 2;
                        return 0;
                    }
                    if (M[nx][ny] == '0' && visited[nx][ny] == false) {
                        next_q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        q = next_q;
        while (!next_q.empty())
            next_q.pop();
        ans++;
    }
}