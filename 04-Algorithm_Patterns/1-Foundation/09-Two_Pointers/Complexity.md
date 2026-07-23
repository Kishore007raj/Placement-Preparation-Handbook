# Two Pointers — Complexity

## Per-Variation Complexity

| Variation | Time | Space | Compared to Brute Force |
|---|---|---|---|
| Opposite-Direction (pair sum, sorted) | O(n) | O(1) | O(n²) nested loop |
| Opposite-Direction (3Sum) | O(n²) (sort O(n log n) + O(n) per outer element) | O(1) extra (excl. output/sort) | O(n³) triple nested loop |
| Container With Most Water | O(n) | O(1) | O(n²) all-pairs check |
| Trapping Rain Water (two-pointer) | O(n) | O(1) | O(n) with two extra arrays (prefix max), or O(n²) brute force |
| Valid Palindrome | O(n) | O(1) | same, but avoids building a reversed copy (O(n) space) |
| Sliding Window (fixed size k) | O(n) | O(1) | O(n·k) recomputing sum every window |
| Sliding Window (variable size) | O(n) amortized | O(1) or O(k) with a map/array | O(n²) checking every substring |
| Fast & Slow (cycle detection) | O(n) | O(1) | O(n) time + O(n) space with a HashSet |
| Fast & Slow (middle of list) | O(n) | O(1) | O(n) two-pass (count then traverse) — fast/slow does it in one pass |
| Slow/Fast Write-Read (remove duplicates, move zeroes) | O(n) | O(1) | O(n) space if building a new array |
| Merge Pointers (merge sorted arrays) | O(m + n) | O(1) if merging in place with trailing space, else O(m+n) | O((m+n) log(m+n)) if combined then sorted |
| Three-Pointer Partition (Sort Colors) | O(n) | O(1) | O(n log n) general sort, or O(n) two-pass counting sort |

## Why Two Pointers Achieves O(n) — The Core Argument
The key insight across every variation: **each pointer moves strictly forward (or inward) and never backtracks**. This means the total number of pointer movements across the entire algorithm is bounded by O(n) (or O(n+m) for two structures), even though it might look like there's a nested loop (e.g., sliding window's inner `while` loop for shrinking).

**Amortized analysis for sliding window:** although there's a `while` loop inside a `for` loop, the `left` pointer only ever moves forward, and it can move forward at most `n` times total across the *entire* run of the algorithm — not per iteration of the outer loop. So total work is O(n) + O(n) = O(n), not O(n²).

## Space Complexity Notes
- Almost all Two Pointers variations achieve **O(1) extra space** — this is usually the entire point of using the pattern instead of a HashMap/HashSet-based alternative.
- Exceptions: sliding window problems needing a frequency map over a large/unbounded alphabet will use O(k) space (k = distinct elements in the window) — still typically much better than the O(n²) time alternative.
- Merge Pointers into a **new** array costs O(m+n) space; merging **in place** (when one structure has trailing capacity) achieves O(1) extra space.

## Comparing Two Pointers to Alternative Techniques

| Situation | Two Pointers | Alternative | Trade-off |
|---|---|---|---|
| Pair sum, sorted array | O(n) time, O(1) space | HashMap: O(n) time, O(n) space | Two Pointers wins on space when sorted |
| Pair sum, unsorted, need indices | Requires sorting first (loses indices) | HashMap: O(n) time, O(n) space | HashMap wins — sorting destroys index info |
| Cycle detection | O(n) time, O(1) space | HashSet: O(n) time, O(n) space | Two Pointers (Floyd's) wins on space |
| Longest substring condition | O(n) time, O(1)/O(k) space | Brute force: O(n²) or O(n³) time | Two Pointers wins decisively on time |