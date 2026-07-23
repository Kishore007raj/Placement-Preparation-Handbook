# 02 - Strings — Cheatsheet

Quick-glance table. Full detail in `Patterns.md`.

| # | Pattern | Trigger Keywords | Core Idea | Time | Space |
|---|---|---|---|---|---|
| 1 | Two Pointers | "palindrome", "reverse string" | converge from both ends, compare | O(n) | O(1) |
| 2 | Sliding Window | "longest/shortest substring with condition" | expand right, shrink left, freq array/map | O(n) | O(1)-O(k) |
| 3 | Hashing - Frequency | "anagram", "isomorphic", "first unique char" | fixed array count(26) or two-way map | O(n) | O(1)-O(n) |
| 4 | Expand Around Center | "longest palindromic substring" (n small-medium) | try every center, expand while matching | O(n²) | O(1) |
| 5 | Manacher's Algorithm | "longest palindromic substring", O(n) required, n large | transform string + radius array via center/right trick | O(n) | O(n) |
| 6 | KMP Algorithm | "find pattern occurrences", "implement strStr" | LPS array to avoid re-matching on mismatch | O(n+m) | O(m) |
| 7 | Rabin-Karp | "pattern matching", "repeated substring of length k" | rolling hash, verify on match | O(n+m) avg | O(1) |
| 8 | Z-Function | "prefix function", "pattern occurrences" (alt to KMP) | z[i] = match length with prefix at i | O(n+m) | O(n+m) |
| 9 | Trie | "autocomplete", "prefix search", "word dictionary" | tree of characters, O(L) insert/search | O(L) | O(total chars) |
| 10 | Backtracking on Strings | "all permutations/subsequences", "generate parentheses" | choose-recurse-undo | exponential | O(n) recursion depth |

## Decision Flowchart (fast triage)
```
Does the problem need PALINDROME logic?
 ├─ Check if a given string is a palindrome → Two Pointers
 ├─ Find longest palindromic substring, n small/medium → Expand Around Center
 └─ Find longest palindromic substring, n large (O(n) required) → Manacher's Algorithm

Does the problem need a SUBSTRING satisfying a condition (length, distinct chars, contains chars)?
 └─ YES → Sliding Window

Does the problem need to FIND ONE STRING INSIDE ANOTHER (pattern matching)?
 ├─ Deterministic worst-case guarantee needed → KMP
 ├─ Comfortable with average-case + verification → Rabin-Karp
 └─ Need "match length with prefix at every position" → Z-Function

Does the problem involve MANY STRINGS SHARING PREFIXES (dictionary, autocomplete)?
 └─ YES → Trie

Does the problem need FREQUENCY/GROUPING/MAPPING between chars?
 └─ YES → Hashing (Frequency Counting)

Does the problem ask to GENERATE ALL possible arrangements/subsequences/partitions?
 └─ YES → Backtracking on Strings
```

## STL Quick Reference (C++)
```cpp
s.substr(pos, len);
s.find(t);                          // string::npos if not found
reverse(s.begin(), s.end());
sort(s.begin(), s.end());
transform(s.begin(), s.end(), s.begin(), ::tolower);
isalnum(c); isalpha(c); isdigit(c);
stoi(s); to_string(n);
stringstream ss(s);                 // for splitting by delimiter
```

## Common Gotchas
- Off-by-one in sliding window `required` counter — verify with a small example ("aa", "aab") before trusting the logic.
- Repeated `+=` string concatenation in a loop can be hidden O(n²) — use `reserve()` or build via vector<char>.
- Fixed 26-size arrays assume lowercase-only input — check constraints before using them; switch to 128/256-size array or hashmap otherwise.
- `substr()` copies — avoid calling it in a tight loop if it can be avoided with index-based comparison instead.
- Palindrome checks: don't forget even-length centers (e.g., "abba") when using expand-around-center.
- KMP: LPS array indices are the most common source of bugs — trace through by hand on a small pattern like "aabaaab" before using it in a live interview.