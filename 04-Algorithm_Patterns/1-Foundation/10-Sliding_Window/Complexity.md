# Sliding Window — Complexity

## Per-Variation Complexity

| Variation | Time | Space | Compared to Brute Force |
|---|---|---|---|
| Fixed-Size Window | O(n) | O(1) or O(k) (if tracking a map) | O(n·k) recomputing sum/state every window |
| Variable-Size (Longest) | O(n) amortized | O(1) or O(k)/O(alphabet size) | O(n²) or O(n³) checking every substring/subarray |
| Variable-Size (Shortest) | O(n) amortized | O(1) or O(k) | O(n²) checking every subarray |
| Monotonic Deque Window | O(n) amortized | O(k) for the deque | O(n·k) scanning every window for max/min |
| At-Most-K Trick | O(n) (two O(n) passes) | O(k) for frequency map | O(n²) counting subarrays directly by brute force |
| Fixed + Frequency Array (Anagram) | O(n · Σ) where Σ = alphabet size (effectively O(n)) | O(Σ) — O(1) for fixed 26-letter alphabet | O(n · k log k) sorting each window |

## Why Sliding Window Achieves O(n) — The Core Argument
Both `left` and `right` pointers only move **forward**, never backward. Across the entire run of the algorithm:
- `right` advances at most `n` times (once per element).
- `left` advances at most `n` times total, **across all iterations combined**, not per iteration of the outer loop.

This is the same **amortized/aggregate analysis** argument used for Two Pointers generally: even though a `while` loop for shrinking sits inside a `for` loop for expanding, the *total* combined work across the whole run is O(n), not O(n²). This is the single most important complexity argument to be able to state clearly in an interview.

## Monotonic Deque Amortized Argument
For Sliding Window Maximum/Minimum: each index is pushed onto the deque exactly once and popped at most once (either from the front when it exits the window range, or from the back when a larger/smaller element dominates it). Total pushes + pops ≤ 2n, so the total work across the whole algorithm is O(n), even though it looks like there could be repeated popping per step.

## Space Complexity Notes
- **Fixed alphabet problems** (lowercase letters only) → use `vector<int>(26)` for O(1) space, not `unordered_map` (which has real per-entry overhead and is unnecessary when the domain is small and known).
- **General/unbounded values** (integers, unicode) → `unordered_map` gives O(k) space where k = number of distinct elements/characters currently in the window.
- **Monotonic deque** → O(k) space where k is the window size (worst case, deque holds every index in the window).
- **At-Most-K trick** → runs the `atMost` helper twice, but this doesn't change the overall O(n) time complexity (constant factor of 2), and space remains O(k) for the frequency map used inside the helper.

## Comparing Sliding Window to Alternative Techniques

| Situation | Sliding Window | Alternative | Trade-off |
|---|---|---|---|
| Longest subarray sum ≤ target, non-negative values | O(n) time, O(1) space | Prefix Sum + binary search: O(n log n) | Sliding Window wins when values are non-negative |
| Longest subarray sum ≤ target, **negative values allowed** | Doesn't directly apply (breaks monotonicity) | Prefix Sum + sorted structure / monotonic deque on prefix sums: O(n log n) | Must switch approaches — sliding window alone is incorrect here |
| Max/min per window | O(n) with monotonic deque | Naive scan per window: O(n·k) | Deque wins decisively for large k |
| Anagram/permutation matching | O(n) with frequency array | Sort each window: O(n·k log k) | Frequency array avoids repeated sorting |