#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[200005];
vector<bool> visited(200005, false);
int c = 0;
bool isValid = true;
int l = -1, r = -1;

void DFS(int v, int edges) {
    visited[v] = true;
    if (edges > 2) isValid = false;
    for (auto &e : adjList[v]) {
        if (!visited[e]) {
            if (adjList[e].size() == 1) {
                if (l == -1) l = e;
                else r = e;
            }
            DFS(e, adjList[e].size());
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            int x = adjList[i].size();
            if (x==0) {
                ++c;
                l = -1; r = -1;
                continue;
            } else if (x==1 && l == -1) {
                l = i;
            }
            DFS(i, x);
            c = (isValid && adjList[l].size() == 1 && adjList[r].size() == 1) ? ++c : c;
            isValid = true;
            l = -1; r = -1;
        }
    }
    printf("%d", c);
    return 0;
}