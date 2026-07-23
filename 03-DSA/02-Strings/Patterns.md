# 02 - Strings - Patterns

Format for every pattern: **Name | When to Use | Tips for Effective Use | Recognition | Detailed Template | Time and Space Considerations | Constraints and Strategies**

---

## 1. Two Pointers (Palindrome / Reversal)

### When to Use
- Checking if a string is a palindrome (with or without skipping non-alphanumeric characters).
- Reversing a string/array in place.
- Comparing characters from both ends moving inward.

### Tips for Effective Use
- Use `left = 0, right = n-1`, move both inward, compare and stop early on mismatch.
- For "valid palindrome" variants, normalize first (lowercase, strip non-alphanumeric) or skip invalid chars on the fly to avoid extra passes.
- For "almost palindrome" (allow one deletion), try skipping either the left or right character on mismatch and recheck both branches.

### Recognition
- Keywords: "palindrome", "reverse string", "valid palindrome ignoring spaces/punctuation", "at most one character removed".

### Detailed Template
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}

// Valid Palindrome (ignore non-alphanumeric, case-insensitive)
bool isPalindromeAlnum(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

// Valid Palindrome II (allow deleting at most one character)
bool validSub(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}
bool validPalindromeII(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right])
            return validSub(s, left + 1, right) || validSub(s, left, right - 1);
        left++; right--;
    }
    return true;
}
```

### Time and Space Considerations
- O(n) time, O(1) space (excluding output string for reversal).

### Constraints and Strategies
- Always clarify: case sensitivity, whitespace/punctuation handling, unicode vs ASCII.
- For "reverse words in a string" style problems, combine two-pointer in-place reversal with a second pass to reverse word order - avoid unnecessary extra string allocations when in-place is required.

---

## 2. Sliding Window (Substring Problems)

### When to Use
- Longest/shortest substring satisfying a condition (no repeating chars, at most k distinct chars, contains all chars of another string).
- Minimum window substring, longest substring with at most K distinct characters, permutation-in-string style problems.

### Tips for Effective Use
- Maintain a frequency map/array for the current window; expand `right`, shrink `left` when the window becomes invalid (or once it becomes valid, to minimize).
- Track a counter of "how many characters/conditions are satisfied" instead of scanning the whole map every time - keeps each step O(1) amortized.
- For fixed-size windows (anagram/permutation check), compare window size directly instead of a "valid substring" condition.

### Recognition
- Keywords: "longest substring without repeating characters", "minimum window substring", "permutation in string", "at most K distinct characters", "anagram substring".

### Detailed Template
```cpp
// Longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    vector<int> lastSeen(256, -1);
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (lastSeen[s[right]] >= left) left = lastSeen[s[right]] + 1;
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// Minimum Window Substring
string minWindow(string s, string t) {
    vector<int> need(128, 0);
    for (char c : t) need[c]++;
    int required = t.size();
    int left = 0, bestLen = INT_MAX, bestStart = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (need[s[right]]-- > 0) required--;
        while (required == 0) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
            if (++need[s[left]] > 0) required++;
            left++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}

// Permutation in String (fixed-size window == s1's length)
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> need(26, 0), window(26, 0);
    for (char c : s1) need[c - 'a']++;
    int k = s1.size();
    for (int i = 0; i < (int)s2.size(); i++) {
        window[s2[i] - 'a']++;
        if (i >= k) window[s2[i - k] - 'a']--;
        if (i >= k - 1 && window == need) return true;
    }
    return false;
}
```

### Time and Space Considerations
- O(n) time for the window sweep (each pointer moves forward at most n times).
- O(1) extra space when alphabet is fixed size (26/128/256 array), O(k) for general HashMap.

### Constraints and Strategies
- Fixed alphabet (lowercase letters) → use `vector<int>(26)` instead of `unordered_map` for speed and simpler equality checks (`window == need`).
- Be precise about what "valid" means - off-by-one errors around the `required` counter are the most common bug here.
- For case-insensitive or unicode strings, adjust array size / use a hashmap instead of a fixed 26/128 array.

---

## 3. Hashing - Frequency Counting for Strings

### When to Use
- Anagram checks, isomorphic strings, first unique character, character frequency comparisons.
- Grouping strings by a signature (anagram groups, similar structure).

### Tips for Effective Use
- Use a fixed-size array (`int count[26]` for lowercase-only) instead of `unordered_map<char,int>` - faster and avoids hashing overhead.
- For anagram checks between two strings, increment count for one string and decrement for the other; all zero at the end = anagram.
- For isomorphic strings, maintain **two** maps (char→char in both directions) to ensure a true bijection.

### Recognition
- Keywords: "anagram", "isomorphic", "first unique/non-repeating character", "permutation of another string", "character frequency".

### Detailed Template
```cpp
// Valid Anagram
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;
    for (int c : count) if (c != 0) return false;
    return true;
}

// First Unique Character
int firstUniqChar(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    for (int i = 0; i < (int)s.size(); i++)
        if (freq[s[i] - 'a'] == 1) return i;
    return -1;
}

// Isomorphic Strings
bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> mapST, mapTS;
    for (int i = 0; i < (int)s.size(); i++) {
        char a = s[i], b = t[i];
        if (mapST.count(a) && mapST[a] != b) return false;
        if (mapTS.count(b) && mapTS[b] != a) return false;
        mapST[a] = b;
        mapTS[b] = a;
    }
    return true;
}
```

### Time and Space Considerations
- O(n) time, O(1) space (fixed alphabet array) or O(n) space (general hashmap for unicode/mixed-case).

### Constraints and Strategies
- Always confirm the character set (lowercase only? mixed case? unicode?) before choosing array size vs hashmap.
- Watch for early-exit optimization: return `false` as soon as a mismatch is detected instead of scanning the whole string.

---

## 4. Expand Around Center (Palindromic Substrings)

### When to Use
- Find the longest palindromic substring, or count all palindromic substrings, when input size is moderate (n ≤ ~5000).

### Tips for Effective Use
- Every palindrome has a center - either a single character (odd length) or between two characters (even length). Try both for every index.
- Expand outward from each center while characters match; track the longest found.
- This is simpler to code than Manacher's and sufficient for O(n²) time limits.

### Recognition
- Keywords: "longest palindromic substring", "count palindromic substrings", input size not requiring strict O(n).

### Detailed Template
```cpp
pair<int,int> expandFromCenter(const string& s, int left, int right) {
    while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
        left--; right++;
    }
    return {left + 1, right - 1}; // inclusive palindrome bounds
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, maxLen = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        auto [l1, r1] = expandFromCenter(s, i, i);       // odd length
        auto [l2, r2] = expandFromCenter(s, i, i + 1);   // even length
        if (r1 - l1 + 1 > maxLen) { start = l1; maxLen = r1 - l1 + 1; }
        if (r2 - l2 + 1 > maxLen) { start = l2; maxLen = r2 - l2 + 1; }
    }
    return s.substr(start, maxLen);
}

// Count all palindromic substrings
int countSubstrings(string s) {
    int n = s.size(), count = 0;
    for (int center = 0; center < 2 * n - 1; center++) {
        int left = center / 2, right = left + center % 2;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++; left--; right++;
        }
    }
    return count;
}
```

### Time and Space Considerations
- O(n²) time (n centers, each expansion up to O(n)), O(1) space.

### Constraints and Strategies
- If `n` is large (≥ 10^5) and O(n²) will TLE, switch to **Manacher's Algorithm** (pattern 5) for O(n).
- Remember to check **both** odd-length and even-length centers - missing even-length centers is a common bug (e.g., "abba").

---

## 5. Manacher's Algorithm (Longest Palindromic Substring, O(n))

### When to Use
- Longest palindromic substring when `n` is large enough that O(n²) expand-around-center would TLE (typically n ≥ 10^5).

### Tips for Effective Use
- Transform the string by inserting a separator (`#`) between every character (and at the ends) to handle odd/even palindromes uniformly.
- Maintain an array `p[i]` = radius of palindrome centered at `i` in the transformed string, using the "center/right boundary" trick to avoid redundant expansion.
- Rarely asked to fully implement from scratch as a fresher, but recognize it exists and know the O(n) claim - some interviews accept explaining the idea over full implementation.

### Recognition
- Keywords: "longest palindromic substring", explicit O(n) time requirement, very large input size in constraints.

### Detailed Template
```cpp
string longestPalindromeManacher(string s) {
    string t = "^";
    for (char c : s) { t += '#'; t += c; }
    t += "#$";
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 1; i < n - 1; i++) {
        if (i < right) p[i] = min(right - i, p[2 * center - i]);
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
        if (i + p[i] > right) { center = i; right = i + p[i]; }
    }
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) { maxLen = p[i]; centerIndex = i; }
    }
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}
```

### Time and Space Considerations
- O(n) time, O(n) space (transformed string + radius array).

### Constraints and Strategies
- Rarely required to hand-write in a fresher interview, but useful to mention as the optimal known approach if asked "can you do better than O(n²)?"
- The sentinel characters (`^`, `$`) at the boundaries avoid explicit bounds-checking during expansion - don't skip them.

---

## 6. KMP Algorithm (Knuth-Morris-Pratt Pattern Matching)

### When to Use
- Find all occurrences of a pattern `p` inside text `s` in O(n + m) time, avoiding the O(n·m) brute force.
- Problems around "implement strStr()", repeated substring patterns, prefix-suffix relationships.

### Tips for Effective Use
- Precompute the **LPS array** (Longest Proper Prefix which is also Suffix) for the pattern - this lets you skip re-comparing characters on mismatch.
- Core idea: on mismatch at position `j` in pattern, don't restart `j` from 0 - jump to `lps[j-1]`.
- The LPS array itself is useful standalone for problems like "shortest repeating substring" or "add shortest palindrome prefix".

### Recognition
- Keywords: "find all occurrences of pattern", "implement strStr", "repeated substring pattern", explicit need for O(n+m) matching.

### Detailed Template
```cpp
vector<int> computeLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> result;
    if (pattern.empty()) return result;
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    int n = text.size(), m = pattern.size();
    while (i < n) {
        if (text[i] == pattern[j]) { i++; j++; }
        if (j == m) {
            result.push_back(i - j);   // match found at index i-j
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j > 0) j = lps[j - 1];
            else i++;
        }
    }
    return result;
}
```

### Time and Space Considerations
- O(n + m) time (n = text length, m = pattern length), O(m) space for the LPS array.

### Constraints and Strategies
- Preferred over brute force `substr`/nested-loop matching whenever `n` and `m` are both large (avoids O(n·m) worst case, e.g., text = "aaaa...a", pattern = "aaa...ab").
- The LPS array logic is the hard part to get right - practice writing it from scratch; it's the most commonly mis-implemented part in interviews.

---

## 7. Rabin-Karp (Rolling Hash Pattern Matching)

### When to Use
- Pattern matching where you want an average O(n + m) solution using hashing instead of LPS arrays.
- Multiple pattern search against the same text (precompute rolling hashes once).
- Detecting duplicate substrings of fixed length (e.g., "Repeated DNA Sequences").

### Tips for Effective Use
- Compute a rolling hash so that moving the window by one character is O(1): `newHash = (oldHash - s[left]*pow) * base + s[right]`.
- Use a large prime modulus to reduce collision probability; on hash match, do a direct character comparison to rule out false positives (since hashing is probabilistic).
- Precompute `base^(m-1) mod prime` once, reuse for every window shift.

### Recognition
- Keywords: "repeated substring of length k", "find pattern occurrences", "duplicate substrings", willingness to accept average-case (not worst-case guaranteed) performance.

### Detailed Template
```cpp
vector<int> rabinKarp(const string& text, const string& pattern) {
    const int base = 256, mod = 1e9 + 7;
    int n = text.size(), m = pattern.size();
    vector<int> result;
    if (m > n) return result;

    long long patternHash = 0, windowHash = 0, h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * base) % mod;

    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        windowHash = (windowHash * base + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash) {
            if (text.substr(i, m) == pattern)   // verify to rule out collision
                result.push_back(i);
        }
        if (i < n - m) {
            windowHash = (base * (windowHash - text[i] * h) + text[i + m]) % mod;
            if (windowHash < 0) windowHash += mod;
        }
    }
    return result;
}

// Repeated DNA Sequences (fixed-length duplicate substrings) using hashing
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> freq;
    vector<string> result;
    for (int i = 0; i + 10 <= (int)s.size(); i++) {
        string sub = s.substr(i, 10);
        if (++freq[sub] == 2) result.push_back(sub);
    }
    return result;
}
```

### Time and Space Considerations
- Average O(n + m) time; worst case O(n·m) if many hash collisions occur (rare with a good modulus/base and verification step).
- O(1) extra space for the rolling hash (excluding output).

### Constraints and Strategies
- Always verify a hash match with a direct string comparison - hash collisions are possible even with a good modulus (birthday paradox).
- Choose a large prime modulus and a base larger than the alphabet size to minimize collisions.
- For very performance-critical code, consider double hashing (two different mod/base pairs) to virtually eliminate collision risk.

---

## 8. Z-Function (String Matching / Pattern Occurrence)

### When to Use
- Alternative to KMP for pattern matching, and useful for problems needing "for every suffix, how long does it match the prefix?"
- Finding all occurrences of a pattern by concatenating `pattern + separator + text` and scanning the Z-array.

### Tips for Effective Use
- `z[i]` = length of the longest substring starting at `i` that matches a prefix of the string.
- Build by maintaining a window `[l, r]` - the rightmost interval matching a prefix - to avoid recomputation, same spirit as Manacher's.
- To find pattern `p` in text `s`: build Z-array of `p + '#' + s`; any position with `z[i] == len(p)` is a match start (adjusted for the prefix + separator length).

### Recognition
- Keywords: "prefix function", "Z-array", "pattern occurrences", problems explicitly mentioning Z-function (less common for freshers but appears in competitive-programming-flavored OAs).

### Detailed Template
```cpp
vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

vector<int> findOccurrences(const string& text, const string& pattern) {
    string combined = pattern + "#" + text;
    vector<int> z = zFunction(combined);
    vector<int> result;
    int m = pattern.size();
    for (int i = m + 1; i < (int)combined.size(); i++) {
        if (z[i] == m) result.push_back(i - m - 1);
    }
    return result;
}
```

### Time and Space Considerations
- O(n + m) time, O(n + m) space (combined string + Z-array).

### Constraints and Strategies
- Choose a separator character guaranteed **not** to appear in either string (commonly `#` or `$`).
- Functionally similar to KMP for exact pattern matching - pick whichever you can implement correctly under pressure; KMP is more commonly expected in fresher interviews, Z-function is a good bonus to mention.

---

## 9. Trie (Prefix Tree)

### When to Use
- Autocomplete, prefix search, "longest common prefix" across many strings, word dictionary lookups (exact + wildcard), word break problems.

### Tips for Effective Use
- Each Trie node holds a fixed-size array of children (26 for lowercase) or a hashmap for larger alphabets, plus an `isEnd` flag.
- Insertion and search are both O(L) where L = length of the word - independent of how many words are stored, unlike a hashset-of-strings approach for prefix queries.
- For wildcard search (`.` matches any character), use DFS/backtracking through the Trie instead of a simple loop.

### Recognition
- Keywords: "implement Trie", "autocomplete", "longest common prefix", "word dictionary with wildcard search", "word break".

### Detailed Template
```cpp
class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};
```

### Time and Space Considerations
- Insert/Search/StartsWith: O(L) time where L = word/prefix length.
- Space: O(total characters across all inserted words) in the worst case (no shared prefixes); much less when prefixes overlap heavily.

### Constraints and Strategies
- For large/sparse alphabets (unicode), use `unordered_map<char, TrieNode*>` per node instead of a fixed-size array to save memory.
- Remember to free/manage memory in production code (not usually required in interviews, but mention it if asked about memory management).
- Combine with DFS/backtracking for problems like Word Search II (grid + dictionary) - Trie prunes the search space significantly.

---

## 10. Backtracking on Strings (Permutations / Subsequences / Combinations)

### When to Use
- Generate all permutations, subsequences, subsets, or valid combinations of characters (e.g., letter combinations of a phone number, generate parentheses, palindrome partitioning).

### Tips for Effective Use
- Standard backtracking skeleton: choose a character → recurse on the rest → undo the choice (backtrack).
- For permutations, track used indices/characters with a boolean array or by swapping in place.
- For "generate parentheses" style problems, track open/close counts as constraints instead of generating-then-filtering (much faster, avoids invalid branches early).
- For palindrome partitioning, precompute a palindrome-check table (`isPalin[i][j]`) with DP to avoid recomputing palindrome checks inside the backtracking recursion.

### Recognition
- Keywords: "all permutations", "all subsequences/subsets of a string", "generate parentheses", "letter combinations", "palindrome partitioning", "word break II (all ways)".

### Detailed Template
```cpp
// All permutations of a string (distinct characters)
void permute(string& s, int idx, vector<string>& result) {
    if (idx == (int)s.size()) { result.push_back(s); return; }
    for (int i = idx; i < (int)s.size(); i++) {
        swap(s[idx], s[i]);
        permute(s, idx + 1, result);
        swap(s[idx], s[i]); // backtrack
    }
}

// Generate Parentheses
void generateHelper(int open, int close, int n, string& current, vector<string>& result) {
    if ((int)current.size() == 2 * n) { result.push_back(current); return; }
    if (open < n) {
        current.push_back('(');
        generateHelper(open + 1, close, n, current, result);
        current.pop_back();
    }
    if (close < open) {
        current.push_back(')');
        generateHelper(open, close + 1, n, current, result);
        current.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    generateHelper(0, 0, n, current, result);
    return result;
}

// Palindrome Partitioning
bool isPalindromeRange(const string& s, int i, int j) {
    while (i < j) if (s[i++] != s[j--]) return false;
    return true;
}
void partitionHelper(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
    if (start == (int)s.size()) { result.push_back(path); return; }
    for (int end = start; end < (int)s.size(); end++) {
        if (isPalindromeRange(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            partitionHelper(s, end + 1, path, result);
            path.pop_back();
        }
    }
}
```

### Time and Space Considerations
- Permutations: O(n · n!) time (n! permutations, O(n) to build/copy each), O(n) recursion depth.
- Generate Parentheses: O(4^n / sqrt(n)) time (Catalan number growth), O(n) recursion depth.
- Palindrome Partitioning: O(n · 2^n) worst case time, improved with DP precomputed palindrome table to O(n²) for the check phase.

### Constraints and Strategies
- Backtracking is inherently exponential - only viable when `n` is small (typically n ≤ 12-20 depending on branching factor). Always check constraints before assuming this pattern is intended.
- Prune early: add constraints (like open/close balance) directly into the recursion rather than generating everything and filtering afterward.
- Precompute expensive checks (like palindrome validity) outside/before the recursive branching when they're reused across many branches.

---
