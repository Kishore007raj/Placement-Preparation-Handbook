# 02 - Strings

Complete prep folder for the **Strings** topic — built for freshers preparing for company OAs and interview DSA rounds. Language: **C++**.

## Folder Contents

| File | Purpose | Read When |
|---|---|---|
| `Theory.md` | Fundamentals of `std::string`, complexity of built-in operations, why strings get their own topic | First — build the foundation |
| `Patterns.md` | The 10 core patterns, each with Name / When to Use / Tips / Recognition / Template / Complexity / Constraints | Main study material |
| `Templates.cpp` | All C++ code templates in one copy-paste-ready file | While practicing / during OA |
| `Cheatsheet.md` | One-page quick reference + decision flowchart | Quick lookup, right before a round |
| `Complexity.md` | Time & space complexity table for every pattern + general rules of thumb | When comparing approaches |
| `Interview_Notes.md` | High-yield problem list, company OA tips, common fresher mistakes | Before interviews specifically |
| `Revision.md` | Night-before-interview recall sheet + personal mistake log | Last-minute revision |

## The 10 Patterns Covered
1. Two Pointers (Palindrome / Reversal)
2. Sliding Window (Substring Problems)
3. Hashing — Frequency Counting for Strings
4. Expand Around Center (Palindromic Substrings)
5. Manacher's Algorithm (O(n) Longest Palindromic Substring)
6. KMP Algorithm (Pattern Matching)
7. Rabin-Karp (Rolling Hash Pattern Matching)
8. Z-Function (String Matching)
9. Trie (Prefix Tree)
10. Backtracking on Strings (Permutations / Subsequences / Combinations)

## Suggested Study Order
1. Read `Theory.md` once — understand how `std::string` behaves and where hidden complexity traps live.
2. Go through `Patterns.md` pattern by pattern. For each: read Recognition → understand Template → note Constraints.
3. Type out each template from `Templates.cpp` from scratch (don't copy-paste) until it's memorized — pay special attention to KMP's LPS array, it's the trickiest one.
4. Solve the "High-Yield List" problems in `Interview_Notes.md`, two passes each (brute force, then optimal).
5. Use `Cheatsheet.md` as your revision doc during timed practice.
6. Night before an interview/OA: read only `Revision.md`.

## How to Use This Folder Effectively
- Most string problems are array problems in disguise — always check `01-Arrays` patterns (two pointers, sliding window, hashing) first before reaching for a string-specific algorithm.
- Don't just read — **type every template by hand** at least 3 times each, especially KMP and Trie.
- After solving any string problem (LeetCode/GFG/company OA), come back and add one row to the mistake log in `Revision.md`.
- If stuck deciding a pattern live, mentally run through the "Red Flags" trigger list in `Revision.md` — designed to be recalled in under 30 seconds.

---
*Part of a larger DSA prep series — this folder (`02-Strings`) builds directly on `01-Arrays`; two pointers, sliding window, and hashing concepts carry over almost unchanged, with string-specific additions (KMP, Trie, palindrome algorithms) layered on top.*