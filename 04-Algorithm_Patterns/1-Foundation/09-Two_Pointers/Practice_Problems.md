# Two Pointers - Practice Problems

Curated list, organized by difficulty and tagged with the variation used. Solve each twice: brute force first, then optimal two-pointer solution.

## Easy

| Problem | Variation |
|---|---|
| Valid Palindrome | Opposite-Direction |
| Reverse String | Opposite-Direction (swap-based) |
| Move Zeroes | Slow/Fast Write-Read |
| Remove Duplicates from Sorted Array | Slow/Fast Write-Read |
| Remove Element | Slow/Fast Write-Read |
| Merge Sorted Array (in place) | Merge Pointers |
| Two Sum II - Input Array Is Sorted | Opposite-Direction |
| Middle of the Linked List | Fast & Slow |
| Linked List Cycle | Fast & Slow |
| Is Subsequence | Two Arrays Non-Merge |
| Intersection of Two Arrays II | Merge Pointers (on sorted) |
| Squares of a Sorted Array | Opposite-Direction |

## Medium

| Problem | Variation |
|---|---|
| 3Sum | Opposite-Direction (nested) |
| 3Sum Closest | Opposite-Direction (nested) |
| Container With Most Water | Opposite-Direction |
| Sort Colors | Three-Pointer Partition |
| Remove Nth Node From End of List | Fast & Slow (offset start) |
| Linked List Cycle II (find cycle start) | Fast & Slow |
| Longest Substring Without Repeating Characters | Sliding Window (variable) |
| Minimum Size Subarray Sum | Sliding Window (variable) |
| Longest Repeating Character Replacement | Sliding Window (variable) |
| Permutation in String | Sliding Window (fixed) |
| Find All Anagrams in a String | Sliding Window (fixed) |
| Sort Array By Parity | Slow/Fast Write-Read |
| Boats to Save People | Opposite-Direction |
| Reorder List | Fast & Slow + Opposite-Direction combined |
| Partition Labels | Sliding Window (variable) |
| 4Sum | Opposite-Direction (double-nested) |
| Palindromic Substrings (expand-around-center is a two-pointer variant) | Opposite-Direction (expanding outward) |

## Hard

| Problem | Variation |
|---|---|
| Trapping Rain Water | Opposite-Direction |
| Minimum Window Substring | Sliding Window (variable) |
| Sliding Window Maximum (paired with monotonic deque) | Sliding Window (fixed, + deque) |
| Substring with Concatenation of All Words | Sliding Window (fixed, advanced) |
| Palindrome Pairs | Opposite-Direction + Trie (advanced combination) |

## Practice Strategy
1. **Round 1 (Recognition):** For each problem, before coding, write down which variation you think applies and why, using the `Recognition.md` checklist. Check yourself against the tables above.
2. **Round 2 (Brute Force):** Implement the naive O(n²) or worse solution first - this builds the intuition for *why* the optimized version works.
3. **Round 3 (Optimal):** Implement the two-pointer solution, timing yourself. Target: Easy ≤ 10 min, Medium ≤ 20 min, Hard ≤ 35 min.
4. **Round 4 (Complexity Defense):** Out loud (or written), state the time/space complexity and defend it - cross-check against `Complexity_Mistakes.md` for common traps.
5. **Round 5 (Cold Retry):** A week later, redo 3-4 random problems from the list from scratch without looking at notes, to confirm retention.