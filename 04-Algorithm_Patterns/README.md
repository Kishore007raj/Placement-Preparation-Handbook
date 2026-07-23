# 🧩 Algorithm Patterns

Algorithm patterns are reusable problem-solving techniques that appear across coding interviews, competitive programming, and real-world software engineering.

Instead of memorizing solutions to individual problems, learn to recognize the underlying pattern. Once you identify the pattern, the solution often becomes much easier to design.

This section is organized from **Foundation → Intermediate → Advanced**, so each topic builds naturally on the previous one.

---

# 🎯 Learning Objectives

By completing this section, you will be able to:

- Identify the underlying pattern in a problem.
- Choose the most appropriate algorithm.
- Transform brute-force solutions into optimized ones.
- Analyze time and space complexity.
- Apply the same pattern to new, unseen problems.
- Build strong interview problem-solving intuition.

---

# 📂 Repository Structure

```text
04-Algorithm-Patterns
│
├── 1-Foundation
│   ├── 01-Linear_Traversal
│   ├── 02-Simulation
│   ├── 03-Frequency_Counting
│   ├── 04-Hashing
│   ├── 05-Sorting
│   ├── 06-Prefix_Sum
│   ├── 07-Prefix_State
│   ├── 08-Difference_Array
│   ├── 09-Two_Pointers
│   ├── 10-Sliding_Window
│   ├── 11-Binary_Search
│   ├── 12-Binary_Search_On_Answer
│   ├── 13-Matrix_Traversal
│   ├── 14-Matrix_Prefix_Sum
│   ├── 15-Floyd_Cycle_Detection
│   └── 16-Recursion
│
├── 2-Intermediate
│   ├── 01-Top_K_Elements
│   ├── 02-Heap
│   ├── 03-Monotonic_Stack
│   ├── 04-Monotonic_Queue
│   ├── 05-Merge_Intervals
│   ├── 06-Cyclic_Sort
│   ├── 07-Greedy
│   ├── 08-BFS
│   ├── 09-DFS
│   ├── 10-Backtracking
│   ├── 11-State_Machine_DP
│   ├── 12-Kadane_Algorithm
│   └── 13-Bitmasking
│
└── 3-Advanced
    ├── 01-Coordinate_Compression
    ├── 02-Sweep_Line
    ├── 03-MO_Algorithm
    ├── 04-Rolling_Hash
    ├── 05-KMP
    ├── 06-Z_Algorithm
    ├── 07-Manachers_Algorithm
    ├── 08-Aho_Corasick
    ├── 09-Digit_DP
    └── 10-Tree_DP
```

---

# 📚 Foundation

These are the essential patterns every programmer should know before moving on to more advanced techniques.

| Pattern | Purpose |
|----------|---------|
| Linear Traversal | Process arrays and strings sequentially. |
| Simulation | Directly model the problem statement. |
| Frequency Counting | Count occurrences using arrays or hash maps. |
| Hashing | Perform fast lookups and detect duplicates. |
| Sorting | Reorder data to simplify problem solving. |
| Prefix Sum | Answer range sum queries efficiently. |
| Prefix State | Maintain cumulative information while traversing. |
| Difference Array | Perform efficient range updates. |
| Two Pointers | Solve problems on sorted or linear data efficiently. |
| Sliding Window | Process contiguous subarrays and substrings. |
| Binary Search | Search efficiently in sorted or monotonic data. |
| Binary Search on Answer | Search the solution space instead of the input. |
| Matrix Traversal | Traverse and manipulate 2D grids. |
| Matrix Prefix Sum | Answer submatrix sum queries in constant time. |
| Floyd Cycle Detection | Detect cycles using slow and fast pointers. |
| Recursion | Solve problems by reducing them into smaller subproblems. |

---

# 🚀 Intermediate

These patterns combine multiple concepts and appear frequently in coding interviews.

| Pattern | Purpose |
|----------|---------|
| Top K Elements | Retrieve the largest or smallest **K** elements efficiently. |
| Heap | Maintain dynamic minimum or maximum elements. |
| Monotonic Stack | Solve next greater/smaller element problems. |
| Monotonic Queue | Optimize sliding window problems. |
| Merge Intervals | Merge overlapping intervals. |
| Cyclic Sort | Place numbers into their correct positions efficiently. |
| Greedy | Make locally optimal decisions that lead to a global solution. |
| BFS | Traverse graphs and trees level by level. |
| DFS | Explore graphs and trees recursively or iteratively. |
| Backtracking | Explore all valid possibilities with pruning. |
| State Machine DP | Model dynamic programming through state transitions. |
| Kadane's Algorithm | Find the maximum subarray in linear time. |
| Bitmasking | Represent subsets and states using binary operations. |

---

# 🏆 Advanced

These patterns are common in competitive programming and advanced technical interviews.

| Pattern | Purpose |
|----------|---------|
| Coordinate Compression | Map large values into compact indices. |
| Sweep Line | Process events in sorted order. |
| MO's Algorithm | Answer offline range queries efficiently. |
| Rolling Hash | Compute substring hashes in constant time. |
| KMP | Perform linear-time pattern matching. |
| Z Algorithm | Compute prefix matches efficiently. |
| Manacher's Algorithm | Find the longest palindromic substring in linear time. |
| Aho-Corasick | Match multiple patterns simultaneously. |
| Digit DP | Solve digit-constrained counting problems. |
| Tree DP | Apply dynamic programming on trees. |

---

# 📖 What You'll Find in Each Pattern

Every pattern directory includes:

- 📌 Problem intuition
- 🔍 Pattern recognition guide
- ✅ When to use the pattern
- ❌ Common mistakes
- 🧠 Step-by-step explanation
- ⚡ Time and space complexity
- 🧩 Reusable template implementation
- 💼 Interview problems
- 📝 Practice problems
- 🔗 Related patterns

---

# 🗺️ Learning Roadmap

```text
Level 1  → Foundation
Level 2  → Intermediate
Level 3  → Advanced
Level 4  → Interview Practice
Level 5  → Competitive Programming
```

Each level builds on the previous one. Master the fundamentals before moving to advanced techniques.

---

# 📚 Prerequisites

Before starting this section, you should be comfortable with:

- Arrays
- Strings
- Hash Tables
- Linked Lists
- Stacks
- Queues
- Heaps
- Trees
- Graphs
- Time & Space Complexity

---

# 💡 How to Study

For every pattern:

1. Learn the intuition behind the technique.
2. Understand when the pattern applies.
3. Memorize the generic template-not individual solutions.
4. Solve easy problems until the pattern becomes recognizable.
5. Progress to medium and hard variations.
6. Revisit the pattern after a few days to reinforce recognition.

The goal is to recognize patterns automatically when solving new problems.

---

# ⭐ End Goal

By the end of this section, you should be able to look at a new problem and quickly answer:

- **What pattern is this?**
- **Why does this pattern fit?**
- **What is the optimal approach?**
- **What are the time and space complexities?**

Mastering these classical patterns provides the foundation for advanced algorithmic patterns, efficient problem solving, and technical interviews.