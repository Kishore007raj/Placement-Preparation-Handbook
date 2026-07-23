# Sliding Window - When to Use

## Core Signal
Use Sliding Window whenever the problem is about a **contiguous** range (subarray or substring) and you're tempted to check every possible range with nested loops (O(n²) or worse), AND at least one of these is true:
- You need the **longest or shortest** contiguous range satisfying some condition.
- You need a range of a **fixed size k**.
- The condition on the range can be **updated incrementally** (O(1) or amortized O(1)) as you add/remove one element, rather than recomputed from scratch.
- You need to track a **running aggregate** (sum, count, frequency, distinct count, max/min) over the current range.

## Specific Scenarios

### 1. Fixed-Size Window
The problem explicitly gives you a window size `k` and asks for something about every window of that size (max sum, average, whether it matches a pattern).
> Use when: "subarray of size k", "window of length k", "every k consecutive elements".

### 2. Variable-Size Window - Longest Valid Range
You want the **longest** contiguous range that still satisfies a condition. Grow the window greedily; only shrink when the condition breaks.
> Use when: "longest substring/subarray with...", "at most k distinct characters", "longest subarray with sum ≤ target".

### 3. Variable-Size Window - Shortest Valid Range
You want the **shortest** contiguous range that satisfies a condition. Grow until valid, then shrink as much as possible while it stays valid, recording the best each time.
> Use when: "minimum window substring", "smallest subarray with sum ≥ target", "minimum length subarray containing all elements of X".

### 4. Fixed/Variable Window + Extremum Tracking
You need the max or min value *within* the current window efficiently as it slides - a plain scan per window would be O(n·k).
> Use when: "sliding window maximum/minimum", "maximum of every window of size k".

### 5. Exact-Count Variants ("Exactly K" Problems)
Directly tracking "exactly K distinct/matching elements" with shrink/grow logic is awkward because the condition isn't strictly monotonic in the usual sense. The trick: compute `atMost(K) - atMost(K-1)`.
> Use when: "exactly K distinct elements", "subarrays with exactly K odd numbers".

### 6. Pattern/Anagram Matching Within a Larger String
Checking if any window of the text matches a permutation/anagram of a pattern - fixed window size equal to the pattern length, tracked via a frequency array.
> Use when: "find all anagrams", "permutation in string", "smallest substring containing all characters of another string".

## When NOT to Use Sliding Window
- **Non-contiguous subsequences** (elements don't need to be adjacent) - sliding window only works on contiguous ranges; use DP or backtracking instead.
- **The condition isn't monotonic as the window grows/shrinks** - e.g., if adding an element to the window could make a previously-invalid window valid *and* a previously-valid window invalid unpredictably, the shrink logic breaks. Common with problems involving negative numbers and simple running sums (a variable window on sums generally requires non-negative values; use Prefix Sum + HashMap instead if negatives are allowed).
- **You need information from non-adjacent parts of the array simultaneously** that a single window can't represent - consider prefix sums, two separate passes, or a different data structure.

## The One Question to Ask Yourself
> "If I have a valid (or invalid) window `[left, right]`, does moving `right` forward by one, or `left` forward by one, change the validity in a **predictable, monotonic** way - so I never need to re-check earlier positions?"

If yes → Sliding Window is very likely the right tool.
If validity can flip back and forth unpredictably as you slide, the pattern likely doesn't apply directly - check whether negative numbers, non-contiguous requirements, or non-monotonic conditions are the culprit.