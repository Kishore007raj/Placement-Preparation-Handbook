# Sliding Window - Complexity Mistakes

Common ways candidates **miscalculate** or **misstate** complexity for Sliding Window solutions - and how to correct the reasoning on the spot.

---

## Mistake 1: Thinking the Nested `while` Inside `for` Is O(n²)
**The mistake:** Seeing:
```cpp
for (int right = 0; right < n; right++) {
    while (invalid) { left++; /* shrink */ }
}
```
and assuming O(n²) because of the nested loop shape.

**Why it's wrong:** `left` only ever moves forward and, across the **entire** execution, advances at most `n` times total - not `n` times per outer iteration. The correct analysis is **amortized/aggregate**: total work of the inner loop summed across all outer iterations is O(n).

**Correct statement:** "Although there's a nested loop, both pointers move strictly forward across the whole array, so total work is O(n) - this is an amortized analysis argument, not per-iteration."

---

## Mistake 2: Applying Sliding Window to Sum Conditions With Negative Numbers
**The mistake:** Using the standard "expand right, shrink left while sum > target" logic on an array that contains **negative numbers**, and still claiming O(n).

**Why it's wrong:** With negative numbers, adding an element to the window doesn't monotonically increase the sum - shrinking `left` might not actually reduce the sum, breaking the core assumption that makes the window's movement "safe" (never needing to re-check earlier positions). The algorithm can silently produce **wrong answers**, not just wrong complexity.

**Correct statement:** "This approach assumes non-negative values so the running sum is monotonic as the window grows. With negative numbers present, I'd need Prefix Sum combined with a HashMap or monotonic deque instead."

---

## Mistake 3: Confusing "Longest" and "Shortest" Window Recording Position
**The mistake:** Writing a "shortest valid window" solution but recording the answer **after** the shrink loop (like the "longest" pattern), missing the true minimum.

**Why it's wrong:** In the "shortest" variant, the window is smallest right at the boundary of still being valid - recording after the shrink loop exits (i.e., once it's invalid again) captures a window that's one step too small/already broken, or misses the true minimum captured mid-shrink. This isn't strictly a complexity bug, but it's frequently *justified* incorrectly as a complexity/style choice when it's actually a correctness bug with complexity implications (extra unnecessary passes to "fix" it).

**Correct statement:** always double-check: for "shortest," record inside the `while(valid)` shrink loop; for "longest," record after ensuring validity (typically right after the shrink `while` loop for invalidity exits).

---

## Mistake 4: Treating Frequency Array Comparison as Non-Constant
**The mistake:** For anagram/permutation matching using `window == need` (both `vector<int>(26)`), claiming this comparison makes the whole algorithm O(n · 26) = "not really O(n)."

**Why it's wrong:** Since 26 is a **fixed constant**, not a function of input size `n`, O(n · 26) simplifies to O(n) in standard asymptotic terms. It's fine to mention the constant factor for precision, but it shouldn't be presented as a different complexity class.

**Correct statement:** "Each window comparison is O(26), a constant, so the overall complexity is still O(n), just with a small constant factor - not O(n·k) the way sorting each window would be."

---

## Mistake 5: Forgetting the Two-Pass Cost in the At-Most-K Trick
**The mistake:** Claiming `subarraysWithKDistinct` is O(n) "because each pass is O(n)" without acknowledging it runs the helper **twice**.

**Why it's wrong:** While technically still O(n) overall (2n simplifies to O(n)), failing to mention that two passes are being run can look like you don't fully understand what the trick is doing - interviewers may probe further if this isn't stated clearly.

**Correct statement:** "This runs the `atMost(K)` helper twice - once for K, once for K-1 - so it's 2×O(n) = O(n) overall, with a HashMap costing O(k) space where k is the number of distinct values in the window."

---

## Mistake 6: Assuming the Monotonic Deque Adds Extra Complexity
**The mistake:** Assuming that maintaining a deque with push/pop operations inside the main loop makes Sliding Window Maximum O(n·k) or O(n log n) (confusing it with a heap-based approach).

**Why it's wrong:** A **deque** (not a heap) used with the monotonic invariant guarantees each index is pushed once and popped at most once across the *entire* run - so total deque operations are O(n), not O(n·k). This is different from a heap-based sliding window maximum, which *would* cost O(n log k) due to log-time heap operations (and needs lazy deletion since heaps don't support arbitrary removal in O(log k) directly).

**Correct statement:** "Using a monotonic deque, each index is pushed and popped at most once, giving O(n) total time. A heap-based version would be O(n log k) instead, since heap push/pop are O(log k)."

---

## Mistake 7: Not Accounting for `substr()` / String-Building Costs in Window Solutions
**The mistake:** In "minimum window substring" style problems, calling `s.substr(left, len)` on every valid window found (inside the loop) and still claiming O(n) overall.

**Why it's wrong:** `substr()` copies characters - calling it on every valid window inside the loop adds up to O(n²) in the worst case (many valid windows, each requiring an O(window size) copy). The fix: only track `bestStart` and `bestLen` as indices during the loop, and call `substr()` **once** at the very end to build the final answer.

**Correct statement:** "I'm only tracking the best start index and length as integers during the sliding window sweep, and calling `substr()` once at the end - so the window sweep itself stays O(n), and the final substring extraction is a one-time O(bestLen) cost."

---

## Quick Self-Check Before Stating Complexity Out Loud
- [ ] Did I confirm this is the amortized argument, not a naive nested-loop O(n²) read?
- [ ] Does my window logic assume non-negative values where required - and did I check the problem allows that?
- [ ] Am I recording the answer at the correct point for "longest" vs "shortest" variants?
- [ ] Did I mention any fixed-size constant factors (like a 26-array comparison) accurately without inflating the complexity class?
- [ ] For At-Most-K, did I acknowledge the two-pass nature (still O(n) overall)?
- [ ] Am I comparing my deque-based solution correctly against a heap-based alternative if asked?
- [ ] Did I avoid calling `substr()` or building strings repeatedly inside the main sliding window loop?