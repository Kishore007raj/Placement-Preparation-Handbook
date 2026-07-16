# Theory

## Definition

Binary Search is a searching algorithm that works on sorted data by repeatedly dividing the search interval into two halves.

## Why it exists

A linear scan takes $O(n)$ time. Binary Search reduces the search space by half each step, achieving $O(log n)$ time.

## Intuition

If the target is present, one half of the array can never contain it, so it is discarded.

## Real-world analogy

Think of looking for a word in a dictionary. Instead of reading every page, you open the middle and decide whether the word lies before or after that point.

## Working principle

- Maintain a low and high index.
- Compute mid = low + (high - low) / 2.
- Compare the middle element with the target.
- Move low or high accordingly.

## Advantages

- Very fast for large sorted datasets.
- Simple to implement.
- Useful for many interview problems.

## Disadvantages

- Only works on sorted data.
- Requires careful handling of boundaries.

## Applications

- Searching in sorted arrays
- Finding boundaries in arrays
- Solving monotonic decision problems

## Edge cases

- Empty array
- Single element
- Target at the first or last position
- Duplicate values

## Interview notes

Binary search is often used as a template for problems where the answer space is monotonic.
