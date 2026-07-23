# Two Pointers - Algorithm Pattern Deep Dive

A focused, ace-the-interview breakdown of the **Two Pointers** pattern. Language: **C++**.

## Folder Contents

| File | Purpose | Read When |
|---|---|---|
| `When_To_Use.md` | Signals that tell you Two Pointers is the right tool | First - decide if this pattern applies |
| `Recognition.md` | How to recognize the *exact variation* needed from problem phrasing | Right after deciding Two Pointers applies |
| `Variations.md` | All flavors of Two Pointers (opposite-direction, same-direction, fast-slow, three-pointer) | Core study material |
| `Template.cpp` | Ready-to-paste C++ templates for every variation | While practicing / during OA |
| `Examples.md` | Fully worked examples with step-by-step reasoning | To see the pattern applied end-to-end |
| `Complexity.md` | Time & space complexity for every variation | When comparing approaches |
| `Complexity_Mistakes.md` | Common complexity miscalculations and why they happen | Before an interview - avoid these traps |
| `Practice_Problems.md` | Curated problem list by difficulty, with which variation each uses | For structured practice |

## What Is the Two Pointers Pattern?
Two Pointers is a technique where you maintain two (occasionally three) index variables that traverse a data structure - typically an array, string, or linked list - according to some rule, instead of using nested loops. It converts many O(n²) brute-force solutions into O(n) by exploiting a monotonic property (usually: sorted order, or a window that only grows/shrinks in one direction).

## Suggested Study Order
1. `When_To_Use.md` → `Recognition.md` - build the intuition for *spotting* this pattern fast.
2. `Variations.md` - learn all the flavors, not just the classic "opposite ends" version.
3. `Template.cpp` - type out every template by hand until automatic.
4. `Examples.md` - walk through fully worked problems to see the reasoning, not just the code.
5. `Complexity.md` + `Complexity_Mistakes.md` - make sure you can defend your complexity claims out loud.
6. `Practice_Problems.md` - grind the list, two passes each (brute force, then optimal).

## Quick Definition Table
| Variation | Pointer Movement | Typical Use |
|---|---|---|
| Opposite Direction | `left` starts at 0, `right` starts at n-1, move inward | sorted array pair sum, palindrome check, container with most water |
| Same Direction (Fast/Slow, different speeds) | both start at 0, move forward at different rates | cycle detection, middle of linked list, remove duplicates |
| Same Direction (Sliding Window) | both start at 0, `right` leads, `left` follows/catches up | subarray/substring problems with a window condition |
| Three Pointers | one fixed/moving anchor + two-pointer sweep on the rest | 3Sum, Dutch National Flag |

---