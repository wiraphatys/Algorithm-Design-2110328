#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges, weights;
int n;

int heuristic_in(vector<bool> &visited, int u) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int best = 0;
            for (int j = 0; j < n; j++) {
                if (weights[j][i] > best && (visited[j] == false || j == u)) {
                    best = weights[j][i];
                }
            }
            sum += best;
        }
    }
    return sum;
}

bool search(vector<bool> &visited, int u, int sum, int k) {
    if (sum == k) return true;
    if (sum > k) return false;
    if (sum + heuristic_in(visited, u) < k) return false;
    for (auto &x : edges[u]) {
        int v = x;
        int w = weights[u][v];
        if (visited[v] == false) {
            visited[v] = true;
            bool r = search(visited, v, sum + w, k);
            visited[v] = false;
            if (r) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> n >> m;
    edges.resize(n);
    weights = vector<vector<int>>(n, vector<int>(n, 0));
    vector<int> k(8);
    for (int i = 0; i < 8; i++) cin >> k[i];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back(b);
        edges[b].push_back(a);
        weights[a][b] = w;
        weights[b][a] = w;
    }

    for (int i = 0; i < 8; i++) {
        vector<bool> visited(n, false);
        bool result = false;
        for (int j = 0; j < n; j++) {
            visited[j] = true;
            if (search(visited, j, 0, k[i])) {
                result = true;
                break;
            }
            visited[j] = false;
        }
        string x = (result) ? "YES" : "NO";
        cout << x << endl;
    }
}
