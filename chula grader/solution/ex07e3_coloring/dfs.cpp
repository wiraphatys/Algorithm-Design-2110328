#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[51];
vector<bool> visited(51);
vector<vector<int> > color;

void DFS(int v) {
    visited[v] = true;
    for (auto &v : color) {
        for (auto &)
    }
    for (auto &e : adjList[v]){
        if (!visited[e]) DFS(e);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) DFS(i);
    }
    return 0;
}