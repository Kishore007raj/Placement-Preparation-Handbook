# Two Pointers - Variations

Every distinct flavor of the Two Pointers pattern, with the core mechanic explained.

---

## 1. Opposite-Direction (Converging Pointers)
**Mechanic:** `left = 0`, `right = n - 1`; move them toward each other based on a comparison.

**Used for:**
- Pair sum in sorted array
- 3Sum / 4Sum (outer loop fixes one element, inner two-pointer sweep on the rest)
- Container With Most Water
- Trapping Rain Water (with auxiliary max-so-far tracking)
- Valid Palindrome
- Reverse array/string in place

**Decision rule:** if current combination result is too small → move `left` right (increase); if too large → move `right` left (decrease).

---

## 2. Same-Direction, Same-Speed (Sliding Window)
**Mechanic:** `left = 0`, `right = 0`; `right` expands the window every step, `left` catches up only when the window becomes invalid (or to minimize once valid).

**Used for:**
- Longest substring without repeating characters
- Minimum window substring
- Longest subarray with sum ≤ k
- Fixed-size window problems (max sum of k consecutive elements)

**Decision rule:** grow `right` unconditionally each iteration; shrink `left` in a `while` loop until the window is valid again (or stop growing once at target size for fixed windows).

---

## 3. Same-Direction, Different-Speed (Fast & Slow / Floyd's)
**Mechanic:** `slow` moves 1 step, `fast` moves 2 steps per iteration, both starting from the same point.

**Used for:**
- Finding the middle of a linked list (`slow` lands on the middle when `fast` reaches the end)
- Detecting a cycle in a linked list (they meet if a cycle exists - Floyd's Cycle Detection)
- Finding the start of a cycle (reset one pointer to head after first meeting, advance both by 1 until they meet again)
- Finding if a number is "happy" (treat digit-square-sum sequence as an implicit linked list, detect cycle)

**Decision rule:** no comparison needed - the speed differential alone produces the useful structural property.

---

## 4. Slow/Fast Write-Read Pointers (In-Place Array Modification)
**Mechanic:** `slow` marks the next "valid" write position; `fast` scans ahead reading candidates. When `fast` finds a valid element, write it at `slow` and advance `slow`.

**Used for:**
- Remove Duplicates from Sorted Array
- Move Zeroes
- Remove Element (remove all instances of a value in place)
- Partitioning an array by a predicate (evens before odds, etc.)

**Decision rule:** `fast` always advances every iteration; `slow` advances only when a "keep" condition is met.

---

## 5. Merge Pointers (Two Separate Structures)
**Mechanic:** `i` indexes structure A, `j` indexes structure B, both starting at 0; advance whichever points to the smaller (or otherwise "behind") element.

**Used for:**
- Merge Two Sorted Arrays / Lists
- Intersection of Two Sorted Arrays
- Merge Sort's merge step

**Decision rule:** compare `A[i]` and `B[j]`; take the smaller, advance that pointer; when one structure is exhausted, append the rest of the other.

---

## 6. Three-Pointer Partition (Dutch National Flag)
**Mechanic:** `low`, `mid`, `high` - `mid` scans, `low` marks the boundary for "small" elements, `high` marks the boundary for "large" elements.

**Used for:**
- Sort Colors (0s, 1s, 2s in one pass)
- 3-way quicksort partitioning
- Partitioning around a pivot value (elements less than / equal to / greater than pivot)

**Decision rule:** if `nums[mid]` belongs to the "low" group, swap with `low` and advance both; if it belongs to "high" group, swap with `high` and only decrement `high` (recheck the swapped-in value); if it's already in the middle group, just advance `mid`.

---

## 7. Two Pointers on Two Different Arrays (Non-Merge)
**Mechanic:** similar to merge pointers, but used for comparison/matching rather than merging - e.g., checking if one string is a subsequence of another.

**Used for:**
- Is Subsequence (check if `s` is a subsequence of `t`)
- Backspace String Compare (processing from the end, skipping backspaces)

**Decision rule:** advance the pointer on the "target"/longer structure every step; advance the pointer on the "pattern"/shorter structure only on a match.

---

## Summary Table

| Variation | Start Positions | Movement | Signature Use Case |
|---|---|---|---|
| Opposite-Direction | ends | toward each other | Pair sum, palindrome |
| Sliding Window | same end | same direction, different catch-up timing | Substring/subarray with condition |
| Fast & Slow | same start | same direction, different speed | Linked list cycle/middle |
| Slow/Fast Write-Read | same start | same direction, conditional advance | In-place dedup/partition |
| Merge Pointers | start of each structure | same direction, comparison-driven | Merge sorted structures |
| Three-Pointer Partition | ends + scan | mixed | Sort Colors, quicksort partition |
| Two Arrays Non-Merge | start (or end) of each | same direction, conditional advance | Subsequence check |