# 01 - Arrays & Hashing — Revision (Night-Before-Interview Sheet)

Read this top-to-bottom in ~10 minutes before any OA/interview.

## One-Line Recall Per Pattern
1. **Prefix Sum** — cumulative sum array; subarray sum = k → pair with HashMap<sum, count>, init `{0:1}`.
2. **Two Pointers** — sorted array, converge from both ends; move the pointer that fixes the sum comparison.
3. **Sliding Window (Fixed)** — window size k; subtract outgoing, add incoming, don't recompute.
4. **Sliding Window (Variable)** — expand right always; shrink left only while condition is violated.
5. **Cyclic Sort** — values in [1..n]; place `nums[i]` at index `nums[i]-1` via swapping.
6. **Hashing (Frequency)** — count with map or fixed array; anagrams → sorted string or 26-count signature as key.
7. **HashMap Pair Search** — check complement `target - nums[i]` before inserting `nums[i]`.
8. **Kadane's** — `curSum = max(nums[i], curSum + nums[i])`; init both to `nums[0]`, not 0.
9. **Dutch National Flag** — 3 pointers `low, mid, high`; don't increment `mid` after swapping with `high`.
10. **Monotonic Stack** — store indices; pop while stack top violates the "next greater/smaller" order.

## Formulas to Memorize
```
range sum [l, r]        = prefix[r+1] - prefix[l]
subarray count sum = k  = freq[sum - k] accumulated, with freq[0] = 1 initially
Kadane recurrence        = curSum = max(nums[i], curSum + nums[i])
first missing positive   = cyclic sort, then first index i where nums[i] != i+1
```

## Red Flags That Tell You Which Pattern (memorize these triggers)
- "sorted array" + "pair/triplet" → **Two Pointers**
- "subarray", "size k" → **Sliding Window (fixed)**
- "longest/shortest subarray/substring with condition" → **Sliding Window (variable)**
- "range sum query", "subarray sum equals k" → **Prefix Sum (+HashMap)**
- "numbers from 1 to n", "missing", "duplicate" → **Cyclic Sort**
- "anagram", "frequency", "top k" → **Hashing**
- "two sum", "indices", "unsorted" → **HashMap Pair Search**
- "maximum subarray/product" → **Kadane's**
- "sort colors", "0s 1s 2s" → **Dutch National Flag**
- "next greater/smaller", "daily temperatures" → **Monotonic Stack**

## My Common Mistakes Log (fill this in as you practice)
| Date | Problem | Pattern | Mistake Made | Fix |
|---|---|---|---|---|
| | | | | |
| | | | | |
| | | | | |

> Tip: Every time you get a problem wrong or slow, add a row above. Re-read this table before every interview — it's your personalized weak-spot list.

## Final 5-Minute Sanity Check Before Submitting Code
- [ ] Handled empty array / single element?
- [ ] Handled all-negative or all-same values?
- [ ] Used `long long` where sums could overflow `int`?
- [ ] Checked `.count()`/`.find()` before relying on map lookups (avoid silent auto-insert bugs)?
- [ ] Stated time & space complexity out loud?