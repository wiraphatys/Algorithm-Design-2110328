#include <bits/stdc++.h>
using namespace std;

const int MAXVAL = 2002;
const int INF = 2e9;
vector<int> G[MAXVAL];
int dis[MAXVAL];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int co[n] = {0}, ci[n] = {0};
    for (int i = 0; i < n; ++i) cin >> ci[i];
    for (int i = 0; i < n; ++i) cin >> co[i];
    for (int i = 0; i < n; ++i) dis[i] = INF;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    dis[0] = 0;
    priority_queue<pair<int, int> > pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        for (auto v : G[u]) {
            if (dis[v] > dis[u] + co[u] + ci[v]) {
                dis[v] = dis[u] + co[u] + ci[v];
                pq.emplace(-dis[v], v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dis[i] == INF) cout << -1 << " ";
        else cout << dis[i] << " ";
    }
    return 0;
}
