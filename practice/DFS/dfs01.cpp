#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[10001];
vector<bool> visited(10001);
int v;

void DFS(int i) {
    visited[i] = true;
    for (auto &e : adjList[i]) {
        if (!visited[e]) DFS(e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int e, c = 0;
    cin >> v >> e;
    for (auto i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (auto i = 1; i <= v; ++i) {
        if (!visited[i]) {
            ++c;
            DFS(i);
        }
    }
    printf("%d", c);
    return 0;
}