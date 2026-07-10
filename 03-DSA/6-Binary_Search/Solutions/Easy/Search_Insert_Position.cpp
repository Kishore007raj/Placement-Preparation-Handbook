#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given a sorted array of distinct integers and a target value, return the index
if the target is found. Otherwise, return the index where it would be inserted.

Approach:
Use binary search and maintain the insertion position.

Thought Process:
We need the first position where target could be inserted while keeping order.

Algorithm:
1. Initialize low = 0 and high = n.
2. While low < high:
   - mid = low + (high - low) / 2
   - If nums[mid] < target, move low to mid + 1
   - Otherwise move high to mid
3. Return low.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int searchInsert(vector<int> &nums, int target)
{
    int low = 0, high = (int)nums.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 5) << "\n";
    cout << searchInsert(nums, 2) << "\n";
    return 0;
}
