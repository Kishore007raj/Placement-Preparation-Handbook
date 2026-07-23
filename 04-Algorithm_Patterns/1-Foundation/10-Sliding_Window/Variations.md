# Sliding Window — Variations

Every distinct flavor of the Sliding Window pattern, with the core mechanic explained.

---

## 1. Fixed-Size Window
**Mechanic:** window size `k` is constant. Slide by adding `nums[right]` and removing `nums[right - k]` in the same step (once the window first reaches size k).

**Used for:**
- Maximum/minimum sum or average of k consecutive elements
- Maximum number of vowels in a substring of length k

**Decision rule:** maintain a running aggregate (sum, count, etc.); update it in O(1) per slide instead of recomputing over the whole window.

---

## 2. Variable-Size Window — Longest Valid Range
**Mechanic:** `left = 0`; for each `right`, expand the window by including `nums[right]`. If the window becomes invalid, shrink from `left` in a `while` loop until valid again. Record the max window size **after** ensuring validity.

**Used for:**
- Longest substring without repeating characters
- Longest subarray with sum ≤ k (non-negative values)
- Longest substring with at most K distinct characters
- Longest repeating character replacement (track max frequency character in window; window invalid when `windowSize - maxFreq > k` replacements allowed)
- Fruit Into Baskets (at most 2 distinct types = special case of at-most-K)

**Decision rule:** grow unconditionally; shrink only when invalid; the answer is measured at the point of maximum valid extent.

---

## 3. Variable-Size Window — Shortest Valid Range
**Mechanic:** `left = 0`; for each `right`, expand the window. Once valid, shrink from `left` **as much as possible while staying valid**, recording the minimum window size at each valid step before it becomes invalid again.

**Used for:**
- Minimum Window Substring
- Minimum Size Subarray Sum (sum ≥ target)
- Smallest subarray containing all unique elements of the array

**Decision rule:** grow unconditionally; shrink greedily while still valid, recording the answer at every valid state — not just once at the end.

---

## 4. Monotonic Deque Window (Sliding Window Maximum/Minimum)
**Mechanic:** maintain a deque of indices such that their corresponding values are in decreasing (for max) or increasing (for min) order. On each new element, pop from the back while it violates monotonicity, then push the new index; pop from the front if it has fallen out of the current window range.

**Used for:**
- Sliding Window Maximum
- Sliding Window Minimum
- Shortest Subarray with Sum at Least K (using a monotonic deque on prefix sums)

**Decision rule:** the front of the deque always holds the index of the current window's max/min — O(1) retrieval, O(n) total amortized work since each index is pushed and popped at most once.

---

## 5. At-Most-K Trick (Exactly-K Transformation)
**Mechanic:** directly computing "exactly K" with a shrink/grow window is awkward because the validity condition isn't simply monotonic in the usual single-direction sense. Instead, compute two "at most K" style variable windows and subtract:
```
exactly(K) = atMost(K) - atMost(K - 1)
```

**Used for:**
- Subarrays with Exactly K Different Integers
- Count subarrays with exactly K odd numbers
- Binary subarrays with sum exactly = goal (via atMost(goal) - atMost(goal-1))

**Decision rule:** write a clean `atMost(K)` helper function (a standard Variable-Size Longest window counting all valid subarrays ending at each `right`), then call it twice.

---

## 6. Fixed-Size Window + Frequency Array (Anagram/Permutation Matching)
**Mechanic:** window size equals the pattern's length; maintain a frequency array (size 26 typically) for the current window and compare it against the pattern's frequency array (either with direct array equality or a "matches" counter).

**Used for:**
- Find All Anagrams in a String
- Permutation in String
- Substring with Concatenation of All Words (extension with multiple words, more advanced)

**Decision rule:** slide the window one character at a time; update counts for the incoming and outgoing characters; compare frequency arrays each step (or maintain a running "matches" count to avoid O(26) comparison every time, for a faster O(1) amortized check).

---

## Summary Table

| Variation | Window Size | Shrink Trigger | Record Answer |
|---|---|---|---|
| Fixed-Size | constant k | N/A (slides, doesn't shrink independently) | after window first reaches size k, every step |
| Variable (Longest) | grows/shrinks | shrink only when invalid | after shrink loop (window valid & maximal) |
| Variable (Shortest) | grows/shrinks | shrink while still valid | inside shrink loop, before losing validity |
| Monotonic Deque | fixed or variable | pop back (monotonicity), pop front (out of range) | front of deque = current max/min |
| At-Most-K Trick | variable (two passes) | standard "at most K" shrink logic | difference of two atMost(K) calls |
| Fixed + Frequency Array | constant (pattern length) | N/A (slides) | compare frequency arrays / matches counter each step |