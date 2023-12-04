#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int c, k;

void bfs(int start, vector<int> &dist) {
    c = 0;
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (dist[v] == k) continue;
        for (auto &e : adj[v]){
            if (dist[e] == -1) {
                dist[e] = dist[v]+1;
                q.push(e);
                ++c;
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e >> k;
    for(int i = 0; i < e; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> dist(1005, -1);
        bfs(i, dist);
        result = max(result, c);
    }
    cout << ++result << endl;
    return 0;
}