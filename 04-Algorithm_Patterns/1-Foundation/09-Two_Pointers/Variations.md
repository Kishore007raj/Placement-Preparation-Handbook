# Two Pointers Variations

# 1. Opposite-Direction (Converging Pointers)

## Overview

Two pointers start at opposite ends of a sorted (or otherwise order-exploitable) structure and move toward each other, narrowing the search space by one element every step based on a comparison.

## When to Use

* Pair sum in a sorted array
* 3Sum / 4Sum (outer loop fixes one element, inner two-pointer sweep on the rest)
* Container With Most Water
* Trapping Rain Water (with auxiliary max-so-far tracking)
* Valid Palindrome
* Reversing an array/string in place

## Recognition Pattern

Look for:

* Sorted array
* Pair that sums to a target
* Palindrome check
* Reverse in place
* Maximum area / container

## Pointer Movement Logic

```text
Start:
left = 0
right = n - 1

Compare nums[left] and nums[right].

If the current value is too small:
    Move left++

If the current value is too large:
    Move right--

If a valid answer is found:
    Record it
    Move one or both pointers depending on the problem
```

## Core Idea

Each comparison eliminates one end from further consideration — the pointers converge until they meet or cross, checking the search space in a single linear pass instead of all pairs.

## Algorithm

1. Initialize `left = 0`, `right = n - 1`.
2. While `left < right`:
   * Evaluate the current pair.
   * Move `left`, `right`, or both, based on the comparison.
   * Record the answer if valid.
3. Stop when the pointers meet or cross.

## Generic Template

```cpp
int left = 0, right = n - 1;

while (left < right)
{
    int current = evaluate(nums[left], nums[right]);

    if (current == target)
    {
        // record answer
        left++;
        right--;
    }
    else if (current < target)
        left++;
    else
        right--;
}
```

## Interview Template

```cpp
int left = 0, right = n - 1;

while (left < right)
{
    // Evaluate nums[left] and nums[right]
    ...

    if (/* result matches target */)
    {
        // Record the answer
        ...

        left++;
        right--;
    }
    else if (/* result too small */)
        left++;
    else
        right--;
}
```

## The 4-Step Rule

```text
1. Start pointers at both ends

2. Compare the values at left and right

3. Move the pointer that needs adjusting
   (or both, if a match is found)

4. Stop when the pointers meet or cross
```

## What Changes Between Problems?

Only these change:

1. **What condition decides which pointer moves?**
   * Sum vs. target
   * Area vs. height
   * Character comparison for a palindrome

2. **What is recorded when a valid answer is found?**
   * A pair
   * A maximum area
   * A count

## Time Complexity

**O(n)** for a single converging pass. (3Sum is O(n²) overall — an O(n) outer loop wrapping an O(n) two-pointer sweep.)

## Space Complexity

**O(1)**

## Common Problems

* Two Sum II (sorted input)
* 3Sum
* Container With Most Water
* Trapping Rain Water
* Valid Palindrome

## Common Mistakes

* Forgetting the array must be sorted (or sortable) for the comparison logic to make sense.
* Not skipping duplicates in 3Sum/4Sum, producing repeated triplets.
* Moving both pointers when only one should move (or vice versa), which can skip valid pairs.
* Off-by-one between `while (left < right)` and `while (left <= right)`.

## Key Points

* Requires sorted (or order-exploitable) data.
* Each comparison eliminates one pointer's current position from further consideration.
* Converges in O(n).

## Key Insight

> **For sorted structures, comparing the two ends lets you discard one end per step instead of checking every pair, turning an O(n²) brute force into O(n).**

## Quick Revision

`left = 0`, `right = n - 1` → move based on comparison → converge until `left >= right`.

---
---

# 2. Sliding Window

## Overview

`right` always expands the window every step; `left` only catches up when the window becomes invalid or must shrink to stay optimal. This is the Two Pointers skeleton underlying every Sliding Window variation.

## When to Use

* Substring/subarray problems with a validity condition
* Longest or shortest substring/subarray under a constraint
* Fixed-size windows (e.g., max sum of `k` consecutive elements)

## Recognition Pattern

Look for:

* Substring / subarray
* Window
* At most / exactly `k`
* Longest / shortest with a condition

## Pointer Movement Logic

```text
right always moves.

left moves only when:

• Window becomes invalid
OR
• Window must shrink
OR
• Window size reaches k (Fixed Window)
```

## Core Idea

Expand with `right` every step; shrink with `left` in a `while` loop only when necessary.

## Algorithm

1. `left = 0`.
2. For each `right` from `0` to `n - 1`:
   * Expand the window using `nums[right]`.
   * While the window is invalid (or has reached size `k`): shrink from `left`.
   * Record the answer.

## Generic Template

```cpp
int left = 0;

for (int right = 0; right < n; right++)
{
    // Expand using nums[right]

    while (/* invalid or needs shrink */)
    {
        // Shrink
        left++;
    }

    // Record answer
}
```

## Interview Template

```cpp
int left = 0;

for (int right = 0; right < n; right++)
{
    // Expand
    ...

    while (/* window invalid, or reached size k */)
    {
        // Shrink
        ...
        left++;
    }

    // Record the answer
    ...
}
```

## The 4-Step Rule

```text
1. Expand right every iteration

2. Check if the window is invalid (or reached size k)

3. Shrink left until valid again
   (or slide by one for fixed windows)

4. Record the answer
```

## What Changes Between Problems?

Only these change:

1. **What makes a window valid or invalid?**
2. **What's recorded?** (max length, min length, count, boolean)

## Time Complexity

**O(n)** amortized — each index is touched by `left` and `right` at most once each.

## Space Complexity

**O(1)** to **O(k)** depending on what's tracked inside the window.

## Common Problems

* Longest Substring Without Repeating Characters
* Minimum Window Substring
* Longest Subarray with Sum ≤ K
* Maximum Sum Subarray of Size K

## Common Mistakes

* Shrinking before the window is actually invalid.
* Using `if` instead of `while` for the shrink condition.
* Forgetting to update the window's tracked state (sum/frequency) when removing the left element.

## Key Points

* `right` always advances; `left` advances only conditionally.
* Every Sliding Window variation (fixed-size, longest, shortest, monotonic deque, etc.) is a refinement of this same `left`/`right` movement rule.

## Key Insight

> **This is really the Two Pointers pattern applied to a window: `right` explores, `left` cleans up.** For the full breakdown of every Sliding Window variation (fixed-size, longest/shortest valid range, monotonic deque, at-most-K, frequency array, and the hybrid patterns), see the dedicated Sliding Window notes — this section is the bridge between the two topics.

## Quick Revision

`right` always moves; `left` moves only to fix or shrink the window.

---
---

# 3. Fast & Slow (Floyd's)

## Overview

Both pointers start at the same point; `slow` moves 1 step and `fast` moves 2 steps per iteration. The speed differential alone — no value comparison — reveals structural properties like cycles or the middle element.

## When to Use

* Finding the middle of a linked list
* Detecting a cycle in a linked list
* Finding the start of a cycle
* Determining if a number is "happy" (treating the digit-square-sum sequence as an implicit linked list)

## Recognition Pattern

Look for:

* Linked list
* Cycle / loop detection
* Middle of the list
* Happy Number

## Pointer Movement Logic

```text
slow += 1

fast += 2

Stop when:

fast == nullptr
or

fast->next == nullptr
```

## Core Idea

No comparison is needed — the differing speeds alone produce the useful structural property: a meeting point implies a cycle; `fast` reaching the end implies no cycle; `slow`'s position when `fast` finishes is the middle.

## Algorithm

1. `slow = head`, `fast = head`.
2. While `fast` and `fast->next` are non-null: `slow = slow->next`; `fast = fast->next->next`.
3. Depending on the goal: `slow` is the middle, or `slow == fast` signals a cycle — then reset one pointer to `head` and advance both by 1 until they meet again to find the cycle's start.

## Generic Template

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
        // cycle detected
        break;
    }
}
```

## Interview Template

```cpp
ListNode* slow = head;
ListNode* fast = head;
bool hasCycle = false;

while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
        hasCycle = true;
        break;
    }
}

// To find the cycle's start (only if hasCycle):
ListNode* ptr = head;
while (hasCycle && ptr != slow)
{
    ptr = ptr->next;
    slow = slow->next;
}
// ptr (== slow) is the start of the cycle
```

## The 4-Step Rule

```text
1. Start both pointers at the same node

2. Advance slow by 1, fast by 2

3. Stop when fast reaches the end (no cycle)
   or fast meets slow (cycle)

4. Use the meeting point / final position for the answer
```

## What Changes Between Problems?

Only these change:

1. **What the meeting/ending condition means** — middle vs. cycle vs. cycle-start.
2. **Whether a reset-and-replay step is needed** (only for finding the cycle's start).

## Time Complexity

**O(n)**

## Space Complexity

**O(1)**

## Common Problems

* Middle of the Linked List
* Linked List Cycle
* Linked List Cycle II
* Happy Number

## Common Mistakes

* Checking only `fast` instead of `fast && fast->next`, which causes a null-pointer dereference.
* Mishandling the "middle" result for even-length lists — `slow` lands on the second middle by this convention, which may or may not match what the problem expects.
* Forgetting the reset-to-head step (advance both by 1) when finding the cycle's start node.

## Key Points

* No value comparison is needed — only relative speed matters.
* Meeting implies a cycle; `fast` hitting null implies no cycle.

## Key Insight

> **Two pointers moving at different fixed speeds will always meet inside a cycle and will always diverge to the exact middle otherwise — the speed difference alone encodes the structure you need.**

## Quick Revision

`slow += 1`, `fast += 2` each step; `fast` hits null → no cycle; `slow == fast` → cycle found.

---
---

# 4. Write-Read

## Overview

`slow` marks the next valid write position; `fast` scans ahead reading candidates. When `fast` finds a valid element, it's written at `slow`, and `slow` advances.

## When to Use

* In-place array modification
* Removing duplicates
* Removing a specific value
* Moving zeroes
* Partitioning an array by a predicate

## Recognition Pattern

Look for:

* In place / without extra space
* Remove duplicates
* Move zeroes
* Remove element
* Partition array

## Pointer Movement Logic

```text
fast always scans.

If nums[fast] should be kept:

nums[slow] = nums[fast]

slow++

fast++
```

## Core Idea

`fast` explores every element; `slow` only advances (and writes) when the current element passes the "keep" condition.

## Algorithm

1. `slow = 0`.
2. For each `fast` from `0` to `n - 1`:
   * If `nums[fast]` satisfies the keep condition: `nums[slow] = nums[fast]`; `slow++`.
3. `slow` is the new logical length.

## Generic Template

```cpp
int slow = 0;

for (int fast = 0; fast < n; fast++)
{
    if (/* nums[fast] should be kept */)
    {
        nums[slow] = nums[fast];
        slow++;
    }
}

// slow = new length
```

## Interview Template

```cpp
int slow = 0;

for (int fast = 0; fast < n; fast++)
{
    if (/* keep condition on nums[fast] */)
    {
        // Overwrite, or swap(nums[slow], nums[fast])
        // depending on whether order must be fully preserved
        nums[slow] = nums[fast];
        slow++;
    }
}

// slow = new length
```

## The 4-Step Rule

```text
1. fast scans every element

2. Check the keep condition

3. If kept, write it at slow and advance slow

4. Always advance fast
```

## What Changes Between Problems?

Only these change:

1. **What the "keep" condition is** — non-duplicate, non-zero, not-equal-to-value, or a custom predicate.
2. **Whether to overwrite or swap** the element.

## Time Complexity

**O(n)**

## Space Complexity

**O(1)**

## Common Problems

* Remove Duplicates from Sorted Array
* Move Zeroes
* Remove Element
* Partition array by a predicate

## Common Mistakes

* Comparing against the wrong previous element when de-duplicating.
* Overwriting instead of swapping when the problem requires preserving all elements (Move Zeroes needs a swap, not a plain overwrite, so zeroes end up correctly at the tail).
* Off-by-one when returning `slow` as the new length vs. the last valid index.

## Key Points

* `fast` always advances; `slow` advances conditionally.
* `slow`'s final value is the new logical length of the array.

## Key Insight

> **By decoupling "reading" from "writing" with two pointers moving at different rates, you can compact an array in place in a single O(n) pass without extra space.**

## Quick Revision

`fast` scans all elements; `slow` only advances/writes on a "keep" condition; final `slow` = new length.

---
---

# 5. Merge Pointers (Two Separate Structures)

## Overview

`i` indexes structure A, `j` indexes structure B; advance whichever pointer points to the smaller (or "behind") element, to merge or compare two sorted structures.

## When to Use

* Merging two sorted arrays or linked lists
* Intersection of two sorted arrays
* Merge Sort's merge step

## Recognition Pattern

Look for:

* Merge two sorted
* Intersection of sorted arrays
* Merge step
* Two sorted lists / arrays

## Pointer Movement Logic

```text
Compare A[i] and B[j].

Smaller value wins.

Move only that pointer.

If equal:

Process answer.

Move both.
```

## Core Idea

Since both structures are already sorted, the smaller of the two current elements is guaranteed to be the next element in merged order.

## Algorithm

1. `i = 0`, `j = 0`.
2. While `i < A.size()` and `j < B.size()`:
   * If `A[i] < B[j]`: take `A[i]`, `i++`.
   * Else if `A[i] > B[j]`: take `B[j]`, `j++`.
   * Else: process the equal case, `i++`, `j++`.
3. Append any remaining elements from A or B.

## Generic Template

```cpp
int i = 0, j = 0;

while (i < A.size() && j < B.size())
{
    if (A[i] < B[j])
    {
        // take A[i]
        i++;
    }
    else if (A[i] > B[j])
    {
        // take B[j]
        j++;
    }
    else
    {
        // equal: process, then advance both
        i++;
        j++;
    }
}

// Append remaining elements of A or B
```

## Interview Template

```cpp
int i = 0, j = 0;
vector<int> result;

while (i < A.size() && j < B.size())
{
    if (A[i] <= B[j])
        result.push_back(A[i++]);
    else
        result.push_back(B[j++]);
}

while (i < A.size()) result.push_back(A[i++]);
while (j < B.size()) result.push_back(B[j++]);
```

## The 4-Step Rule

```text
1. Compare A[i] and B[j]

2. Advance the pointer with the smaller
   (or "behind") value

3. If equal, process and advance both

4. Append leftovers once one structure is exhausted
```

## What Changes Between Problems?

Only these change:

1. **What "process" means when values match** — intersection records once, merge may still take one or both copies depending on duplicates.
2. **Whether leftovers need to be appended** once one structure is exhausted.

## Time Complexity

**O(n + m)**

## Space Complexity

**O(1)** for in-place merges where possible; **O(n + m)** if building a new merged output.

## Common Problems

* Merge Two Sorted Arrays
* Merge Two Sorted Lists
* Intersection of Two Arrays II
* Merge Sort's merge step

## Common Mistakes

* Forgetting to append the remaining elements once one array is exhausted.
* Mishandling duplicates in intersection problems (the count should be capped by the minimum frequency across both arrays).
* Merging in-place from the front instead of the back when the destination array has trailing free space (LeetCode's Merge Sorted Array requires merging back-to-front to avoid overwriting unread elements).

## Key Points

* Only works because both structures are already sorted.
* The "behind" pointer is always the one that advances.

## Key Insight

> **When two structures are already sorted, you never need to look back — the smaller current element is always the correct next element, giving an O(n + m) merge without extra comparisons.**

## Quick Revision

Compare `A[i]` vs `B[j]`, advance the smaller, append leftovers at the end.

---
---

# 6. Dutch National Flag (Three-Pointer Partition)

## Overview

`low`, `mid`, and `high` partition an array into three groups in a single pass. `mid` scans, `low` marks the boundary for the "small" group, and `high` marks the boundary for the "large" group.

## When to Use

* Sorting an array of three distinct values in place (e.g., 0s, 1s, 2s)
* 3-way quicksort partitioning
* Partitioning around a pivot value (less than / equal to / greater than)

## Recognition Pattern

Look for:

* Sort Colors
* Three distinct values
* Partition around a pivot
* 0s, 1s, 2s
* 3-way partition

## Pointer Movement Logic

```text
nums[mid] == 0

Swap(low, mid)

low++
mid++

------------------

nums[mid] == 1

mid++

------------------

nums[mid] == 2

Swap(mid, high)

high--

Do NOT move mid.
```

## Core Idea

Maintain three regions — `[0, low)` = small group, `[low, mid)` = middle group, `(high, n-1]` = large group — and grow them as `mid` scans through the unknown region `[mid, high]`.

## Algorithm

1. `low = 0`, `mid = 0`, `high = n - 1`.
2. While `mid <= high`:
   * If `nums[mid] == 0`: swap with `low`; advance both `low` and `mid`.
   * Else if `nums[mid] == 1`: advance `mid` only.
   * Else: swap with `high`; decrement `high` (do not advance `mid`).

## Generic Template

```cpp
int low = 0, mid = 0, high = n - 1;

while (mid <= high)
{
    if (nums[mid] == 0)
    {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
    }
    else if (nums[mid] == 1)
    {
        mid++;
    }
    else
    {
        swap(nums[mid], nums[high]);
        high--;
        // mid stays put — recheck the swapped-in value
    }
}
```

## Interview Template

```cpp
int low = 0, mid = 0, high = n - 1;

while (mid <= high)
{
    if (nums[mid] == 0)
    {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
    }
    else if (nums[mid] == 1)
    {
        mid++;
    }
    else // nums[mid] == 2
    {
        swap(nums[mid], nums[high]);
        high--;
        // Do NOT advance mid here — the swapped-in
        // value from high hasn't been checked yet.
    }
}
```

## The 4-Step Rule

```text
1. mid scans the unknown region

2. "0" → swap with low, advance both low and mid

3. "1" → just advance mid

4. "2" → swap with high, decrement high,
         keep mid in place
```

## What Changes Between Problems?

Only these change:

1. **What the three groups represent** — 0/1/2, or elements less-than / equal-to / greater-than a pivot.
2. **The exact partition values** used for comparison.

## Time Complexity

**O(n)** — a single pass.

## Space Complexity

**O(1)**

## Common Problems

* Sort Colors
* 3-way Quicksort partitioning
* Partition Array by a pivot value

## Common Mistakes

* Advancing `mid` right after swapping with `high` — the swapped-in value hasn't been checked yet, and skipping it can leave the array unsorted.
* Confusing which pointer marks which boundary (`low` = end of the "small" region, `high` = start of the "large" region).
* Trying to stretch this pattern to more than three groups, where it doesn't generalize directly.

## Key Points

* Single pass, three-way partition.
* The trickiest rule: a swap with `high` must NOT advance `mid`.

## Key Insight

> **Three pointers can partition an array into three regions in one linear pass — the only subtlety is that a swap with `high` requires rechecking the swapped-in element, so `mid` stays put.**

## Quick Revision

`low` / `mid` / `high`; `0` → swap-low + advance both; `1` → advance `mid`; `2` → swap-high, decrement `high`, don't move `mid`.

---
---

# 7. Two Arrays (Non-Merge)

## Overview

A similar setup to Merge Pointers, but used for comparison/matching between two sequences rather than producing a merged output — e.g., checking subsequences or comparing strings with special characters.

## When to Use

* Checking if one string/sequence is a subsequence of another
* Comparing two strings that contain backspace characters

## Recognition Pattern

Look for:

* Is Subsequence
* Backspace Compare
* Matching characters across two strings in order
* One sequence embedded in another

## Pointer Movement Logic

```text
If characters match:

i++
j++

Else:

Advance only the larger array pointer.
```

## Core Idea

One pointer (on the "target"/longer structure) advances every step; the other (on the "pattern"/shorter structure) advances only on a match.

## Algorithm

1. `i = 0` (pattern), `j = 0` (target).
2. While `i < pattern.size()` and `j < target.size()`:
   * If `pattern[i] == target[j]`: `i++`.
   * `j++` (always).
3. Return whether `i` reached the end of the pattern.

## Generic Template

```cpp
int i = 0, j = 0;

while (i < s.size() && j < t.size())
{
    if (s[i] == t[j])
        i++;

    j++;
}

return i == s.size();
```

## Interview Template

```cpp
int i = 0, j = 0;

while (i < s.size() && j < t.size())
{
    if (s[i] == t[j])
        i++;

    j++;
}

return i == s.size();

// For Backspace Compare: walk both strings from
// the END instead, skipping characters marked for
// deletion (e.g., '#') before every comparison.
```

## The 4-Step Rule

```text
1. j (target/longer) always advances

2. i (pattern/shorter) advances only on a match

3. Continue until one string is exhausted

4. Check whether i reached the end of the pattern
```

## What Changes Between Problems?

Only these change:

1. **Direction of traversal** — front-to-back for subsequence checks, back-to-front for backspace compare.
2. **What counts as "advance"/"skip"** — special handling for characters like `#` in backspace compare.

## Time Complexity

**O(n + m)**

## Space Complexity

**O(1)**

## Common Problems

* Is Subsequence
* Backspace String Compare

## Common Mistakes

* Advancing both pointers on a mismatch instead of only the target pointer.
* Mishandling trailing backspace characters when comparing from the end.
* Off-by-one when checking whether the full pattern matched (`i == s.size()` vs. `i == s.size() - 1`).

## Key Points

* Only one pointer conditionally advances; the other always advances.
* Doesn't require sorted input, unlike most other Two Pointers variations.

## Key Insight

> **When checking order-preserving matches between two sequences, you don't need backtracking — advancing the longer sequence unconditionally and the shorter one only on a match is enough to verify a subsequence in linear time.**

## Quick Revision

Target pointer always advances; pattern pointer advances only on a match; check if the pattern was fully consumed.

---
---

# Master Decision Tree

```text
Does the array have to be sorted?
        │
        ├── Yes
        │     │
        │     ├── Looking for pair?
        │     │       → Opposite Direction
        │     │
        │     ├── Merge?
        │     │       → Merge Pointers
        │     │
        │     └── Subsequence?
        │             → Two Arrays
        │
        └── No
              │
              ├── Linked List?
              │       → Fast & Slow
              │
              ├── Modify array in-place?
              │       → Write-Read
              │
              ├── Three groups?
              │       → Dutch National Flag
              │
              └── Window/Subarray?
                      → Sliding Window
```

---
---

# One-Page Revision Sheet

| Pattern              | Pointer Setup          | Main Idea                                    | Time      | Space      |
| ---------------------- | ------------------------- | ------------------------------------------------ | ----------- | ------------ |
| Opposite Direction    | `left`, `right`          | Move inward based on comparison                  | O(n)        | O(1)         |
| Sliding Window        | `left`, `right`          | Expand and shrink a window                       | O(n)        | O(1)/O(k)    |
| Fast & Slow           | `slow`, `fast`           | Different pointer speeds                        | O(n)        | O(1)         |
| Write-Read            | `slow`, `fast`           | Read with one pointer, write with the other      | O(n)        | O(1)         |
| Merge                 | `i`, `j`                 | Compare two sorted structures                    | O(n + m)    | O(1)*        |
| Dutch National Flag   | `low`, `mid`, `high`     | Three-way partition                              | O(n)        | O(1)         |
| Two Arrays            | `i`, `j`                 | Match elements across structures                 | O(n + m)    | O(1)         |

\* **O(1)** auxiliary space for in-place merges when applicable; **O(n + m)** output space if creating a separate merged array.

---
