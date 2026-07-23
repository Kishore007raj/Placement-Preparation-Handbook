# Two Pointers - Worked Examples

Step-by-step reasoning for representative problems, one per variation.

---

## Example 1: Two Sum II - Input Array Is Sorted (Opposite-Direction)

**Problem:** Given a sorted array, find two numbers that add up to a target. Return their 1-indexed positions.

**Reasoning:**
1. Brute force would check every pair → O(n²).
2. Array is sorted → if `nums[left] + nums[right] > target`, the only way to decrease the sum is to move `right` left (since moving `left` right would increase or keep the sum, moving away from a fix). Similarly, if the sum is too small, move `left` right.
3. This works because the array is sorted - every move is "safe" (never skips a valid answer).

```cpp
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {left + 1, right + 1};
        else if (sum < target) left++;
        else right--;
    }
    return {};
}
```
**Complexity:** O(n) time, O(1) space - vs O(n²) brute force or O(n) time + O(n) space with a HashMap (viable alternative if array weren't sorted).

---

## Example 2: Longest Substring Without Repeating Characters (Sliding Window)

**Problem:** Find the length of the longest substring without repeating characters.

**Reasoning:**
1. Brute force: check every substring for uniqueness → O(n³) (or O(n²) with a smarter check).
2. Use a window `[left, right]`; expand `right` one character at a time.
3. Track the last seen index of each character. If the character at `right` was seen **inside the current window** (`lastSeen[c] >= left`), jump `left` to just after that occurrence - this instantly invalidates the repeat without rescanning.
4. Track the max window size seen so far.

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
**Trace on "abcabcbb":**
- right=0 ('a'): lastSeen['a']=-1 < left(0) → no jump. window="a", len=1
- right=1 ('b'): similar → window="ab", len=2
- right=2 ('c'): window="abc", len=3
- right=3 ('a'): lastSeen['a']=0 >= left(0) → left=1. window="bca", len=3
- right=4 ('b'): lastSeen['b']=1 >= left(1) → left=2. window="cab", len=3
- ... final answer: 3

**Complexity:** O(n) time (each pointer moves forward only), O(1) space (fixed 256-array).

---

## Example 3: Linked List Cycle Detection (Fast & Slow)

**Problem:** Determine if a linked list has a cycle, without extra space.

**Reasoning:**
1. Naive approach: store visited nodes in a HashSet → O(n) space.
2. Better: use two pointers moving at different speeds. If there's no cycle, `fast` reaches `nullptr` and we return false.
3. If there **is** a cycle, `fast` (moving 2x speed) will eventually "lap" `slow` inside the cycle and they will meet - this is a mathematical guarantee (the gap between them decreases by 1 each step once both are in the cycle).

```cpp
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```
**Complexity:** O(n) time, O(1) space - a direct improvement over the O(n) space HashSet approach.

---

## Example 4: Move Zeroes (Slow/Fast Write-Read)

**Problem:** Move all zeroes to the end while maintaining the relative order of non-zero elements, in place.

**Reasoning:**
1. Brute force: build a new array with non-zero elements first, then pad with zeroes → O(n) space.
2. In-place approach: `slow` tracks the position where the next non-zero element should go. `fast` scans every element.
3. Whenever `fast` finds a non-zero, swap it into the `slow` position and advance `slow`. Zeroes naturally get pushed toward the end because they're the only elements left un-swapped-forward.

```cpp
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}
```
**Trace on [0,1,0,3,12]:**
- fast=0 (0): skip
- fast=1 (1): swap(nums[0], nums[1]) → [1,0,0,3,12], slow=1
- fast=2 (0): skip
- fast=3 (3): swap(nums[1], nums[3]) → [1,3,0,0,12], slow=2
- fast=4 (12): swap(nums[2], nums[4]) → [1,3,12,0,0], slow=3
- Final: [1,3,12,0,0] ✓

**Complexity:** O(n) time, O(1) space.

---

## Example 5: Merge Sorted Array In Place (Merge Pointers)

**Problem:** `nums1` has size `m + n` with the last `n` slots empty; merge `nums2` (size n) into `nums1` in sorted order, in place.

**Reasoning:**
1. Merging from the **front** would require shifting elements repeatedly (O(n²)).
2. Instead, merge from the **back**: since `nums1` has empty trailing space, place the largest remaining element (from either array) at the end, working backward. No shifting needed.

```cpp
void mergeInPlace(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}
```
**Complexity:** O(m + n) time, O(1) space - vs O((m+n)²) if shifting were needed from the front.

---

## Example 6: Sort Colors (Three-Pointer Partition)

**Problem:** Sort an array of 0s, 1s, and 2s in place, in one pass.

**Reasoning:**
1. A generic sort would be O(n log n); counting sort (two passes) is O(n) but needs to know counts first.
2. Dutch National Flag does it in **one pass**, O(n) time, O(1) space: `low` boundary for 0s, `high` boundary for 2s, `mid` scans and decides where to swap.
3. Key subtlety: after swapping `mid` with `high`, do **not** advance `mid` - the newly swapped-in value at `mid` hasn't been checked yet.

```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) { swap(nums[low], nums[mid]); low++; mid++; }
        else if (nums[mid] == 1) mid++;
        else { swap(nums[mid], nums[high]); high--; }
    }
}
```
**Complexity:** O(n) time (single pass), O(1) space.