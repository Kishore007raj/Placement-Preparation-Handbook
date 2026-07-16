# 01 - Arrays & Hashing — Cheatsheet

Quick-glance table. Full detail in `Patterns.md`.

| # | Pattern | Trigger Keywords | Core Idea | Time | Space |
|---|---|---|---|---|---|
| 1 | Prefix Sum | "range sum", "subarray sum = k" | precompute cumulative sums; use HashMap for count of subarrays | O(n) | O(n) |
| 2 | Two Pointers | "sorted array", "pair/triplet sum" | move left/right pointer based on comparison to target | O(n) or O(n log n) | O(1) |
| 3 | Sliding Window (Fixed) | "subarray of size k" | maintain running sum, add new / remove old | O(n) | O(1) |
| 4 | Sliding Window (Variable) | "longest/shortest subarray with condition" | expand right, shrink left when invalid | O(n) | O(k) |
| 5 | Cyclic Sort | "numbers from 1 to n", "missing/duplicate number" | place nums[i] at index nums[i]-1 | O(n) | O(1) |
| 6 | Hashing - Frequency | "anagram", "majority element", "top k frequent" | count with map/array, bucket sort for top-k | O(n) | O(n) |
| 7 | HashMap Pair Search | "two sum", "count pairs with diff k" | store seen values, check complement | O(n) | O(n) |
| 8 | Kadane's Algorithm | "max subarray sum/product" | track running best, reset when negative | O(n) | O(1) |
| 9 | Dutch National Flag | "sort colors", "0s 1s 2s" | 3-pointer in-place partition | O(n) | O(1) |
| 10 | Monotonic Stack | "next greater/smaller element" | stack of indices, pop when order violated | O(n) | O(n) |

## Decision Flowchart (fast triage)
```
Is the array SORTED (or can be sorted without losing needed info)?
 ├─ YES → pair/triplet sum? → Two Pointers
 │        need position of two elements & unsorted required? → HashMap
 └─ NO  → Does it involve CONTIGUOUS SUBARRAY?
           ├─ Fixed length k → Sliding Window (Fixed)
           ├─ Variable length with a condition → Sliding Window (Variable)
           ├─ Sum-based query, possibly negative numbers → Prefix Sum (+HashMap)
           └─ Max/min sum or product → Kadane's Algorithm
          Does it involve VALUES BOUNDED BY [1..n]?
           └─ YES → Cyclic Sort
          Does it need "next greater/smaller" relation?
           └─ YES → Monotonic Stack
          Does it need frequency / grouping / duplicates?
           └─ YES → Hashing (frequency map)
```

## STL Quick Reference (C++)
```cpp
unordered_map<int,int> m;      // avg O(1) insert/find/erase
map<int,int> m;                 // O(log n), sorted keys
unordered_set<int> s;           // avg O(1) membership
sort(v.begin(), v.end());       // O(n log n)
*max_element(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0LL);
stack<int> st; st.top(); st.pop(); st.push(x);
```

## Common Gotchas
- Overflow: use `long long` for prefix sums / products when values can be large.
- `unordered_map[key]` **auto-creates** an entry with default value if key doesn't exist — use `.count(key)` or `.find(key)` to check without inserting.
- Two Sum: check complement **before** inserting current element (avoid using same index twice).
- Kadane's: initialize `maxSum = nums[0]`, not 0 (handles all-negative arrays).
- Sliding window (variable): only valid when shrinking monotonically fixes the violated condition; breaks with negative numbers unless adapted.