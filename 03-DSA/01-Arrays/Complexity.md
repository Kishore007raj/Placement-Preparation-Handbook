# 01 - Arrays & Hashing - Complexity Reference

## Per-Pattern Complexity

| Pattern | Best Case | Average | Worst Case | Space | Notes |
|---|---|---|---|---|---|
| Prefix Sum (build) | O(n) | O(n) | O(n) | O(n) | O(1) per query after build |
| Prefix Sum + HashMap (subarray sum = k) | O(n) | O(n) | O(n) | O(n) | hash collisions rare in practice |
| Two Pointers (sorted) | O(n) | O(n) | O(n) | O(1) | + O(n log n) if sorting needed first |
| 3Sum | O(n²) | O(n²) | O(n²) | O(1) extra | sort dominates lower bound |
| Sliding Window (fixed k) | O(n) | O(n) | O(n) | O(1) | |
| Sliding Window (variable) | O(n) | O(n) | O(n) | O(k) | amortized: each pointer moves ≤ n times |
| Cyclic Sort | O(n) | O(n) | O(n) | O(1) | each element swapped into place at most once |
| Frequency Counting (unordered_map) | O(n) | O(n) | O(n²) worst-case (rare) | O(n) | worst case only with pathological hash collisions |
| Frequency Counting (fixed array, e.g. 26 letters) | O(n) | O(n) | O(n) | O(1) | no hashing overhead |
| Group Anagrams | O(n·k log k) | O(n·k log k) | O(n·k log k) | O(n·k) | k = avg string length |
| Top-K Frequent (bucket sort) | O(n) | O(n) | O(n) | O(n) | avoids O(n log n) full sort |
| Two Sum (HashMap) | O(n) | O(n) | O(n) | O(n) | vs O(n²) brute force |
| Kadane's Algorithm | O(n) | O(n) | O(n) | O(1) | single pass |
| Dutch National Flag | O(n) | O(n) | O(n) | O(1) | single pass, 3 pointers |
| Monotonic Stack | O(n) | O(n) | O(n) | O(n) | amortized - each index pushed/popped once |

## General Complexity Rules of Thumb
- **Brute force nested loop** on array problems: O(n²). If asked for better, think **HashMap** (trade space for time) or **sort + two pointers**.
- **Sorting cost**: O(n log n) - acceptable unless the problem explicitly needs O(n) (then think hashing / counting sort / cyclic sort).
- **HashMap operations**: treated as O(1) in interviews by convention, but mention the O(n) worst case (collisions) if asked to be rigorous.
- **Recursion/backtracking** (not core to this topic but often layered on arrays): watch for exponential blowup - usually needs memoization to become polynomial.

## Space Complexity Traps
- Recomputing prefix sums or sorting *in place* can save O(n) space - always ask "can I avoid the extra array?"
- `unordered_map` has real memory overhead per entry (buckets, pointers) - for small fixed domains (like ASCII/lowercase letters), a plain array is both faster and smaller.
- Output arrays (the answer itself) are usually **not** counted toward extra space complexity unless explicitly stated.

## Quick Comparison: When O(n) Beats O(n log n)
| Situation | Prefer |
|---|---|
| Need indices/order preserved, unsorted allowed | HashMap - O(n) |
| Can destroy input order, values bounded [1..n] | Cyclic Sort - O(n), O(1) space |
| Values bounded to small range (e.g. 0-100) | Counting Sort - O(n + range) |
| General purpose, values unbounded, order doesn't matter | Sort + Two Pointers - O(n log n), O(1) space |