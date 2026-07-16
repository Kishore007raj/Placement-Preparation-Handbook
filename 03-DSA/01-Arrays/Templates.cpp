// ============================================================
// 01 - ARRAYS & HASHING : ALL PATTERN TEMPLATES (C++)
// Copy-paste ready. Each block is self-contained.
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// 1. PREFIX SUM
// ------------------------------------------------------------
vector<long long> buildPrefix(vector<int>& nums) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    return prefix;
}
// range sum [l, r] inclusive = prefix[r+1] - prefix[l]

int subarraySum(vector<int>& nums, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;
    long long sum = 0; int count = 0;
    for (int num : nums) {
        sum += num;
        if (freq.count(sum - k)) count += freq[sum - k];
        freq[sum]++;
    }
    return count;
}

// ------------------------------------------------------------
// 2. TWO POINTERS
// ------------------------------------------------------------
bool pairSumSorted(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++; right--;
            } else if (sum < 0) left++;
            else right--;
        }
    }
    return res;
}

// ------------------------------------------------------------
// 3. SLIDING WINDOW - FIXED SIZE
// ------------------------------------------------------------
double maxAvgSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    long long windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i];
    long long maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return (double)maxSum / k;
}

// ------------------------------------------------------------
// 4. SLIDING WINDOW - VARIABLE SIZE
// ------------------------------------------------------------
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];
        if (lastSeen.count(c) && lastSeen[c] >= left) left = lastSeen[c] + 1;
        lastSeen[c] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, n = nums.size();
    long long sum = 0;
    int minLen = INT_MAX;
    for (int right = 0; right < n; right++) {
        sum += nums[right];
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

// ------------------------------------------------------------
// 5. CYCLIC SORT / FAST-SLOW ON ARRAY
// ------------------------------------------------------------
void cyclicSort(vector<int>& nums) {
    int i = 0, n = nums.size();
    while (i < n) {
        int correctIdx = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx])
            swap(nums[i], nums[correctIdx]);
        else i++;
    }
}

int firstMissingPositive(vector<int>& nums) {
    cyclicSort(nums);
    for (int i = 0; i < (int)nums.size(); i++)
        if (nums[i] != i + 1) return i + 1;
    return nums.size() + 1;
}

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++)
        while (nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < n; i++)
        if (nums[i] != i + 1) return {nums[i], i + 1};
    return {};
}

// ------------------------------------------------------------
// 6. HASHING - FREQUENCY COUNTING
// ------------------------------------------------------------
unordered_map<int,int> countFreq(vector<int>& nums) {
    unordered_map<int,int> freq;
    for (int num : nums) freq[num]++;
    return freq;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto& [k, v] : groups) res.push_back(v);
    return res;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto& [num, cnt] : freq) buckets[cnt].push_back(num);
    vector<int> res;
    for (int i = buckets.size() - 1; i >= 0 && (int)res.size() < k; i--)
        for (int num : buckets[i]) {
            res.push_back(num);
            if ((int)res.size() == k) break;
        }
    return res;
}

// ------------------------------------------------------------
// 7. HASHMAP - COMPLEMENT / PAIR SEARCH
// ------------------------------------------------------------
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen;
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}

int countPairsWithDiff(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;
    int count = 0;
    for (auto& [num, c] : freq) {
        if (k == 0) { if (c > 1) count += 1; }
        else if (freq.count(num + k)) count += c * freq[num + k];
    }
    return count;
}

// ------------------------------------------------------------
// 8. KADANE'S ALGORITHM
// ------------------------------------------------------------
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], curSum = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        curSum = max(nums[i], curSum + nums[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int maxProduct(vector<int>& nums) {
    int maxProd = nums[0], minProd = nums[0], result = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        int cur = nums[i];
        if (cur < 0) swap(maxProd, minProd);
        maxProd = max(cur, maxProd * cur);
        minProd = min(cur, minProd * cur);
        result = max(result, maxProd);
    }
    return result;
}

// ------------------------------------------------------------
// 9. DUTCH NATIONAL FLAG (SORT COLORS)
// ------------------------------------------------------------
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) { swap(nums[low], nums[mid]); low++; mid++; }
        else if (nums[mid] == 1) mid++;
        else { swap(nums[mid], nums[high]); high--; }
    }
}

// ------------------------------------------------------------
// 10. MONOTONIC STACK
// ------------------------------------------------------------
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

vector<int> dailyTemperatures(vector<int>& temps) {
    int n = temps.size();
    vector<int> result(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temps[st.top()] < temps[i]) {
            int idx = st.top(); st.pop();
            result[idx] = i - idx;
        }
        st.push(i);
    }
    return result;
}

// ============================================================
// END OF TEMPLATES
// ============================================================