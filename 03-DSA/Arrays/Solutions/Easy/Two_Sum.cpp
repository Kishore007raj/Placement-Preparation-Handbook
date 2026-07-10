#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given an array of integers and a target value, return indices of the two numbers
that add up to the target.

Approach:
Use an unordered_map to store seen values and their indices.

Thought Process:
For each number x, we need the complement target - x.
If it has been seen before, we found the pair.

Algorithm:
1. Traverse the array.
2. For each value x, check if target - x exists in the map.
3. If it exists, return the stored index and current index.
4. Otherwise, store x with its index.

Time Complexity: O(n)
Space Complexity: O(n)
*/

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < (int)nums.size(); ++i)
    {
        int complement = target - nums[i];
        if (mp.count(complement))
        {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = twoSum(nums, 9);
    for (int x : result)
        cout << x << " ";
    cout << "\n";
    return 0;
}
