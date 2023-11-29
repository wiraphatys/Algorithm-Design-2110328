#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int r, c, t;
    scanf("%d %d %d", &r, &c, &t);
    int A[r+2][c+2];
    for (int i = 0; i < c+2; ++i) {
        A[0][i] = 2;
        A[r+1][i] = 2;
    }
    for (int i = 1; i < r+1; ++i) {
        A[i][0] = 2;
        A[i][c+1] = 2;
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            int x; scanf("%d", &x);
            A[i][j] = x;
        }
    }
    while (t--) {
        bool visited[r+2][c+2];
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <=c; ++j) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    if (A[i][j] == 1) {
                        if (A[i - 1][j] == 0) {
                            A[i - 1][j] = 1;
                            visited[i-1][j] = true;
                        }
                        if (A[i + 1][j] == 0) {
                            A[i + 1][j] = 1;
                            visited[i + 1][j] = true;
                        }
                        if (A[i][j + 1] == 0) {
                            A[i][j + 1] = 1;
                            visited[i][j + 1] = true;
                        }
                        if (A[i][j - 1] == 0) {
                            A[i][j - 1] = 1;
                            visited[i][j-1] = true;
                        }
                    }
                }
            }
        }
    }
    int count = 0;
    for (int i = 1; i < r+2; ++i) {
        for (int j = 1; j < c+2; ++j) {
            if (A[i][j]==1) ++count;
        }
    }
    printf("%d", count);
    return 0;
}