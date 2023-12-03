#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1000001];
vector<bool> visited(100001);
int start=-1, step=0, result;
bool isCycle = false;

void DFS(int v, int prev) {
    if (isCycle) return;
    if (visited[v]) {
        isCycle = true;
        start = v;
        return;
    }
    visited[v] = true;
    for (auto &e : adjList[v]) {
        if (e == prev) continue;
        DFS(e, v);
        if (isCycle) break;
    }
    if (isCycle && v != start) ++step;
    else if (isCycle && v == start) result = ++step;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) DFS(i, -1);
    }
    printf("%d", result);
    return 0;
}
