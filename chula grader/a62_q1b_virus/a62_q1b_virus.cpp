#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, k, len;

bool isDOVIC(int begin, int end, bool rev){ 
    int digit = end-begin;
    int mid = (begin+end)/2;
    if (digit == 2) {
        if (!rev) return v[begin] == 0 && v[begin+1] == 1;
        else return v[begin] == 1 && v[begin+1] == 0;
    }
    if (!rev) {
        return (isDOVIC(begin, mid, false) || isDOVIC(begin, mid, true)) && isDOVIC(mid, end, false);
    } else {
        return (isDOVIC(mid, end, false) || isDOVIC(mid, end, true)) && isDOVIC(begin, mid, true);
    }
}

int main() {
    cin >> n >> k;
    len = pow(2, k);
    v = vector<int>(len);
    while (n--) {
        for (int i = 0; i < len; ++i) {
            cin >> v[i];
        }
        cout << (isDOVIC(0, len, false) ? "yes\n" : "no\n");
    }
    return 0;
}