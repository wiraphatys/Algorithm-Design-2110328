#include <bits/stdc++.h>
using namespace std;

int c = 0;

void solve(vector<int> &v, int i, int left, int right, int key) {
    for (int j = left; j < right; ++j) {
        auto itr = find(v.begin()+left, v.begin()+right, key);
        if (itr != v.end()) {
            swap (v[i], *itr);
            c++;
            break;
        }
        if (v[i] != v[j]) {
            swap (v[i], v[j]);
            c++;
            break;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int c1 = 0, c2 = 0, c3 = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] == 1) ++c1;
        if (v[i] == 2) ++c2;
        if (v[i] == 3) ++c3;
    }
    for (int i = 0; i < n; ++i) {
        int key;
        if (v[i] == 1) {
            if (0 <= i && i < c1) {
                continue;
            }
            else {
                key = (c1 <= i && i < c1 + c2) ? 2 : 3;
                solve(v, i, 0, c1, key);
            }
        } else if (v[i] == 2) {
            if (c1 <= i && i < c1+c2) {
                continue;
            }
            else {
                key = (0 <= i && i < c1) ? 1 : 3;
                solve(v, i, c1, c1+c2, key);
            }
        } else if (v[i] == 3) {
            if (c1+c2 <= i && i < c1+c2+c3) {
                continue;
            }
            else {
                key = (0 <= i && i < c1) ? 1 : 2;
                solve(v, i, c1+c2, c1+c2+c3, key);
            }
        }
    }

    // for (auto &e : v) cout << e << ' ';

    cout << c;

    return 0;
}
