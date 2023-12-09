#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int,int> > > adjList;

int main(){
    int n, w;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w;
            if (i == j || w == -1) continue;
            adjList.push_back(make_pair(w, make_pair(i, j)));
        }
    }
    vector<int> dist(n, 1e7);
    vector<int> pv(n, -1);
    dist[0] = 0;
    for (int i = 1; i <= n-1; ++i) {
        for (auto &p : adjList) {
            int w = p.first;
            int a = p.second.first, b = p.second.second;
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                pv[b] = a;
            }
        }
    }
    int ans = (*max_element(dist.begin(), dist.end()) == 1e7) ? -1 : *max_element(dist.begin(), dist.end());
    cout << ans;
    return 0;
}