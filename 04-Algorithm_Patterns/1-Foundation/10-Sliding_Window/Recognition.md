# Sliding Window — Recognition

How to go from reading a problem statement to identifying **which variation** of Sliding Window applies, in under 30 seconds.

## Recognition Checklist (run through in order)

### Step 1 — Is a fixed window size `k` explicitly given?
- **Yes** → **Fixed-Size Window**.
- **No** → go to Step 2.

### Step 2 — Does the problem ask for the LONGEST valid range?
- **Yes, "longest substring/subarray with condition X"** → **Variable-Size Window (Longest)**.

### Step 3 — Does the problem ask for the SHORTEST/MINIMUM valid range?
- **Yes, "minimum window", "shortest subarray with sum ≥ target"** → **Variable-Size Window (Shortest)**.

### Step 4 — Does the problem need the MAX or MIN *inside* every window, not just whether the window is valid?
- **Yes, "sliding window maximum/minimum"** → **Monotonic Deque Window**.

### Step 5 — Does the problem ask for "EXACTLY K" of something (not "at most" or "at least")?
- **Yes** → **At-Most-K Trick**: compute `atMost(K) - atMost(K-1)`.

### Step 6 — Does the problem involve matching another string's character composition (anagram/permutation)?
- **Yes** → **Fixed-Size Window + Frequency Array**, window size = length of the pattern string.

## Keyword-to-Variation Map

| Keywords in Problem Statement | Likely Variation |
|---|---|
| "subarray of size k", "every window of length k" | Fixed-Size Window |
| "maximum average subarray" | Fixed-Size Window |
| "longest substring without repeating characters" | Variable-Size (Longest) |
| "longest subarray with sum at most / ≤ k" | Variable-Size (Longest) |
| "at most k distinct characters" | Variable-Size (Longest) |
| "longest repeating character replacement" | Variable-Size (Longest), with a "max frequency in window" trick |
| "minimum window substring" | Variable-Size (Shortest) |
| "smallest subarray with sum ≥ target" | Variable-Size (Shortest) |
| "minimum size subarray containing all of..." | Variable-Size (Shortest) |
| "sliding window maximum" / "sliding window minimum" | Monotonic Deque Window |
| "exactly k distinct elements" | At-Most-K Trick |
| "exactly k odd numbers" | At-Most-K Trick |
| "find all anagrams in a string" | Fixed-Size Window + Frequency Array |
| "permutation in string" | Fixed-Size Window + Frequency Array |

## Disambiguation: Longest vs Shortest Variable Window
Both variations use the same skeleton (`for right: expand, while(condition): shrink`), but the placement of "record the answer" differs — this is the #1 point of confusion:

- **Longest:** you want the window to stay as **large** as possible. You only shrink when the window becomes **invalid**, and you record the answer **after** the shrink loop (i.e., once the window is valid/expanded to its current max).
  ```cpp
  for (right) {
      // add s[right] to window
      while (window invalid) {
          // remove s[left], left++
      }
      // window is valid here — record max(right - left + 1)
  }
  ```
- **Shortest:** you want the window to shrink as much as **possible** once valid. You shrink **while still valid**, recording the answer **inside** the shrink loop (before it becomes invalid again).
  ```cpp
  for (right) {
      // add s[right] to window
      while (window valid) {
          // record min(right - left + 1) BEFORE shrinking
          // remove s[left], left++
      }
  }
  ```

Getting this "when do I record the answer" placement backward is the most common Sliding Window bug — always double check which variant you're writing.

## Red Flag: When It Looks Like Sliding Window But Isn't
- If the array contains **negative numbers** and the condition is sum-based (e.g., "longest subarray with sum ≤ k") — the simple shrink logic can break because adding an element doesn't monotonically increase the sum. Use **Prefix Sum + HashMap/Monotonic Deque** instead.
- If the required elements can be **non-contiguous** (a subsequence, not a subarray/substring) — Sliding Window doesn't apply; consider DP.
- If the "window" needs to track information from **two or more disjoint ranges simultaneously** — a single window can't represent this; consider splitting into multiple passes or a different structure.