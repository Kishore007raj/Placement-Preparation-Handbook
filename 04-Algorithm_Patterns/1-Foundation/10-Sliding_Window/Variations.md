# Sliding Window Variations

# 1. Fixed-Size Window

## Overview

The window size is fixed throughout the algorithm. Once the window reaches the required size, every new element added to the window is matched by removing one element from the left. The window size never changes.

## When to Use

Use this pattern whenever the problem specifies a fixed window size:

* Maximum sum of `k` consecutive elements
* Minimum sum of `k` elements
* Average of every window of size `k`
* Maximum number of vowels in a substring of length `k`

## Recognition Pattern

Look for words like:

* Window of size `k`
* Exactly `k` elements
* Consecutive `k`
* Fixed length substring
* Fixed length subarray

## Core Idea

* Expand until the window size becomes `k`.
* Process the current window.
* Remove the left element.
* Continue sliding.

The window always contains exactly `k` elements.

## Algorithm

1. Initialize `left = 0`.
2. Expand the window using `right`.
3. Once the window size becomes `k`:
   * Compute/update the answer.
   * Remove the left element.
   * Move `left`.
4. Continue until the end.

## Generic Template

```cpp
int left = 0;

for (int right = 0; right < nums.size(); right++)
{
    // Add current element

    if (right - left + 1 == k)
    {
        // Process current window

        // Remove left element
        left++;
    }
}
```

## Interview Template

```cpp
int left = 0;

// Current window information
// sum / count / frequency / etc.

for (int right = 0; right < nums.size(); right++)
{
    // Expand
    ...

    // Window reaches size k
    if (right - left + 1 == k)
    {
        // Process current window
        ...

        // Slide the window
        ...

        left++;
    }
}
```

## The 4-Step Rule

```text
1. Expand the window

2. Wait until window size becomes k

3. Process the current window

4. Remove the left element and slide
```

## What Changes Between Problems?

Only these two things change:

1. **What information is stored inside the window?**
   * Running sum
   * Frequency
   * Count
   * Maximum/Minimum
   * Average

2. **How is the answer updated?**
   * Maximum
   * Minimum
   * Average
   * Count
   * Boolean

Everything else remains identical.

## Time Complexity

**O(n)** — Each element enters and leaves the window exactly once.

## Space Complexity

**O(1)** — Only a few variables are maintained.

## Common Problems

* Maximum Sum Subarray of Size K
* Maximum Average Subarray I
* Maximum Number of Vowels in a Substring of Given Length

## Common Mistakes

* Updating the answer before the window actually reaches size `k`.
* Forgetting to remove the left element after processing, which silently turns this into a growing window.
* Recomputing the sum/frequency from scratch on every slide instead of updating in O(1).
* Off-by-one errors in the `right - left + 1 == k` condition.

## Key Points

* Window size never changes.
* Slide by removing one element and adding one element.
* Running sum/frequency avoids recomputation.

## Key Insight

> **Whenever the window size is fixed, never rebuild the window from scratch. Simply remove one element, add one element, and update the running information in O(1).**

## Quick Revision

Fixed size `k` → expand until size `k` → process → pop left → repeat. O(n) time, O(1) space.

---
---

# 2. Variable-Size Window (Longest)

## Overview

The window size changes dynamically. The window keeps expanding until it becomes invalid. Once invalid, shrink it until it becomes valid again. The goal is to find the **longest** valid window.

## When to Use

Use this pattern when the problem asks for:

* Longest substring
* Longest subarray
* Maximum length
* At most `K`
* Without duplicates

## Recognition Pattern

Look for phrases like:

* Longest substring
* Maximum length
* At most K
* Without repeating
* At most two distinct
* Longest valid segment

## Core Idea

* Expand the window.
* If invalid, shrink until valid.
* Record the maximum window size after restoring validity.

## Algorithm

1. Expand the window.
2. Update window information.
3. While the window is invalid:
   * Remove the left element.
   * Move `left`.
4. Record the maximum window length.

## Generic Template

```cpp
int left = 0;
int answer = 0;

for (int right = 0; right < nums.size(); right++)
{
    // Expand

    while (/* invalid */)
    {
        // Shrink
        left++;
    }

    answer = max(answer, right - left + 1);
}
```

## Interview Template

```cpp
int left = 0;
int answer = 0;

for (int right = 0; right < nums.size(); right++)
{
    // Expand
    ...

    while (/* Window is INVALID */)
    {
        // Shrink
        ...

        left++;
    }

    // Window is now valid
    answer = max(answer, right - left + 1);
}
```

## The 4-Step Rule

```text
1. Expand

2. If the window becomes invalid

3. Shrink until it becomes valid again

4. Record the maximum valid window
```

## What Changes Between Problems?

Only two parts change:

1. **What makes the window invalid?**
   * Duplicate character
   * Too many distinct elements
   * Sum exceeds limit
   * More than K replacements

2. **What information is stored?**
   * Frequency map
   * Running sum
   * Distinct count
   * Maximum frequency

Everything else stays the same.

## Time Complexity

**O(n)** — Each element is processed at most twice.

## Space Complexity

* **O(1)** for counters
* **O(k)** when using a hash map or frequency array

## Common Problems

* Longest Substring Without Repeating Characters
* Longest Repeating Character Replacement
* Fruit Into Baskets
* Longest Substring with At Most K Distinct Characters

## Common Mistakes

* Shrinking the window even when it's still valid ("shrinking early"), which loses the longest possible answer.
* Using `if` instead of `while` for the shrink condition, so the window doesn't fully return to valid.
* Updating the answer inside the shrink loop instead of after it.
* Forgetting to update window state (e.g., frequency counts) when removing the left element.

## Key Points

* Grow first.
* Shrink only when invalid.
* Update the answer after the window becomes valid.

## Key Insight

> **For longest-window problems, never shrink early. Let the window grow as much as possible, and shrink only when the condition is violated.**

## Quick Revision

Expand always → if invalid, shrink with `while` until valid → record `max(right-left+1)` after the loop.

---
---

# 3. Variable-Size Window (Shortest)

## Overview

The window grows until it satisfies the required condition. Once valid, shrink it as much as possible while keeping it valid. The goal is to find the **smallest** valid window.

## When to Use

Use this pattern when the problem asks for:

* Minimum length
* Smallest window
* Shortest substring
* Minimum valid range

## Recognition Pattern

Look for:

* Minimum
* Smallest
* Shortest
* Minimum window
* Smallest valid subarray

## Core Idea

* Expand the window.
* Once valid, keep shrinking.
* Record the answer before the window becomes invalid.

## Algorithm

1. Expand the window.
2. Check whether it becomes valid.
3. While valid:
   * Record the answer.
   * Remove the left element.
   * Move `left`.

## Generic Template

```cpp
int left = 0;
int answer = INT_MAX;

for (int right = 0; right < nums.size(); right++)
{
    // Expand

    while (/* valid */)
    {
        answer = min(answer, right - left + 1);

        // Shrink
        left++;
    }
}
```

## Interview Template

```cpp
int left = 0;
int answer = INT_MAX;

for (int right = 0; right < nums.size(); right++)
{
    // Expand
    ...

    while (/* Window is VALID */)
    {
        answer = min(answer, right - left + 1);

        // Shrink
        ...

        left++;
    }
}
```

## The 4-Step Rule

```text
1. Expand

2. Wait until the window becomes valid

3. Record the answer

4. Shrink while it remains valid
```

## What Changes Between Problems?

Only two things change:

1. **What makes the window valid?**
2. **What information does the window maintain?**

Everything else remains identical.

## Time Complexity

**O(n)** — Each element is added and removed at most once.

## Space Complexity

* **O(1)** for counters
* **O(k)** when using maps or frequency arrays

## Common Problems

* Minimum Window Substring
* Minimum Size Subarray Sum
* Smallest Subarray Containing All Distinct Elements

## Common Mistakes

* Recording the answer only once instead of continuously while the window stays valid.
* Shrinking past the point of validity before recording the answer.
* Forgetting to initialize `answer` to `INT_MAX` (or infinity), causing wrong comparisons.
* Not restoring window state correctly after shrinking past a required element.

## Key Points

* Expand until valid.
* Shrink greedily.
* Record every valid window.

## Key Insight

> **For shortest-window problems, every valid window is a candidate. Keep shrinking until the condition breaks to guarantee the minimum answer.**

## Quick Revision

Expand always → once valid, shrink with `while` recording `min(right-left+1)` each step → stop shrinking when invalid again.

---
---

# 4. Monotonic Deque

## Overview

Instead of storing values, maintain a deque of indices in monotonic order. The deque always keeps the best candidate for the maximum or minimum.

## When to Use

Use this pattern when repeatedly finding the maximum or minimum inside a sliding window.

## Recognition Pattern

Look for:

* Sliding Window Maximum
* Sliding Window Minimum
* Maximum in every window
* Minimum in every window

## Core Idea

For maximum:

* Remove smaller elements from the back.
* Remove expired indices from the front.
* Front always stores the maximum.

For minimum:

* Reverse the comparison.

## Algorithm

1. Remove smaller elements from the back.
2. Insert the current index.
3. Remove expired indices.
4. Front stores the answer.

## Generic Template

```cpp
deque<int> dq;

for (int i = 0; i < nums.size(); i++)
{
    while (!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();

    dq.push_back(i);

    while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();

    if (i >= k - 1)
        answer.push_back(nums[dq.front()]);
}
```

## Interview Template

```cpp
deque<int> dq;

for (int i = 0; i < nums.size(); i++)
{
    while (!dq.empty() &&
           nums[dq.back()] <= nums[i])
        dq.pop_back();

    dq.push_back(i);

    while (!dq.empty() &&
           dq.front() <= i - k)
        dq.pop_front();

    if (i >= k - 1)
        answer.push_back(nums[dq.front()]);
}
```

## The 4-Step Rule

```text
1. Remove smaller (or larger) elements

2. Insert the current index

3. Remove expired indices

4. Read the answer from the front
```

## What Changes Between Problems?

Only these change:

1. **Maximum or Minimum?**
2. **Increasing deque or Decreasing deque?**

Everything else remains unchanged.

## Time Complexity

**O(n)** — Every index enters and leaves the deque only once.

## Space Complexity

**O(k)** — The deque stores at most `k` indices.

## Common Problems

* Sliding Window Maximum
* Sliding Window Minimum
* Shortest Subarray with Sum At Least K (Prefix Sum + Monotonic Deque)

## Common Mistakes

* Storing values instead of indices, which makes expiry checks impossible.
* Using `<` instead of `<=` (or vice versa) when popping from the back, which breaks tie handling.
* Forgetting to check `i >= k - 1` before recording the answer, producing extra/early outputs.
* Not popping expired indices from the front before reading the answer.

## Key Points

* Stores indices, not values.
* Front always contains the answer.
* Each index is pushed and popped at most once.

## Key Insight

> **The deque stores only useful candidates. Every element enters and leaves the deque at most once, giving an O(n) solution.**

## Quick Revision

Pop smaller/larger from back → push current index → pop expired from front → front = answer once `i >= k-1`.

---
---

# 5. At-Most-K Trick

## Overview

Many "Exactly K" counting problems are difficult to solve directly. Instead, solve two easier "At Most K" problems.

**Formula:**

```text
Exactly(K) = AtMost(K) − AtMost(K − 1)
```

## When to Use

Use this pattern when counting subarrays or substrings with exactly `K`.

## Recognition Pattern

Look for:

* Exactly K
* Exactly K distinct
* Exactly K odd numbers
* Exactly K occurrences

## Core Idea

1. Write an `atMost(K)` function.
2. Call it twice.
3. Subtract the answers.

## Algorithm

1. Compute `atMost(K)`.
2. Compute `atMost(K - 1)`.
3. Return the difference.

## Generic Template

```cpp
answer = atMost(K) - atMost(K - 1);
```

## Interview Template

```cpp
int answer = atMost(K) - atMost(K - 1);

int atMost(int K)
{
    int left = 0;
    int result = 0;

    ...

    return result;
}
```

## The 4-Step Rule

```text
1. Write an atMost(K) function

2. Write it only once

3. Call it twice

4. Subtract the results
```

## What Changes Between Problems?

Only these change:

1. **What defines "At Most K"?**
2. **How are valid subarrays counted?**

Everything else remains the same.

## Time Complexity

**O(n)** — Two linear passes.

## Space Complexity

**O(k)** — Usually uses a frequency map.

## Common Problems

* Subarrays with K Different Integers
* Count Nice Subarrays
* Binary Subarrays With Sum

## Common Mistakes

* Trying to solve "Exactly K" directly with a single pass instead of via the `atMost` decomposition.
* Forgetting to handle `K = 0`, which can make `atMost(K - 1)` invalid or negative.
* Miscounting subarrays inside `atMost` — the count added per valid right endpoint should be `right - left + 1`, not `1`.
* Writing two separate, slightly different `atMost` implementations instead of reusing one function.

## Key Points

* Never solve "Exactly K" directly if an "At Most K" version exists.
* Reuse the same helper function twice.

## Key Insight

> **If an "Exactly K" counting problem has a monotonic "At Most K" version, solve the easier problem twice and subtract the results.**

## Quick Revision

Exactly(K) = AtMost(K) − AtMost(K−1). Write `atMost` once, call it twice, subtract.

---
---

# 6. Fixed Window + Frequency Array

## Overview

The window size remains fixed, but character frequencies are maintained instead of a running sum. This variation is commonly used for strings.

## When to Use

Use this pattern when comparing characters inside a fixed-size substring.

## Recognition Pattern

Look for:

* Anagram
* Permutation
* Same character frequency
* Rearrangement
* Pattern matching

## Core Idea

Maintain a frequency array for:

* Pattern
* Current window

Compare both after every slide.

## Algorithm

1. Build the pattern frequency array.
2. Expand the window.
3. Remove the outgoing character.
4. Compare both frequency arrays.

## Generic Template

```cpp
vector<int> freqPattern(26, 0);
vector<int> freqWindow(26, 0);

for (...)
{
    // Add new character

    // Remove old character

    // Compare frequencies
}
```

## Interview Template

```cpp
vector<int> pattern(26, 0);
vector<int> window(26, 0);

for (int right = 0; right < s.size(); right++)
{
    // Add new character

    if (right >= k)
    {
        // Remove old character
    }

    if (window == pattern)
    {
        // Valid match
    }
}
```

## The 4-Step Rule

```text
1. Add the incoming character

2. Remove the outgoing character

3. Update frequencies

4. Compare with the pattern
```

## What Changes Between Problems?

Only these change:

1. **What frequency structure is used?**
   * Array
   * Hash map

2. **How is equality checked?**
   * Direct comparison
   * Matches counter

Everything else stays the same.

## Time Complexity

**O(n)** — Each character is processed once.

## Space Complexity

**O(1)** — Frequency array size is fixed (26 or 256).

## Common Problems

* Find All Anagrams in a String
* Permutation in String
* Substring with Concatenation of All Words

## Common Mistakes

* Comparing full 26-length arrays every slide instead of using a `matches` counter, which can hurt performance at scale.
* Forgetting to remove the outgoing character once the window exceeds size `k`.
* Off-by-one errors in the `right >= k` boundary check for when to start removing characters.
* Rebuilding the frequency array from scratch each slide instead of updating incrementally.

## Key Points

* Window size is fixed.
* Frequency arrays make comparisons efficient.
* Best suited for character-based problems.

## Key Insight

> **Instead of comparing substrings character by character, compare their frequency distributions. Sliding updates make each window change in O(1), producing an overall O(n) solution.**

## Quick Revision

Fixed size `k`, frequency array for pattern + window, add/remove one char per slide, compare arrays (or a `matches` counter) for O(n) total.

---
---

> **Note:** Sections 7–10 below are hybrid or specialized patterns rather than pure sliding window techniques. They combine sliding window with another technique (prefix sums, hash maps) or apply it to a special array shape (circular, multi-window). They're grouped separately from the core six for revision, but follow the same 16-part layout for consistency.

---
---

# 7. Prefix Sum + Sliding Window (Hybrid Pattern)

## Overview

This is not a pure sliding window pattern. It combines **Prefix Sum** with a window-like approach when cumulative sums are more useful than maintaining a running window alone — typically because the array contains negative numbers or the running sum isn't monotonic.

## When to Use

* Subarray sum equals `K`
* Subarray sum divisible by `K`
* Arrays containing negative numbers, where a simple two-pointer window would fail
* Range-sum queries that need to be answered repeatedly

## Recognition Pattern

Look for:

* Subarray sum equals K
* Contains negative numbers
* Range sum queries
* Continuous subarray sum

## Core Idea

* Build a prefix sum array so any range sum is a simple subtraction.
* Use an auxiliary structure (hash map, binary search, or monotonic deque) on the prefix sums to find pairs that satisfy the condition.
* Update the answer as prefix sums are processed.

## Algorithm

1. Build the prefix sum array.
2. Use prefix sums to compute range sums in O(1).
3. Apply the required companion technique (Binary Search / Hash Map / Deque).
4. Update the answer.

## Generic Template

```cpp
vector<int> prefix(n + 1, 0);

for (int i = 0; i < n; i++)
{
    prefix[i + 1] = prefix[i] + nums[i];
}

// Use prefix sums according to the problem.
```

## Interview Template

```cpp
vector<int> prefix(n + 1, 0);

for (int i = 0; i < n; i++)
{
    prefix[i + 1] = prefix[i] + nums[i];
}

// Use prefix sums according to the problem.
// Sometimes combined with binary search,
// hash map, or monotonic deque.
```

## The 4-Step Rule

```text
1. Build the prefix sum array

2. Use prefix sums to compute range sums

3. Apply the required technique
   (Binary Search / Hash Map / Deque)

4. Update the answer
```

## What Changes Between Problems?

Only these change:

1. **How are prefix sums used?**
   * Binary Search
   * Hash Map
   * Monotonic Deque

2. **What condition are we checking?**
   * Sum ≥ K
   * Sum = K
   * Maximum sum
   * Minimum length

Everything else follows the same prefix-sum idea.

## Time Complexity

**O(n)** with a hash map; **O(n log n)** if paired with binary search.

## Space Complexity

**O(n)** for the prefix array and any auxiliary hash map/deque.

## Common Problems

* Subarray Sum Equals K
* Continuous Subarray Sum
* Shortest Subarray with Sum At Least K

## Common Mistakes

* Forgetting to initialize `prefix[0] = 0`, which breaks sums that start from index 0.
* Trying to use a plain two-pointer window on arrays with negative numbers, where sums aren't monotonic.
* Not choosing the right companion structure (hash map for "equals K", monotonic deque for "at least K" with negatives).

## Key Points

* Converts any range sum into an O(1) subtraction.
* Almost always paired with a hash map, binary search, or deque to be useful.

## Key Insight

> **When maintaining a running window is difficult (because of negative numbers or non-monotonic behavior), prefix sums often simplify the problem by converting range sums into simple arithmetic.**

## Quick Revision

Build `prefix[]` → pair with hash map / binary search / deque depending on the condition → O(1) range sums make the rest of the logic simple.

---
---

# 8. Circular Sliding Window

## Overview

Handles arrays where the window needs to wrap around from the end back to the start, simulated by iterating past the array's length using modulo indexing (or by duplicating the array).

## When to Use

* Circular array traversal problems
* Windows that may span across the end and beginning of the array
* Problems explicitly describing a circular buffer or circular array

## Recognition Pattern

Look for:

* Circular array
* Wrap around
* Circular buffer
* "Next" element loops back to the start

## Core Idea

* Simulate the circular array by iterating up to `2 * n`.
* Index into the real array using `i % n`.
* Keep the window from ever exceeding one full cycle (`n` elements).

## Algorithm

1. Simulate a circular array by looping `right` from `0` to `2n`.
2. Expand normally using `nums[right % n]`.
3. Shrink if the window grows larger than allowed.
4. Process the answer.

## Generic Template

```cpp
int left = 0;

for (int right = 0; right < 2 * n; right++)
{
    int current = nums[right % n];

    // Expand

    while (/* window too large */)
    {
        // Shrink
        left++;
    }

    // Process answer
}
```

## Interview Template

```cpp
int left = 0;

for (int right = 0; right < 2 * n; right++)
{
    int current = nums[right % n];

    // Expand

    while (/* window too large */)
    {
        // Shrink
        left++;
    }

    // Process answer
}
```

## The 4-Step Rule

```text
1. Simulate a circular array

2. Expand normally

3. Keep the window within limits

4. Process the answer
```

## What Changes Between Problems?

Only these change:

1. **How is circular traversal handled?**
   * Modulo (%)
   * Array duplication

2. **Maximum allowed window size**

Everything else is identical to a normal sliding window.

## Time Complexity

**O(n)** — the loop runs at most `2n` times.

## Space Complexity

**O(1)** with modulo indexing; **O(n)** if the array is duplicated.

## Common Problems

* Circular Array Loop
* Maximum Sum Circular Subarray (window variant)
* Constrained Subsequence problems on circular arrays

## Common Mistakes

* Forgetting to cap the window at `n` elements, letting it revisit the same element twice.
* Indexing without `% n`, causing out-of-bounds access.
* Not stopping the loop at `2n`, which can cause the window to wrap more than once.

## Key Points

* Treat the circular array as a linear array of length `2n`.
* The window must never exceed one full cycle.

## Key Insight

> **Treat the circular array as a linear array by using modulo indexing or duplicating the array, while ensuring the window never exceeds one full cycle.**

## Quick Revision

Loop `right` from `0` to `2n`, index with `right % n`, cap window size at `n`.

---
---

# 9. Multi-Window Sliding Window

## Overview

Less common but useful in advanced interview problems — some problems require tracking **multiple independent windows** simultaneously instead of relying on a single window, then combining their results.

## When to Use

* Problems comparing two subarrays or substrings
* Splitting the array into multiple parts under separate constraints
* "Two non-overlapping subarrays" style problems

## Recognition Pattern

Look for:

* Two windows
* Non-overlapping subarrays
* Combine two windows
* Left window and right window

## Core Idea

* Maintain each window's state (its own `left`/`right` pointers and running info) independently.
* Update each window as needed.
* Combine their information to produce the final answer.

## Algorithm

1. Maintain multiple windows.
2. Update each independently.
3. Combine their information.
4. Update the final answer.

## Generic Template

```cpp
// Window 1
...

// Window 2
...

// Process both windows independently
// or combine their results.
```

## Interview Template

```cpp
// Window 1
...

// Window 2
...

// Process both windows independently
// or combine their results.
```

## The 4-Step Rule

```text
1. Maintain multiple windows

2. Update each independently

3. Combine their information

4. Update the final answer
```

## What Changes Between Problems?

Only these change:

1. **Number of windows**
2. **How their results are combined**

Everything else follows the same sliding-window principles.

## Time Complexity

**O(n)** overall — each window is still processed in linear time, even when maintained together.

## Space Complexity

**O(1) to O(k)** depending on what each window tracks.

## Common Problems

* Maximum Sum of Two Non-Overlapping Subarrays
* Splitting an array into two parts under separate constraints
* Problems requiring a left window and a right window to be combined

## Common Mistakes

* Forgetting to enforce the non-overlap constraint between windows.
* Combining results before both windows have finished updating.
* Not considering both orderings when the two windows' relative position matters (e.g., window A before window B vs. after).

## Key Points

* Each window is tracked independently.
* The final answer merges results from all windows.

## Key Insight

> **Some problems require tracking multiple independent windows simultaneously instead of relying on a single window.**

## Quick Revision

Track each window with its own pointers/state → update independently → merge results at the end.

---
---

# 10. Sliding Window with Hash Map

## Overview

A generalization of the Variable-Size Sliding Window pattern. Instead of a fixed-size frequency array (limited to a small alphabet), a hash map is used, making the window suitable for arbitrary values or characters.

## When to Use

* Distinct elements / distinct characters conditions
* Values with a large or unknown range (not just lowercase letters)
* Duplicate detection, frequency-based validity conditions

## Recognition Pattern

Look for:

* Distinct characters
* No more than K distinct
* Duplicate within a distance
* Frequency of elements

## Core Idea

* Expand the window, adding elements to a hash map of frequencies.
* While the window is invalid, shrink from the left, decrementing (and erasing) map entries.
* Update the answer once the window is valid again.

## Algorithm

1. Expand the window and update the hash map.
2. Check whether the window is invalid.
3. While invalid, remove the left element from the map (erasing entries that hit zero) and move `left`.
4. Update the answer.

## Generic Template

```cpp
unordered_map<char, int> freq;

int left = 0;

for (int right = 0; right < s.size(); right++)
{
    freq[s[right]]++;

    while (/* invalid */)
    {
        freq[s[left]]--;

        if (freq[s[left]] == 0)
            freq.erase(s[left]);

        left++;
    }

    // Update answer
}
```

## Interview Template

```cpp
unordered_map<char, int> freq;

int left = 0;

for (int right = 0; right < s.size(); right++)
{
    freq[s[right]]++;

    while (/* invalid */)
    {
        freq[s[left]]--;

        if (freq[s[left]] == 0)
            freq.erase(s[left]);

        left++;
    }

    // Update answer
}
```

## The 4-Step Rule

```text
1. Expand

2. Update the hash map

3. Shrink if needed

4. Update the answer
```

## What Changes Between Problems?

Only these change:

1. **What does the map store?**
   * Frequency
   * Last occurrence
   * Distinct count

2. **What defines an invalid window?**

Everything else stays the same.

## Time Complexity

**O(n)** amortized — hash map operations are O(1) on average.

## Space Complexity

**O(k)**, where `k` is the number of distinct elements currently in the window.

## Common Problems

* Longest Substring with At Most K Distinct Characters
* Contains Duplicate II
* Subarrays with K Different Integers (often paired with the At-Most-K Trick)

## Common Mistakes

* Forgetting to `erase` a key once its count hits zero, which makes `map.size()` overcount distinct elements.
* Relying on `map.size()` for a distinct-element count without cleaning up zero-count entries.
* Treating map lookups as free — unnecessary repeated lookups can add overhead even though complexity stays O(1) amortized.

## Key Points

* Generalizes the fixed-size frequency array to arbitrary values.
* Always erase zero-count keys so `size()` reflects the true distinct count.

## Key Insight

> **A hash map lets the sliding window handle arbitrary values or characters efficiently, making it suitable for problems involving distinct elements, frequencies, or duplicates.**

## Quick Revision

Same as Variable-Size Window, but frequencies live in a hash map — erase zero-count keys to keep the distinct count accurate.

---
---

# Quick Comparison (All Variations)

| Variation               | Window Size   | Shrink Condition                            | When to Record Answer                  | Time     | Space           |
| ------------------------ | ------------- | -------------------------------------------- | ---------------------------------------- | -------- | ---------------- |
| Fixed-Size               | Fixed (`k`)   | Never (slides automatically)                | Every time the window reaches size `k` | **O(n)** | **O(1)**        |
| Variable (Longest)       | Dynamic       | When window becomes invalid                 | After the window becomes valid         | **O(n)** | **O(1) / O(k)** |
| Variable (Shortest)      | Dynamic       | While window remains valid                  | Inside the shrink loop                 | **O(n)** | **O(1) / O(k)** |
| Monotonic Deque          | Usually Fixed | Remove smaller elements and expired indices | Front of deque is the answer           | **O(n)** | **O(k)**        |
| At-Most-K Trick          | Dynamic       | Standard "At Most K" logic                  | `atMost(K) - atMost(K - 1)`             | **O(n)** | **O(k)**        |
| Fixed + Frequency Array  | Fixed         | Never (slides automatically)                | Compare frequencies after each slide   | **O(n)** | **O(1)**        |

This format keeps every variation consistent, easy to revise, and suitable for interview preparation.

---
---

# Master Recognition Rules

| If the Question Says...         | Use...                                                                            |
| -------------------------------- | ----------------------------------------------------------------------------------- |
| Exactly **k** consecutive        | Fixed-Size Window                                                                  |
| Longest                          | Variable Window (Longest)                                                         |
| Shortest / Minimum               | Variable Window (Shortest)                                                        |
| Maximum in every window          | Monotonic Deque                                                                   |
| Minimum in every window          | Monotonic Deque                                                                   |
| Exactly **K**                    | At-Most-K Trick                                                                   |
| Anagram / Permutation            | Fixed + Frequency Array                                                           |
| Circular Array                   | Circular Sliding Window                                                           |
| Negative Numbers + Sum           | Prefix Sum + Monotonic Deque (or Prefix Sum + Hash Map, depending on the problem) |
| Distinct Elements / Frequencies  | Variable Window + Hash Map                                                        |

---
---

# Final Interview Cheat Sheet

| Pattern              | Expand                    | Shrink                              | Record Answer              |
| --------------------- | -------------------------- | -------------------------------------- | ----------------------------- |
| Fixed-Size            | Always                    | Automatic when size = `k`           | Every complete window      |
| Variable (Longest)    | Always                    | When invalid                        | After shrinking             |
| Variable (Shortest)   | Always                    | While valid                         | Inside shrink loop          |
| Monotonic Deque       | Insert index              | Remove expired/useless indices      | Front of deque              |
| At-Most-K             | Standard variable window  | Standard variable window            | `atMost(K) - atMost(K-1)`   |
| Frequency Array       | Add new character         | Remove old character                | Compare frequencies         |
| Circular Window       | Expand with modulo        | Maintain valid size                 | Normal update                |
| Prefix Sum Hybrid     | Build prefix sums         | Depends on the companion technique  | Depends on the problem       |
| Multi-Window          | Expand each window        | Depends on each window's rule       | Combine results at the end   |
| Hash Map Window       | Add to hash map            | Erase zero-count keys while invalid | After the window is valid    |

---

### Note

For interview preparation (LeetCode, NeetCode, Blind 75, and most product-company interviews), the **first six patterns** (Fixed-Size, Variable-Longest, Variable-Shortest, Monotonic Deque, At-Most-K, Fixed + Frequency Array) are the ones you should master thoroughly. Patterns 7–10 (Prefix Sum Hybrid, Circular Window, Multi-Window, Hash Map Window) are specialized techniques that appear less frequently or are combinations with other algorithms rather than standalone sliding window patterns — good to recognize, but secondary priority.
