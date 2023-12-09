#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > adjList;
vector<int> memorize(1005, -1);

int findset(int n) {
    int temp = n;
    while (memorize[temp] != -1) {
        temp = memorize[temp];
    }
    return temp;
}

void unionset(int s1, int s2) {
    memorize[s2] = s1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, w;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            cin >> w;
            adjList.push_back(make_pair(w, make_pair(i,j)));
        }
    }
    sort(adjList.begin(), adjList.end());
    int sum = 0, edge = 0;
    for (auto &p : adjList) {
        if (edge == n-1) break;
        auto v = p.second;
        int s1 = findset(v.first);
        int s2 = findset(v.second);
        if (s1 != s2) {
            unionset(s1, s2);
            sum += p.first;
            ++edge;
        }
    }
    cout << sum << "\n";
    return 0;
}