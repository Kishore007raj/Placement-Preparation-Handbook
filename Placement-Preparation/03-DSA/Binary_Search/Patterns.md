# Patterns

## 1. Standard Binary Search

- Recognition: sorted array and direct match
- Use when: need to find a target element
- Avoid when: data is not sorted

## 2. Lower Bound

- Recognition: first position where condition becomes true
- Use when: finding first occurrence or insertion point
- Common problems: search insert position

## 3. Upper Bound

- Recognition: last position where condition is true
- Use when: counting occurrences or finding the right boundary

## 4. Search on Answer

- Recognition: answer is monotonic and can be checked in $O(1)$ or $O(log n)$
- Use when: minimum/maximum feasible value is required
- Common problems: capacity problems and minimum time
