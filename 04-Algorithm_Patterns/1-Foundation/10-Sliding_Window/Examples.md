# Sliding Window - Worked Examples

Step-by-step reasoning for representative problems, one per variation.

---

## Example 1: Maximum Average Subarray I (Fixed-Size Window)

**Problem:** Find the contiguous subarray of length `k` with the maximum average.

**Reasoning:**
1. Brute force: for every starting index, sum the next `k` elements → O(n·k).
2. Instead, compute the sum of the first window once. For every subsequent window, subtract the element leaving (`nums[i-k]`) and add the element entering (`nums[i]`) - O(1) update per slide.
3. Track the maximum sum seen; divide by `k` at the end for the average.

```cpp
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
```
**Complexity:** O(n) time, O(1) space - vs O(n·k) brute force.

---

## Example 2: Longest Substring Without Repeating Characters (Variable - Longest)

**Problem:** Find the length of the longest substring without repeating characters.

**Reasoning:**
1. Brute force: check every substring for uniqueness → O(n²) or O(n³).
2. Track the last seen index of each character. Expand `right`; if the incoming character was seen **inside the current window**, jump `left` to just past that occurrence (shrink).
3. Because we only shrink when the window becomes invalid (a repeat appears), and we record the answer **after** ensuring validity, this is the "Longest" variant.

```cpp
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
```
**Complexity:** O(n) time (amortized - `left` moves forward at most n times total), O(1) space (fixed 256-array).

---

## Example 3: Minimum Size Subarray Sum (Variable - Shortest)

**Problem:** Find the minimal length of a contiguous subarray with sum ≥ target.

**Reasoning:**
1. Brute force: check every subarray's sum → O(n²).
2. Expand `right`, adding to a running sum. Once the sum meets/exceeds the target (window is **valid**), shrink `left` **as much as possible while it stays valid**, recording the minimum length at each valid step - this is the key difference from the "Longest" pattern: we record the answer *inside* the shrink loop, right before the window would become invalid.

```cpp
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
```
**Trace on nums = [2,3,1,2,4,3], target = 7:**
- right=0..3: sum accumulates to 2,5,6,8 - at right=3, sum=8 ≥ 7, shrink: remove 2→sum=6 (stop, <7). minLen=4 (window [2,3,1,2])
- right=4: sum=6+4=10 ≥7, shrink: remove 3→sum=7(≥7,minLen=min(4,4)=4,continue shrink)→remove1→sum=6(<7,stop). minLen stays 4 but window [1,2,4] len3 recorded before... (trace shows minLen ends at 2 for subarray [4,3])
- Final answer: 2 (subarray [4,3])

**Complexity:** O(n) time (amortized), O(1) space.

---

## Example 4: Sliding Window Maximum (Monotonic Deque Window)

**Problem:** For every window of size `k`, return the maximum element.

**Reasoning:**
1. Brute force: scan every window for its max → O(n·k).
2. Maintain a deque of **indices** where corresponding values are in decreasing order. The front of the deque is always the max of the current window.
3. Before adding a new index, pop from the back while its value is smaller than the incoming value (those elements can never be the max again, since the new element is both later and larger - they're dominated).
4. Pop from the front if it has slid out of the current window range.

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < (int)nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
```
**Trace on nums = [1,3,-1,-3,5,3,6,7], k=3:**
- Windows: [1,3,-1]→3, [3,-1,-3]→3, [-1,-3,5]→5, [-3,5,3]→5, [5,3,6]→6, [3,6,7]→7
- Result: [3,3,5,5,6,7] ✓

**Complexity:** O(n) time - each index is pushed and popped from the deque at most once (amortized), O(k) space for the deque.

---

## Example 5: Subarrays with Exactly K Different Integers (At-Most-K Trick)

**Problem:** Count the number of subarrays with exactly `k` distinct integers.

**Reasoning:**
1. Directly tracking "exactly k" with a simple shrink/grow window is awkward - the count of distinct integers isn't cleanly monotonic to shrink toward "exactly."
2. Instead, use the identity: `exactly(k) = atMost(k) - atMost(k-1)`.
3. `atMost(k)` is a standard "Longest" style window that, for each `right`, adds `right - left + 1` to the count (all subarrays ending at `right` with at most `k` distinct values are automatically counted this way).

```cpp
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
        count += right - left + 1;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
}
```
**Complexity:** O(n) time (two passes of the O(n) at-most-K window), O(k) space for the frequency map.

---

## Example 6: Find All Anagrams in a String (Fixed Window + Frequency Array)

**Problem:** Find all starting indices of `p`'s anagrams in `s`.

**Reasoning:**
1. Brute force: for every window of length `|p|`, sort and compare → O(n · k log k).
2. Instead, maintain a frequency array for `p` (`need`) and a frequency array for the current window (`window`), both size 26 (lowercase-only). Slide the window by adding the incoming character and removing the outgoing one once the window exceeds size `k`.
3. Compare `window == need` (direct array comparison, O(26) - effectively O(1)) at each valid window position.

```cpp
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
```
**Complexity:** O(n · 26) ≈ O(n) time (constant-size array comparison each step), O(1) space (fixed 26-size arrays).