#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1001];

void BFS(int start, int deg, int &count) {
    vector<int> distance(1001, -1);
    queue<int> Q;
    Q.push(start);
    distance[start] = 0;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        if (distance[v] == deg) continue;
        for (auto &neighbor : adjList[v]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[v]+1;
                Q.push(neighbor);
                ++count;
            }
        }
    }
}

int main() {
    int vertices, edges, deg;
    scanf("%d %d %d", &vertices, &edges, &deg);
    for (int i = 0; i < edges; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < vertices; ++i) {
        int count = 0;
        BFS(i, deg, count);
        ans = max(ans, count);
    }
    ++ans;
    printf("%d", ans);
    return 0;
}