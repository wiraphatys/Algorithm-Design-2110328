#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void solve(int n, int step, string &str, string &consecutive) {
    if (step < n) {
        str += '0';
        solve(n, step+1, str, consecutive);
        str.pop_back();
        str += '1';
        solve(n, step+1, str, consecutive);
        str.pop_back();
        return;
    }
    if (str.find(consecutive) != -1) cout << str << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;

    string str;
    string consecutive(k,'1');
    solve(n, 0, str, consecutive);
    return 0;
}
