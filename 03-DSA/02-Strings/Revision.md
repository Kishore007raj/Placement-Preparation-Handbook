# 02 - Strings — Revision (Night-Before-Interview Sheet)

Read this top-to-bottom in ~10 minutes before any OA/interview.

## One-Line Recall Per Pattern
1. **Two Pointers** — converge `left`/`right` inward; compare and stop on first mismatch.
2. **Sliding Window** — expand `right` always; shrink `left` based on a validity/counter condition; track best window.
3. **Hashing (Frequency)** — `int count[26]` for lowercase-only; increment for one string, decrement for other, all-zero = match.
4. **Expand Around Center** — try every index as both odd-length and even-length center; expand while chars match.
5. **Manacher's Algorithm** — transform with `#` separators; radius array `p[i]` using center/right-boundary trick; O(n).
6. **KMP** — build LPS array (longest proper prefix = suffix); on mismatch jump `j = lps[j-1]` instead of restarting.
7. **Rabin-Karp** — rolling hash, O(1) update per shift; always verify hash match with direct string comparison.
8. **Z-Function** — `z[i]` = match length with prefix starting at i; concatenate `pattern + '#' + text` for matching.
9. **Trie** — tree of characters; O(L) insert/search independent of dictionary size; use for prefix-heavy problems.
10. **Backtracking** — choose → recurse → undo; add constraints early to prune (e.g., open/close balance in parentheses).

## Formulas / Core Recurrences to Memorize
```
KMP LPS transition:      if pattern[i] == pattern[len]: lps[i] = ++len
                         else if len > 0: len = lps[len-1]
                         else: lps[i] = 0

Rolling hash update:     newHash = (base * (oldHash - s[left]*h) + s[right]) % mod

Z-function core:         if i < r: z[i] = min(r - i, z[i - l])
                         then extend while s[z[i]] == s[i + z[i]]

Manacher's core:         if i < right: p[i] = min(right - i, p[2*center - i])
                         then expand while t[i+p[i]+1] == t[i-p[i]-1]
```

## Red Flags That Tell You Which Pattern (memorize these triggers)
- "palindrome check" → **Two Pointers**
- "longest/shortest substring with condition" → **Sliding Window**
- "anagram", "isomorphic", "first unique char" → **Hashing (Frequency)**
- "longest palindromic substring", n small/medium → **Expand Around Center**
- "longest palindromic substring", n large / O(n) required → **Manacher's**
- "find pattern occurrences", "implement strStr" → **KMP** (or Rabin-Karp / Z-function)
- "repeated substring of length k" → **Rabin-Karp / Hashing**
- "autocomplete", "prefix search", "word dictionary" → **Trie**
- "all permutations/subsequences/partitions", "generate parentheses" → **Backtracking**

## My Common Mistakes Log (fill this in as you practice)
| Date | Problem | Pattern | Mistake Made | Fix |
|---|---|---|---|---|
| | | | | |
| | | | | |
| | | | | |

> Tip: Every time you get a problem wrong or slow, add a row above. Re-read this table before every interview — it's your personalized weak-spot list.

## Final 5-Minute Sanity Check Before Submitting Code
- [ ] Confirmed the character set (lowercase-only vs mixed vs unicode)?
- [ ] Handled empty string input?
- [ ] Handled single-character string input?
- [ ] Checked for off-by-one errors in substring bounds / window shrink logic?
- [ ] Avoided hidden O(n²) string concatenation in a loop for large inputs?
- [ ] Stated time & space complexity out loud?