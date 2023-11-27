#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[10005];
vector<bool> visited(10005);
int vertices, edges;

void DFS(int n) {
    visited[n] = true;
    for (auto v : adjList[n]) {
        if (!visited[v]) DFS(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> vertices >> edges;

    while (edges--) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int count = 0;
    for (int i = 1; i <= vertices; ++i) {
        if (!visited[i]) {
            ++count;
            DFS(i);
        }
    }
    cout << count;
    return 0;
}