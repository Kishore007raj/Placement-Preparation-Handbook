// ============================================================
// TWO POINTERS : ALL VARIATION TEMPLATES (C++)
// Copy-paste ready. Each block is self-contained.
// ============================================================
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ------------------------------------------------------------
// 1. OPPOSITE-DIRECTION (CONVERGING POINTERS)
// ------------------------------------------------------------

// Pair sum in sorted array
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

// 3Sum - all unique triplets summing to 0
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

// Container With Most Water
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1, best = 0;
    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        best = max(best, area);
        if (height[left] < height[right]) left++;
        else right--;
    }
    return best;
}

// Trapping Rain Water
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
            left++;
        } else {
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

// Valid Palindrome (ignore non-alphanumeric, case-insensitive)
bool isPalindromeAlnum(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

// Reverse array/string in place
void reverseInPlace(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) swap(nums[left++], nums[right--]);
}

// ------------------------------------------------------------
// 2. SLIDING WINDOW (SAME-DIRECTION, CATCH-UP)
// ------------------------------------------------------------

// Fixed-size: max sum of k consecutive elements
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

// Variable-size: longest substring without repeating characters
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

// Variable-size: minimum size subarray with sum >= target
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
// 3. FAST & SLOW POINTERS (LINKED LIST)
// ------------------------------------------------------------

// Middle of Linked List
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Linked List Cycle Detection (Floyd's)
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Find start of the cycle
ListNode* detectCycleStart(ListNode* head) {
    ListNode *slow = head, *fast = head;
    bool hasCyc = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { hasCyc = true; break; }
    }
    if (!hasCyc) return nullptr;
    slow = head;
    while (slow != fast) { slow = slow->next; fast = fast->next; }
    return slow; // start of cycle
}

// Nth node from the end (offset-start fast pointer)
ListNode* nthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++) fast = fast->next; // offset fast by n
    if (!fast) return head; // n == length, remove head case
    while (fast->next) { fast = fast->next; slow = slow->next; }
    return slow->next; // node to remove/target, adjust per exact problem
}

// ------------------------------------------------------------
// 4. SLOW/FAST WRITE-READ POINTERS (IN-PLACE MODIFICATION)
// ------------------------------------------------------------

// Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < (int)nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1; // new length
}

// Move Zeroes (preserve relative order of non-zero elements)
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

// Remove Element (remove all instances of val in place)
int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

// ------------------------------------------------------------
// 5. MERGE POINTERS (TWO SORTED STRUCTURES)
// ------------------------------------------------------------

// Merge Two Sorted Arrays into a new array
vector<int> mergeSortedArrays(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < (int)a.size()) result.push_back(a[i++]);
    while (j < (int)b.size()) result.push_back(b[j++]);
    return result;
}

// Merge Sorted Array in place (nums1 has extra trailing space)
void mergeInPlace(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}

// Intersection of Two Sorted Arrays
vector<int> intersectSorted(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] == b[j]) { result.push_back(a[i]); i++; j++; }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    return result;
}

// ------------------------------------------------------------
// 6. THREE-POINTER PARTITION (DUTCH NATIONAL FLAG)
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
// 7. TWO POINTERS ON TWO DIFFERENT ARRAYS (NON-MERGE)
// ------------------------------------------------------------

// Is Subsequence
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == (int)s.size();
}

// ============================================================
// END OF TEMPLATES
// ============================================================