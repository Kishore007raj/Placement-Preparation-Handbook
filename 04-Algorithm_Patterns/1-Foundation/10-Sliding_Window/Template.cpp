// ============================================================
// SLIDING WINDOW : ALL VARIATION TEMPLATES (C++)
// Copy-paste ready. Each block is self-contained.
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// 1. FIXED-SIZE WINDOW
// ------------------------------------------------------------

// Max sum of k consecutive elements
long long maxSumFixedWindow(vector<int>& nums, int k) {
    long long windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i];
    long long maxSum = windowSum;
    for (int i = k; i < (int)nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

// Max average of a subarray of size k
double findMaxAverage(vector<int>& nums, int k) {
    long long windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i];
    long long maxSum = windowSum;
    for (int i = k; i < (int)nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return (double)maxSum / k;
}

// ------------------------------------------------------------
// 2. VARIABLE-SIZE WINDOW - LONGEST VALID RANGE
// ------------------------------------------------------------

// Longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    vector<int> lastSeen(256, -1);
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (lastSeen[s[right]] >= left) left = lastSeen[s[right]] + 1;
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// Longest subarray with sum <= target (non-negative values only)
int longestSubarraySumAtMost(vector<int>& nums, int target) {
    int left = 0, n = nums.size();
    long long sum = 0;
    int maxLen = 0;
    for (int right = 0; right < n; right++) {
        sum += nums[right];
        while (sum > target) {
            sum -= nums[left++];
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// Longest substring with at most K distinct characters
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        freq[s[right]]++;
        while ((int)freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// Longest Repeating Character Replacement
int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int left = 0, maxFreq = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        count[s[right] - 'A']++;
        maxFreq = max(maxFreq, count[s[right] - 'A']);
        // window invalid if replacements needed exceed k
        while ((right - left + 1) - maxFreq > k) {
            count[s[left] - 'A']--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// ------------------------------------------------------------
// 3. VARIABLE-SIZE WINDOW - SHORTEST VALID RANGE
// ------------------------------------------------------------

// Minimum size subarray with sum >= target
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

// Minimum Window Substring
string minWindow(string s, string t) {
    vector<int> need(128, 0);
    for (char c : t) need[c]++;
    int required = t.size();
    int left = 0, bestLen = INT_MAX, bestStart = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (need[s[right]]-- > 0) required--;
        while (required == 0) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
            if (++need[s[left]] > 0) required++;
            left++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}

// ------------------------------------------------------------
// 4. MONOTONIC DEQUE WINDOW (SLIDING WINDOW MAX/MIN)
// ------------------------------------------------------------

// Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices, decreasing values
    vector<int> result;
    for (int i = 0; i < (int)nums.size(); i++) {
        // remove indices out of the window
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // maintain decreasing order
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

// Sliding Window Minimum (symmetric - increasing deque)
vector<int> minSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices, increasing values
    vector<int> result;
    for (int i = 0; i < (int)nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] > nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

// ------------------------------------------------------------
// 5. AT-MOST-K TRICK (EXACTLY-K TRANSFORMATION)
// ------------------------------------------------------------

// Helper: count subarrays with at most K distinct integers
int atMostKDistinct(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int,int> freq;
    int left = 0, count = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        freq[nums[right]]++;
        while ((int)freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) freq.erase(nums[left]);
            left++;
        }
        count += right - left + 1; // all subarrays ending at right with <= k distinct
    }
    return count;
}

// Subarrays with Exactly K Different Integers
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
}

// ------------------------------------------------------------
// 6. FIXED-SIZE WINDOW + FREQUENCY ARRAY (ANAGRAM/PERMUTATION)
// ------------------------------------------------------------

// Find All Anagrams in a String
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) return result;
    vector<int> need(26, 0), window(26, 0);
    for (char c : p) need[c - 'a']++;
    int k = p.size();
    for (int i = 0; i < (int)s.size(); i++) {
        window[s[i] - 'a']++;
        if (i >= k) window[s[i - k] - 'a']--;
        if (i >= k - 1 && window == need) result.push_back(i - k + 1);
    }
    return result;
}

// Permutation in String
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> need(26, 0), window(26, 0);
    for (char c : s1) need[c - 'a']++;
    int k = s1.size();
    for (int i = 0; i < (int)s2.size(); i++) {
        window[s2[i] - 'a']++;
        if (i >= k) window[s2[i - k] - 'a']--;
        if (i >= k - 1 && window == need) return true;
    }
    return false;
}

// ============================================================
// END OF TEMPLATES
// ============================================================