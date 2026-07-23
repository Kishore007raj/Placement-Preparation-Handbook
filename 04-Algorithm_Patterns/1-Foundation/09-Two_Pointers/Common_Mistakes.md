# Two Pointers — Complexity Mistakes

Common ways candidates **miscalculate** or **misstate** complexity for Two Pointers solutions — and how to correct the reasoning on the spot.

---

## Mistake 1: Thinking Sliding Window's Nested Loop Is O(n²)
**The mistake:** Seeing a `while` loop nested inside a `for` loop and assuming O(n²) time.
```cpp
for (int right = 0; right < n; right++) {
    while (condition) { left++; }   // looks like nested loop = O(n²)?
}
```
**Why it's wrong:** `left` only ever moves **forward**, and across the *entire* execution of the algorithm, it can move forward at most `n` times total — not `n` times per outer iteration. This is **amortized analysis**: the total work done by the inner loop across all outer iterations combined is O(n), not O(n) per outer step.

**Correct statement:** "Even though there's a nested loop, both `left` and `right` traverse the array at most once each, so total time is O(n), not O(n²). This is an amortized/aggregate analysis argument, not a per-iteration one."

---

## Mistake 2: Forgetting the Sort Cost in 3Sum/4Sum
**The mistake:** Stating 3Sum is O(n) because "it's two pointers."

**Why it's wrong:** 3Sum requires sorting first (O(n log n)), then for each of the n elements, an O(n) two-pointer sweep — giving O(n²) total, which **dominates** the O(n log n) sort. The final complexity is O(n²), not O(n) or O(n log n).

**Correct statement:** "3Sum is O(n²): O(n log n) to sort, then O(n) two-pointer sweep for each of the n outer elements, and O(n²) dominates O(n log n)."

---

## Mistake 3: Ignoring the Cost of Sorting When It's Required First
**The mistake:** Claiming O(n) for a two-pointer solution on an array that **wasn't already sorted**, forgetting that sorting it first costs O(n log n).

**Why it's wrong:** If the problem doesn't guarantee sorted input and your solution starts with `sort(nums.begin(), nums.end())`, your true complexity is O(n log n), not O(n) — the two-pointer sweep afterward is the cheaper part.

**Correct statement:** always ask "was this already sorted, or did I sort it?" before claiming O(n).

---

## Mistake 4: Treating `substr()` / Array Copy Calls as O(1)
**The mistake:** In a two-pointer window solution, calling `s.substr(left, right - left + 1)` inside the loop and assuming the whole algorithm is still O(n).

**Why it's wrong:** `substr()` copies characters — it's O(window size), not O(1). If called on every iteration, the total cost can balloon to O(n²) even though the *pointer movement* itself is O(n).

**Correct statement:** "The two-pointer movement is O(n), but if I extract the substring on every valid window instead of just tracking indices, that adds up to O(n²) in the worst case. I should only materialize the substring once, at the end, using the best `start`/`length` found."

---

## Mistake 5: Assuming Fast & Slow Pointers Save Space When They Don't Need To
**The mistake:** Using a HashSet to detect a linked list cycle, then claiming O(1) space "because it's a two-pointer-style problem."

**Why it's wrong:** A HashSet-based cycle detection is O(n) space — that's the whole point of comparing it against Floyd's Fast & Slow approach, which achieves true O(1) space. Mixing these up in an interview signals you don't understand *why* Two Pointers is preferred here.

**Correct statement:** "The HashSet approach is O(n) time and O(n) space. Floyd's Fast & Slow pointers achieve the same O(n) time but O(1) space — that's the specific advantage of this pattern here."

---

## Mistake 6: Miscounting Total Work in Merge Pointers
**The mistake:** Saying merging two sorted arrays of size m and n is O(n) or O(m), forgetting the total is O(m + n).

**Why it's wrong:** Both pointers advance independently through their own structure; the total number of steps is bounded by the combined size, not just one of the two sizes.

**Correct statement:** "Merging is O(m + n) time — each element from both arrays is visited exactly once."

---

## Mistake 7: Overlooking Worst-Case Behavior in "Almost Sorted" Assumptions
**The mistake:** Assuming a two-pointer solution designed for sorted input still gives O(n) if you skip the sort step because "it's mostly sorted already."

**Why it's wrong:** Two pointers rely on a strict monotonic guarantee. If the input isn't fully sorted, the pointer movement logic can silently skip valid answers — this is a **correctness** bug disguised as a complexity question. Always sort fully (O(n log n)) unless the input is guaranteed sorted by the problem statement.

---

## Quick Self-Check Before Stating Complexity Out Loud
- [ ] Did I include the cost of sorting, if I performed it?
- [ ] Am I confusing "looks like nested loops" with actual amortized O(n) behavior?
- [ ] Did I account for any O(k) operations (substr, array copy) happening inside the pointer loop?
- [ ] Am I comparing against the right alternative (e.g., HashSet/HashMap) to correctly justify why Two Pointers' space complexity is better?
- [ ] For merge-style problems, did I state the combined size (m + n), not just one operand?