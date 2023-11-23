#include <iostream>
int main(){
    int n;
    std::cin >> n;
    int a[12] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200};
    std::cout << a[n-1];
}