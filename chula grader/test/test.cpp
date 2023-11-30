#include <bits/stdc++.h>
using namespace std;

int c = 0;

void A(double n) {
    if (n <= 1) return;
    A(sqrt(n));
    c++;
}

int main() {
    unsigned long long x = -1;
    A(x);
    cout << c;
    return 0;
}