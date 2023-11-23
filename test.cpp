#include <iostream>
#include <vector>
using namespace std;

int threeValuesSort(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1, swaps = 0, i = 0;

    while (i <= right)
    {
        if (arr[i] == 1)
        {
            swap(arr[i], arr[left]);
            left++;
            swaps++;
            i++;
        }
        else if (arr[i] == 3)
        {
            swap(arr[i], arr[right]);
            right--;
            swaps++;
        }
        else
        {
            i++;
        }
    }

    return swaps;
}

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    int minSwaps = threeValuesSort(array);
    cout << minSwaps << endl;

    return 0;
}
