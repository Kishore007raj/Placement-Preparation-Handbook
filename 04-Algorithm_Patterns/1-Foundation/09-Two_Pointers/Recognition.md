# Two Pointers - Recognition

How to go from reading a problem statement to identifying **which variation** of Two Pointers applies, in under 30 seconds.

## Recognition Checklist (run through in order)

### Step 1 - Is the input sorted, or can it be sorted?
- **Yes, and you need pair/triplet combos matching a target** → **Opposite-Direction Two Pointers**.
- **Yes, and you're merging with another sorted structure** → **Merge Pointers (one per structure)**.

### Step 2 - Is this about a contiguous window (subarray/substring)?
- **Fixed window size given** → **Sliding Window (fixed)**.
- **Variable window size, "longest/shortest ... satisfying condition"** → **Sliding Window (variable)**.

### Step 3 - Is this a linked list with positional/structural questions?
- **"middle of the list", "detect cycle", "nth from end"** → **Fast & Slow Pointers**.

### Step 4 - Do you need to modify the array in place based on a condition?
- **"remove duplicates", "move zeroes", "partition"** → **Slow/Fast Write-Read Pointers**.

### Step 5 - Does the problem need three or more coordinated values?
- **"3Sum", "sort colors / Dutch flag"** → **Three-Pointer variant** (fix one, two-pointer sweep the rest, or low/mid/high partition).

## Keyword-to-Variation Map

| Keywords in Problem Statement | Likely Variation |
|---|---|
| "sorted array", "pair with sum", "two numbers that add up to" | Opposite-Direction |
| "3Sum", "triplet", "closest sum" | Opposite-Direction (nested in a loop) |
| "container with most water", "trapping rain water" | Opposite-Direction |
| "palindrome" | Opposite-Direction |
| "subarray of size k" | Sliding Window (fixed) |
| "longest substring without repeating", "at most k distinct" | Sliding Window (variable) |
| "minimum window substring" | Sliding Window (variable) |
| "remove duplicates from sorted array" | Slow/Fast Write-Read |
| "move zeroes", "partition array around pivot" | Slow/Fast Write-Read |
| "middle of linked list" | Fast & Slow (different speeds) |
| "linked list cycle", "cycle detection", "Floyd's" | Fast & Slow (different speeds) |
| "nth node from the end" | Fast & Slow (offset start) |
| "merge two sorted arrays/lists" | Merge Pointers |
| "sort colors", "0s 1s 2s", "Dutch national flag" | Three-Pointer Partition |
| "reverse string/array in place" | Opposite-Direction (swap-based) |

## Disambiguation: Two Pointers vs Sliding Window vs Fast-Slow
These three are often confused because they all use two index variables - the distinguishing question:

- **Opposite-Direction Two Pointers**: pointers start at *opposite ends* and move *toward* each other. Used when order is fixed (sorted) and you're searching for a combination.
- **Sliding Window**: both pointers start at the *same end* and move in the *same direction*; the "window" between them represents a contiguous range you're actively growing/shrinking.
- **Fast & Slow Pointers**: both pointers start at the *same position* but move at *different speeds* in the *same direction* - used for structural/positional discovery (cycles, midpoints), not for combination search or windowing.

## Red Flag: When It Looks Like Two Pointers But Isn't
- If the array is unsorted and the problem needs the **original indices** of elements (not just their values) - sorting would destroy that information. Use a **HashMap** instead (see the Arrays/Hashing folder).
- If elements don't need to be **contiguous** or **adjacent** (a subsequence, not a subarray) - Two Pointers doesn't directly apply; consider DP.