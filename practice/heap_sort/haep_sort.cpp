#include <bits/stdc++.h>
using namespace std;

void fixDown(vector<int> &v, size_t i, size_t size) {
    int temp = v[i];
    size_t c = 2 * i + 1;
    while (c < size) {
        if (c + 1 < size && v[c] < v[c + 1]) ++c;
        if (v[c] < temp) break;
        v[i] = v[c];
        i = c;
        c = 2 * i + 1;
    }
    v[i] = temp;
}

void heap_sort(vector<int> &v) {
    size_t n = v.size();
    if (n <= 1) return;

    for (int i = n / 2 - 1; i >= 0; --i) {
        fixDown(v, i, n);
    }

    for (int i = n - 1; i >= 0; --i) {
        swap(v[0], v[i]);
        fixDown(v, 0, i);
    }
}

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(7);
    v.push_back(2);
    v.push_back(4);
    v.push_back(0);

    heap_sort(v);

    for (auto &e : v) cout << e << ' ';
    return 0;
}