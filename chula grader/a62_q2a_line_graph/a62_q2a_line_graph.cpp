#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[200001];
vector<bool> visited(200001);
int c = 0;

void DFS(int n) {

}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; ++i) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) DFS(i);
    }
    return 0;
}