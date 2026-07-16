#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearch(const vector<int> &arr, int target)
{
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Lower Bound: first index where arr[i] >= target
int lowerBound(const vector<int> &arr, int target)
{
    int low = 0, high = (int)arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

// Upper Bound: first index greater than target
int upperBound(const vector<int> &arr, int target)
{
    int low = 0, high = (int)arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    cout << binarySearch(arr, 7) << "\n";
    cout << lowerBound(arr, 5) << "\n";
    cout << upperBound(arr, 5) << "\n";
    return 0;
}
