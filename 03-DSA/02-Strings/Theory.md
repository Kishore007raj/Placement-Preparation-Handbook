# 02 - Strings - Theory

## What is a String (in C++)?
`std::string` is a dynamic, mutable sequence of characters (built on top of a `vector<char>`-like structure internally). Unlike C-style `char[]` arrays, `std::string` manages its own memory, supports concatenation, comparison, and many built-in member functions.

### Key Properties
| Operation | Time Complexity |
|---|---|
| Access by index `s[i]` | O(1) |
| `s.length()` / `s.size()` | O(1) |
| Concatenation `s1 + s2` | O(n + m) (new string allocated) |
| `substr(pos, len)` | O(len) (copies characters) |
| Comparison `s1 == s2` | O(min(n, m)) |
| Insert/erase at arbitrary position | O(n) - shifts remaining characters |
| Append single char (`push_back`) | O(1) amortized |

### Mutability
- `std::string` is mutable - you can modify characters in place: `s[i] = 'x';`
- Careful: string literals assigned to `const char*` are immutable; always use `std::string` for problems requiring mutation.

### Common Built-in Functions Worth Knowing
```cpp
s.substr(pos, len);        // substring starting at pos, length len
s.find(t);                 // returns index of first occurrence of t, or string::npos
s.find(t, fromIndex);      // search starting from fromIndex
reverse(s.begin(), s.end()); // in-place reversal
sort(s.begin(), s.end());  // sort characters
transform(s.begin(), s.end(), s.begin(), ::tolower); // lowercase entire string
stoi(s); to_string(n);     // string <-> int conversions
s.append(t); s += t;       // concatenation
```

## Character Sets & Encoding
- ASCII: 128 characters (0-127); lowercase letters occupy indices 97-122 (`'a'`-`'z'`).
- Most interview problems assume **lowercase English letters only** unless stated otherwise - this justifies using `int count[26]` instead of a full hashmap.
- Watch for problems explicitly mentioning uppercase, digits, or unicode - these require either a larger fixed array (128/256) or a hashmap.

## Why Strings Get Their Own Topic (Beyond Arrays)
Strings are technically arrays of characters, so many array patterns (two pointers, sliding window, hashing) directly apply. But strings introduce topic-specific problems:
1. **Pattern matching** - finding one string inside another efficiently (KMP, Rabin-Karp, Z-function) - this has no true array analog.
2. **Palindromes** - a recurring string-specific structural property (expand-around-center, Manacher's).
3. **Tries** - a data structure built specifically for prefix relationships between strings.
4. **String immutability considerations** - concatenation costs, avoiding O(n²) blowup from repeated `+=` in a loop (use `string` reserve / build via vector<char> then join, or `stringstream`, for very large builds).

## Complexity Traps Specific to Strings
- Repeated string concatenation in a loop (`result += s;` many times) can silently become O(n²) - each `+=` may reallocate/copy. Use `reserve()` upfront if final size is known, or build via a `vector<char>`/`ostringstream` and convert once.
- `substr()` **copies** characters - calling it repeatedly inside a loop (e.g., inside Rabin-Karp verification) adds hidden O(k) cost per call; be aware of this when reasoning about total complexity.
- String comparison (`==`) is O(min(n,m)), not O(1) - comparing many strings pairwise (e.g., inside a naive anagram grouping) can add up.

## Mental Model Summary
- Treat strings as arrays first - two pointers, sliding window, and hashing patterns from the Arrays topic apply almost unchanged.
- Layer on string-specific patterns (KMP/Rabin-Karp/Z-function for matching, expand-around-center/Manacher's for palindromes, Trie for prefix problems) when the array patterns alone don't capture the problem's structure.
- Backtracking on strings (permutations, subsequences, partitions) is really "array backtracking" wearing a string costume - the core recursion skeleton is identical to array/subset backtracking.