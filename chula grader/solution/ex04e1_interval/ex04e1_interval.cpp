#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int, int> > v(n);
    for (auto &[a,b]:v) cin >> b;
    for (auto &[a,b]:v) cin >> a;
    sort(v.begin(), v.end());
    int t = 0, result = 0;
    for (auto &p : v) {
        if (p.second >= t) {
            ++result;
            t = p.first;
        }
    }
    cout << result;
    return 0;
}