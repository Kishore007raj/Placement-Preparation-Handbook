# Two Pointers - When to Use

## Core Signal
Use Two Pointers whenever you're tempted to write a **nested loop** (O(n²)) over an array/string/linked list, AND at least one of these is true:
- The data is **sorted** (or can be sorted without losing information you need).
- You're looking at a **contiguous window/subarray/substring**.
- You need to compare or combine elements from **both ends** of a structure.
- You're traversing a **linked list** and need positional information (middle, cycle, nth-from-end) without knowing the length upfront.
- You need to **partition or rearrange elements in place** based on a condition.

## Specific Scenarios

### 1. Sorted Array - Pair / Triplet Sum
When the array is sorted and you need to find pairs or triplets matching a sum/target, two pointers converging from both ends beats the O(n²) brute force by exploiting monotonicity: increasing left increases the sum, decreasing right decreases it.
> Use when: "sorted array", "find pair with sum", "3Sum", "4Sum".

### 2. Palindrome / Symmetric Checks
Comparing characters from outside-in is a direct two-pointer application - no need to reverse and compare.
> Use when: "check if palindrome", "valid palindrome ignoring case/punctuation".

### 3. Contiguous Subarray/Substring With a Condition
A window defined by `left` and `right` that expands and shrinks based on a running condition (sum, distinct count, frequency) - this is the "sliding window" flavor of two pointers.
> Use when: "longest/shortest subarray/substring with...", "minimum window containing...".

### 4. In-Place Array Modification
Removing duplicates, moving zeros, partitioning around a pivot - a slow pointer marks the "write position" while a fast pointer scans ahead.
> Use when: "remove duplicates in place", "move zeroes", "partition array", "in O(1) extra space".

### 5. Linked List Positional Problems
Fast and slow pointers moving at different speeds reveal structural properties (middle, cycle, nth node) in a single pass without needing to know the list's length in advance.
> Use when: "find the middle of a linked list", "detect a cycle", "nth node from the end", "find where a cycle begins".

### 6. Merging / Comparing Two Sorted Structures
Two separate pointers, one per structure, advancing based on comparison - used to merge sorted arrays/lists or find intersections.
> Use when: "merge two sorted arrays", "intersection of two sorted arrays", "merge sorted linked lists".

## When NOT to Use Two Pointers
- **Unsorted data where order/indices matter and sorting would lose that information** (e.g., classic "Two Sum" needing original indices) - prefer a **HashMap** instead.
- **Non-contiguous subsequence problems** (elements don't need to be adjacent) - usually need DP or backtracking instead.
- **Problems requiring lookahead/lookbehind across the whole structure repeatedly** - if the pointers would need to jump around non-monotonically, two pointers won't give you the O(n) guarantee; consider a different structure (stack, hashmap, heap).

## The One Question to Ask Yourself
> "As one pointer moves, does the answer change **monotonically** - that is, can I decide with certainty which pointer to move next without backtracking?"

If yes → Two Pointers is very likely the right tool.
If the decision of which pointer to move isn't clearly determined by a simple comparison, the pattern probably doesn't fit as-is.