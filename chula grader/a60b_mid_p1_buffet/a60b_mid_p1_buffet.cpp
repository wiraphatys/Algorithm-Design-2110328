#include <bits/stdc++.h>
using namespace std;

int main() {
    int f, w, n;
    cin >> f >> w >> n;
    vector<int> v(f);
    for (int i = 0; i < f; ++i) cin >> v[i];
    if (w == 0) {
        cout << f; return 0;
    }
    sort(v.begin(), v.end());
    int sum = 0, range = 2*w+1;
    auto start = v.begin(), stop = v.begin();
    while (true) {
        while (stop != v.end() && *stop - *start < range) {
            stop++;
        }
        ++sum;
        if (stop == v.end()) break;
        start = stop;
        stop++;
    }
    cout << sum << "\n";
    return 0;
}