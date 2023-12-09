#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, pair<int, int> > > adj;
vector<int> memo(pow(2,20)-1, -1);

int findset(int n) {
    int temp = n;
    while (memo[temp] != -1) {
        temp = memo[temp];
    }
    return temp;
}

void unionset(int a, int b) {
    memo[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ll w = arr[i] ^ arr[j];
            adj.push_back(make_pair(-w,make_pair(i,j)));
        }
    }
    sort(adj.begin(), adj.end());
    ll sum = 0, edge = 0;
    for (auto &p : adj) {
        if (edge == n-1) break;
        auto v = p.second;
        ll v1 = findset(v.first), v2 = findset(v.second);
        if (v1 != v2) {
            unionset(v1,v2);
            ++edge;
            sum += p.first;
        }
    }
    cout << -sum;
    return 0;
}