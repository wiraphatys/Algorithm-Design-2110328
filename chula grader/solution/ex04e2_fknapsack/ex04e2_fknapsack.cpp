#include <bits/stdc++.h>
using namespace std;

int main(){
    double W;
    int n;
    cin >> W >> n;
    vector<double> v(n+1, 0), w(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> w[i];
    vector<pair<double, pair<double,double > > > fraction;
    for (int i = 1; i <= n; ++i) {
        fraction.push_back(make_pair(-v[i]/w[i], make_pair(v[i],w[i])));
    }
    sort(fraction.begin(), fraction.end());
    double totalValue = 0, remainWeight = W;
    for (auto &p : fraction) {
        if (remainWeight == 0) break;
        double itemValue = p.second.first, itemWeight = p.second.second;
        if (remainWeight >= itemWeight) {
            remainWeight -= itemWeight;
            totalValue += itemValue;
        } else {
            itemValue *= (remainWeight/itemWeight);
            totalValue += itemValue;
            remainWeight = 0;
        }
    }
    printf("%.4f", totalValue);
    return 0;
}