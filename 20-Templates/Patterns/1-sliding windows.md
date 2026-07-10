Here's your DSA Patterns documentation in your preferred style, using Markdown:


# DSA Patterns - Sliding Window

## Definitions

The sliding window technique is a method for processing subarrays or substrings by using two pointers to define a window and efficiently sliding them through the sequence. There are two main types of sliding windows: **Fixed-sized sliding window** and **Dynamic-sized sliding window**.

---

### **1. Fixed Window**

**Definition**:  
In a **Fixed Window** problem, the size of the window remains constant. You are given a fixed window size (let's call it `k`), and you need to process a sequence (like an array or string) while keeping the window size the same.

**How it Works**:  
- Use two pointers: `low` (starting point of the window) and `high` (ending point of the window).
- The window size is fixed and does not change during the process.

**Template**:

```cpp
void fixed_window() {
    int low = 0, high = 0, windowSize = k;
    while (high < arraySize) {
        // Step 1: Expand the window until it reaches the desired size
        if (high - low + 1 < windowSize) {
            high++;  // Increase the right pointer (expand the window)
        }
        // Step 2: Process the window when it's the correct size
        else {
            // Perform the operation on the window (low to high)
            
            // Slide the window: move low pointer forward by 1 to create the next window
            low++;
        }
    }
}
```

**Key Points**:
- The window size stays constant at `k`.
- You process the window once it reaches the size `k` and then slide it by moving the `low` pointer forward.

---

### **2. Variable Window**

**Definition**:  
In a **Variable Window** problem, the window size can change dynamically depending on the conditions you are checking for. The window size is not fixed, and you expand or shrink it as needed.

**How it Works**:
- You still use two pointers: `start` (left pointer) and `end` (right pointer).
- The window size is adjusted based on certain conditions, expanding and shrinking as needed.

**Template**:

```cpp
void variable_window() {
    int start = 0, end = 0;
    while (end < n) {  // Loop through the entire sequence
        // Step 1: Expand the window (increase end pointer) if needed
        if (end - start + 1 < k) {
            end++;  // Expand the window by moving the end pointer forward
        }

        // Step 2: If the window size is correct, process it
        else if (end - start + 1 == k) {
            // Process the window (start to end)
            
            end++;  // Move the end pointer to check for the next window
        }

        // Step 3: Shrink the window if it's too large
        else if (end - start + 1 > k) {
            while (end - start + 1 > k) {
                // Shrink the window by moving the start pointer forward
                start++;
            }

            // Once window size is fixed, process the window
            if (end - start + 1 == k) {
                // Perform the required operation
            }

            end++;  // Move end to continue checking the next window
        }
    }
}
```

**Key Points**:
- The window size can grow or shrink based on conditions.
- You keep adjusting the window size by moving either the `start` or `end` pointer.
- The window is processed when it meets a certain condition (like reaching a size `k`).

---

## **Comparison of Sliding Window Approaches**

| **Approach**                        | **Time Complexity** | **Space Complexity** | **Efficiency**                      |
|-------------------------------------|---------------------|----------------------|-------------------------------------|
| Brute Force                         | O(n²)               | O(1)                 | Simple but inefficient for large arrays |
| Sliding Window (Fixed Size)         | O(n)                | O(1)                 | Efficient for fixed window size problems |
| Sliding Window with Hash            | O(n)                | O(k)                 | Ideal for tracking frequencies or distinct elements |
| Two Pointer                         | O(n)                | O(1)                 | Efficient for sum/range-based problems |

---

## **Approaches Explained**

### **1) Brute Force Approach**

**Definition**: A brute force approach where we try all possible subarrays or windows and check for the condition.  
**When to Use**: When the problem is small or when no specific optimized solution is available.

**Pseudocode**:

```cpp
function brute_force(nums):
    max_sum = 0
    for left from 0 to len(nums)-1:
        for right from left to len(nums):
            current_sum = sum(nums[left:right+1])
            max_sum = max(max_sum, current_sum)
    return max_sum
```

**Code (C++)**:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int brute_force(const vector<int>& nums) {
    int max_sum = 0;
    for (int left = 0; left < nums.size(); left++) {
        for (int right = left; right < nums.size(); right++) {
            int current_sum = 0;
            for (int i = left; i <= right; i++) {
                current_sum += nums[i];
            }
            max_sum = max(max_sum, current_sum);
        }
    }
    return max_sum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Brute Force: " << brute_force(nums) << endl;
    return 0;
}
```

---

### **2) Sliding Window (Fixed Size)**

**Definition**: A sliding window where we use a hash table (or dictionary) to track the frequency of elements inside the window.  
**Use**: When you have a fixed size for the subarray or window.

**Pseudocode**:

```cpp
function sliding_window(nums, k):
    left = 0
    sum = 0
    max_len = 0
    for right from 0 to len(nums)-1:
        sum += nums[right]
        if right - left + 1 == k:
            max_len = max(max_len, sum)
            sum -= nums[left]
            left += 1
    return max_len
```

**Code (C++)**:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sliding_window(const vector<int>& nums, int k) {
    int left = 0;
    int sum = 0;
    int max_len = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        
        if (right - left + 1 == k) {
            max_len = max(max_len, sum);
            sum -= nums[left];
            left++;
        }
    }
    
    return max_len;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    cout << "Sliding Window (Fixed Size): " << sliding_window(nums, k) << endl;
    return 0;
}
```

---

### **3) Sliding Window with Hash Table (Tracking Frequencies)**

**Definition**: A sliding window where we use a hash table (or dictionary) to track the frequency of elements inside the window.  
**Use**: When you need to track the number of distinct elements or other conditions within a window.

**Pseudocode**:

```cpp
function sliding_window_with_hash(nums, k):
    left = 0
    freq_map = {}
    max_len = 0
    for right from 0 to len(nums)-1:
        freq_map[nums[right]] += 1
        while len(freq_map) > k:
            freq_map[nums[left]] -= 1
            if freq_map[nums[left]] == 0:
                freq_map.erase(nums[left])
            left += 1
        max_len = max(max_len, right - left + 1)
    return max_len
```

**Code (C++)**:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int sliding_window_with_hash(const vector<int>& nums, int k) {
    int left = 0;
    unordered_map<int, int> freq_map;
    int max_len = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        freq_map[nums[right]]++;
        
        while (freq_map.size() > k) {
            freq_map[nums[left]]--;
            if (freq_map[nums[left]] == 0) {
                freq_map.erase(nums[left]);
            }
            left++;
        }
        
        max_len = max(max_len, right - left + 1);
    }
    
    return max_len;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Sliding Window with Hash: " << sliding_window_with_hash(nums, k) << endl;
    return 0;
}
```

---

### **4) Two Pointer Approach**

**Definition**: A technique where we use two pointers (left and right) to track a range of elements in the array and adjust the range based on a condition.  
**Use**: When you are dealing with problems related to ranges (e.g., finding subarrays with a sum less than a given threshold).

**Pseudocode**:

```cpp
function two_pointer(nums):
    left = 0
    max_sum = 0
    for right from 0 to len(nums)-1:
        window_sum = sum(nums[left:right+1])
        while window_sum > some_limit:
            left += 1


            window_sum = sum(nums[left:right+1])
        max_sum = max(max_sum, window_sum)
    return max_sum
```

**Code (C++)**:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int two_pointer(const vector<int>& nums) {
    int left = 0;
    int max_sum = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        int window_sum = 0;
        for (int i = left; i <= right; i++) {
            window_sum += nums[i];
        }
        while (window_sum > 10) {
            left++;
            window_sum = 0;
            for (int i = left; i <= right; i++) {
                window_sum += nums[i];
            }
        }
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Two Pointer Approach: " << two_pointer(nums) << endl;
    return 0;
}
```

---

This should give you a structured and efficient guide to DSA Sliding Window patterns!