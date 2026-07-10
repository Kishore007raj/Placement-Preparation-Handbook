# Cheatsheet

## Key Formula

- Midpoint: `mid = low + (high - low) / 2`

## Time Complexity

- Best: $O(1)$
- Average: $O(log n)$
- Worst: $O(log n)$

## Space Complexity

- Iterative: $O(1)$
- Recursive: $O(log n)$

## Common Mistakes

- Using binary search on unsorted data
- Incorrect midpoint calculation
- Forgetting to update `low` or `high`
- Infinite loops from wrong bounds

## Recognition Tips

- The array is sorted
- The problem asks for first/last occurrence
- The answer space is monotonic
