#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > adj;
vector<int> visited(2005, -1);

void bellman(int s, int n) {
    vector<int> dist(n, 1e6);
    vector<int> prev(n, -1);
    dist[s] = 0;
    for (int i = 1; i <= n-1; ++i) {
        for (auto &p : adj) {
            int w = p.first;
            int a = p.second.first, b = p.second.second;
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                prev[b] = a;
            }
        }
    }
    for (auto &p : adj) {
        int w = p.first;
        int a = p.second.first, b = p.second.first;
        if (dist[b] > dist[a] + w) {
            cout << "-1"; return;
        }
    }
    for (auto &e : dist) {
        if (e == 1e6) cout << -1 << ' ';
        else cout << e << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> co(n), ci(n);
    for (int i = 0; i < n; ++i) cin >> ci[i];
    for (int i = 0; i < n; ++i) cin >> co[i];
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int w = co[a]+ci[b];
        adj.push_back(make_pair(w,make_pair(a,b)));
    }
    bellman(0, n);
    return 0;
}