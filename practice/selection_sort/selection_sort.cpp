#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    v.push_back(5); v.push_back(1); v.push_back(7); v.push_back(2); v.push_back(4); v.push_back(0);

    vector<int> temp(v.size());
    size_t idx = v.size() - 1;
    while (!v.empty()) {
        auto it = max_element(v.begin(), v.end());
        temp[idx--] = *it;
        swap(*it, v[v.size()-1]);
        v.pop_back();
    }

    v = temp;
    for (auto &e : v) cout << e << ' ';
    return 0;
}
