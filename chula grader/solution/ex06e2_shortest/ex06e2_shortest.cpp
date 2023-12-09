#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > adjList;

void bellman(int s, int n){
    vector<long long> dist(n, 1e12);
    vector<int> prev(n, -1);
    dist[s] = 0;
    for (int i = 1; i <= n-1; ++i) {
        for (auto &p : adjList) {
            int w = p.first;
            int a = p.second.first, b = p.second.second;
            if (dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                prev[b] = a;
            }
        }
    }
    for (auto &p : adjList) {
        int w = p.first;
        int a = p.second.first, b = p.second.second;
        if (dist[b] > dist[a] + w){
            cout << "-1"; return;
        }
    }
    for (auto &e : dist) cout << e << ' ';
}

int main(){
    int n, e, s;
    cin >> n >> e >> s;
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adjList.push_back(make_pair(c, make_pair(a,b)));
    }
    bellman(s, n);
    return 0;
}