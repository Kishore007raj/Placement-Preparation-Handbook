# Sliding Window — Practice Problems

Curated list, organized by difficulty and tagged with the variation used. Solve each twice: brute force first, then optimal sliding-window solution.

## Easy

| Problem | Variation |
|---|---|
| Maximum Average Subarray I | Fixed-Size Window |
| Contains Duplicate II (nearby duplicate within window k) | Fixed-Size Window |
| Maximum Number of Vowels in a Substring of Given Length | Fixed-Size Window |
| Best Time to Buy and Sell Stock (single pass, window of "so far min") | Variable-Size (Longest), simplified |

## Medium

| Problem | Variation |
|---|---|
| Longest Substring Without Repeating Characters | Variable-Size (Longest) |
| Longest Substring with At Most K Distinct Characters | Variable-Size (Longest) |
| Longest Repeating Character Replacement | Variable-Size (Longest) |
| Fruit Into Baskets | Variable-Size (Longest), at-most-2-distinct |
| Minimum Size Subarray Sum | Variable-Size (Shortest) |
| Find All Anagrams in a String | Fixed-Size + Frequency Array |
| Permutation in String | Fixed-Size + Frequency Array |
| Max Consecutive Ones III | Variable-Size (Longest) |
| Subarray Product Less Than K | Variable-Size (Longest) |
| Sliding Window Maximum | Monotonic Deque Window |
| Sliding Window Median (advanced, needs a balanced structure alongside window) | Monotonic Deque / Two-Heap hybrid |
| Binary Subarrays With Sum | At-Most-K Trick |
| Subarrays with K Different Integers | At-Most-K Trick |
| Count Number of Nice Subarrays (exactly k odd numbers) | At-Most-K Trick |
| Grumpy Bookstore Owner | Fixed-Size Window |
| Frequency of the Most Frequent Element | Variable-Size (Longest), with sorting first |

## Hard

| Problem | Variation |
|---|---|
| Minimum Window Substring | Variable-Size (Shortest) |
| Substring with Concatenation of All Words | Fixed-Size Window + Frequency Array (multi-word) |
| Sliding Window Maximum (strict O(n) requirement, large constraints) | Monotonic Deque Window |
| Shortest Subarray with Sum at Least K (negative numbers allowed) | Monotonic Deque on Prefix Sums (not plain sliding window) |
| Minimum Number of K Consecutive Bit Flips | Fixed-Size Window (with a difference-array trick) |

## Practice Strategy
1. **Round 1 (Recognition):** For each problem, before coding, write down which variation you think applies and why, using `Recognition.md`. Pay special attention to distinguishing "longest" vs "shortest" record-placement.
2. **Round 2 (Brute Force):** Implement the naive O(n²)/O(n·k) solution first.
3. **Round 3 (Optimal):** Implement the sliding window solution, timing yourself. Target: Easy ≤ 10 min, Medium ≤ 20 min, Hard ≤ 35 min.
4. **Round 4 (Complexity Defense):** State the time/space complexity out loud and defend the amortized argument — cross-check against `Complexity_Mistakes.md`.
5. **Round 5 (Cold Retry):** A week later, redo 3-4 random problems from scratch without notes to confirm retention.
