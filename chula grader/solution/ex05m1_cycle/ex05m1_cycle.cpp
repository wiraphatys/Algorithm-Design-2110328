#include <bits/stdc++.h>
using namespace std;

bool isCircle;

void DFS(int v, int prev, vector<vector<int > > &adjList, vector<bool> &visited) {
    if (isCircle) return;
    if (visited[v]) {
        isCircle = true;
        return;
    }
    visited[v] = true;
    for (auto &e : adjList[v]) {
        if (e == prev) continue;
        DFS(e, v, adjList, visited);
        if (isCircle) return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int vertices, edges;
        cin >> vertices >> edges;
        if (edges == 0) {
            cout << "NO\n"; continue;
        }
        vector<vector<int> > adjList(vertices+1);
        vector<bool> visited(vertices+1, false);
        while (edges--) {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                isCircle = false;
                DFS(i, -1, adjList, visited);
                if (isCircle) {
                    break;
                }
            }
        }
        cout << (isCircle ? "YES" : "NO") << "\n";
    }
    return 0;
}