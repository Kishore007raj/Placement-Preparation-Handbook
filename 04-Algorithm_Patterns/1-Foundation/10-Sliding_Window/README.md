# Sliding Window - Algorithm Pattern Deep Dive

A focused, ace-the-interview breakdown of the **Sliding Window** pattern. Language: **C++**.

## Folder Contents

| File | Purpose | Read When |
|---|---|---|
| `When_To_Use.md` | Signals that tell you Sliding Window is the right tool | First - decide if this pattern applies |
| `Recognition.md` | How to recognize the *exact variation* needed from problem phrasing | Right after deciding Sliding Window applies |
| `Variations.md` | All flavors of Sliding Window (fixed, variable-longest, variable-shortest, monotonic deque, at-most-K trick) | Core study material |
| `Template.cpp` | Ready-to-paste C++ templates for every variation | While practicing / during OA |
| `Examples.md` | Fully worked examples with step-by-step reasoning | To see the pattern applied end-to-end |
| `Complexity.md` | Time & space complexity for every variation | When comparing approaches |
| `Complexity_Mistakes.md` | Common complexity miscalculations and why they happen | Before an interview - avoid these traps |
| `Practice_Problems.md` | Curated problem list by difficulty, with which variation each uses | For structured practice |

## What Is the Sliding Window Pattern?
Sliding Window maintains a contiguous range `[left, right]` over an array or string and moves its boundaries according to a rule, instead of recomputing results for every possible subarray/substring from scratch. It converts many O(n²) or O(n³) brute-force solutions (checking every subarray/substring) into O(n) by reusing work already done as the window slides - you add the incoming element and remove the outgoing one, rather than recomputing the whole window's state.

It is closely related to (and often implemented via) Two Pointers - Sliding Window is specifically the "same starting end, same direction, expand/shrink" flavor described in that folder's `Variations.md`.

## Suggested Study Order
1. `When_To_Use.md` → `Recognition.md` - build the intuition for *spotting* this pattern fast, and telling fixed vs variable window apart.
2. `Variations.md` - learn every flavor, including the less obvious ones (monotonic deque, at-most-K trick).
3. `Template.cpp` - type out every template by hand until automatic.
4. `Examples.md` - walk through fully worked problems to see the reasoning, not just the code.
5. `Complexity.md` + `Complexity_Mistakes.md` - make sure you can defend your complexity claims (especially the amortized argument) out loud.
6. `Practice_Problems.md` - grind the list, two passes each (brute force, then optimal).

## Quick Definition Table
| Variation | Window Behavior | Typical Use |
|---|---|---|
| Fixed-Size Window | size stays constant at k, both ends move together | max/min sum or average of k consecutive elements |
| Variable-Size (Longest) | grow right, shrink left only when window becomes invalid | longest substring without repeating chars, longest subarray with sum ≤ k |
| Variable-Size (Shortest) | grow right, shrink left greedily while window stays valid | minimum size subarray sum ≥ target, minimum window substring |
| Monotonic Deque Window | fixed/variable window + a deque tracking max/min in O(1) amortized | sliding window maximum/minimum |
| At-Most-K Trick | compute `atMost(K) - atMost(K-1)` to get "exactly K" | subarrays with exactly K distinct elements |

---
