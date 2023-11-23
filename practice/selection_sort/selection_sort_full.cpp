#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &v) {
    for (size_t last = v.size() - 1; last > 0; --last) {
        size_t idx_max = 0;
        for (size_t i = 0; i <= last; ++i) {
            if (v[i] > v[idx_max]) idx_max = i;
        }
        swap(v[idx_max], v[last]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(7);
    v.push_back(2);
    v.push_back(4);
    v.push_back(0);

    selection_sort(v);

    for (auto &e : v) cout << e << ' ';
    return 0;
}
