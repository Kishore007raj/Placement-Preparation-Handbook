# 02 - Strings — Interview Notes (Fresher OA + Interview Focus)

## How Interviewers Test This Topic
Strings are the second most common "easy filter" topic after arrays, and they specifically test:
1. Comfort manipulating character-level data (indices, ASCII values, in-place modification).
2. Recognizing when a problem is "really" an array problem in disguise (two pointers, sliding window, hashing all transfer directly).
3. Knowledge of a few string-specific algorithms (KMP, Trie) that show depth beyond basic array thinking.

## Step-by-Step Approach in a Live Interview
1. **Clarify the character set** — lowercase only? mixed case? digits/symbols? unicode? This determines whether you use a 26-array, 128/256-array, or hashmap.
2. **Ask about mutability** — can you modify the input string, or must you return a new one?
3. **State the brute force** — e.g., "check every substring" (O(n²) or O(n³)) — before optimizing.
4. **Identify if it's really an array pattern wearing a string costume** — most substring/palindrome-check problems map directly to two pointers / sliding window / hashing from the Arrays topic.
5. **Consider if a string-specific algorithm applies** — pattern matching (KMP/Rabin-Karp), palindromes (expand-around-center/Manacher's), or prefix-heavy problems (Trie).
6. **Code carefully with indices** — string problems are index-heavy; off-by-one bugs are the #1 cause of failed test cases.
7. **State time & space complexity explicitly** at the end.

## Most Frequently Asked Problems (High-Yield List)
- Valid Palindrome / Valid Palindrome II
- Reverse String / Reverse Words in a String
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- Longest Palindromic Substring
- Valid Anagram / Group Anagrams
- First Unique Character in a String
- Isomorphic Strings
- Implement strStr() (KMP)
- Longest Common Prefix
- Implement Trie (Prefix Tree)
- Word Search / Word Search II (Trie + backtracking)
- Word Break / Word Break II
- Generate Parentheses
- Letter Combinations of a Phone Number
- Palindrome Partitioning
- String to Integer (atoi) — parsing edge cases
- Zigzag Conversion
- Count and Say
- Repeated DNA Sequences (Rabin-Karp style hashing)
- Permutation in String

## Company OA Specific Tips
- String parsing problems (like custom "atoi", validating formats, tokenizing) are extremely common in fresher OAs (e.g., TCS, Infosys, Cognizant style rounds) — they test edge-case handling more than algorithmic depth. Practice these carefully: leading/trailing whitespace, signs, overflow, invalid characters.
- Anagram/frequency-based MCQs and coding questions appear often — the fixed-size array trick (`int count[26]`) is worth having memorized cold.
- For product-based company OAs (Amazon, Microsoft, etc.), expect at least one sliding window or KMP-flavored problem — these test whether you can beat the O(n²)/O(n·m) brute force.
- Watch for **hidden large test cases** — a brute-force palindrome or substring search that passes visible samples can TLE on hidden cases with n ~ 10^5.

## Common Mistakes Freshers Make
- Assuming lowercase-only input without checking constraints, causing array-index-out-of-bounds crashes on uppercase/digit input.
- Off-by-one errors in substring bounds (`s.substr(start, length)` vs `s.substr(start, end)` confusion — remember the second argument is a **length**, not an end index).
- Forgetting to handle empty string input (`""`) as an edge case.
- In sliding window problems, forgetting to shrink the window correctly, causing an incorrect `required` counter or missing the final valid window before the loop ends.
- Naive string concatenation in a loop causing hidden O(n²) blowup and TLE on large inputs.
- Confusing KMP's LPS array logic — mixing up `len` (current matched length) with the loop index `i`.

## What to Say When You're Stuck
- "Since this is really about substrings, let me check if a sliding window with a frequency array works here."
- "Let me clarify — can I assume ASCII lowercase letters only, or should I handle a broader character set?"
- "I'll start with the brute-force O(n²) substring check, then think about whether KMP or hashing gets this to O(n)."
Saying these out loud demonstrates structured pattern recognition — highly valued for freshers who may not yet have memorized every algorithm.

## Practice Strategy
1. Solve every problem in the "High-Yield List" twice: brute force, then optimal.
2. Hand-write the KMP LPS array construction from scratch at least 5 times until it's automatic — it's the hardest template here to get exactly right under pressure.
3. Re-derive the sliding window template for both "longest" and "shortest" variants — they have subtly different shrink conditions.
4. After each problem, note in `Revision.md` what specific trigger word told you the pattern.