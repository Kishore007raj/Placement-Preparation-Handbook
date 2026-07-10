#include <bits/stdc++.h>
using namespace std;

// Traverse an array
void printArray(const vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

// Find maximum element
int findMax(const vector<int> &arr)
{
    int mx = arr[0];
    for (int x : arr)
        mx = max(mx, x);
    return mx;
}

// Find sum of array
int sumArray(const vector<int> &arr)
{
    int sum = 0;
    for (int x : arr)
        sum += x;
    return sum;
}

// Reverse an array in-place
void reverseArray(vector<int> &arr)
{
    int l = 0, r = (int)arr.size() - 1;
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    printArray(arr);
    cout << findMax(arr) << "\n";
    cout << sumArray(arr) << "\n";
    reverseArray(arr);
    printArray(arr);
    return 0;
}
