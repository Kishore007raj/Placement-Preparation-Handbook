# 01 - Arrays & Hashing — Theory

## Arrays

### What is an Array?
A contiguous block of memory storing elements of the same type, accessed via a zero-based index in C++. Because memory is contiguous, `arr[i]` is computed as `base_address + i * sizeof(type)` — this is why **random access is O(1)**.

### Key Properties
| Operation | Time Complexity |
|---|---|
| Access by index | O(1) |
| Search (unsorted) | O(n) |
| Search (sorted, binary search) | O(log n) |
| Insert/Delete at end | O(1) amortized (`std::vector`) |
| Insert/Delete at beginning/middle | O(n) — shifting required |

### `std::vector` vs raw arrays
- `vector<int> v(n)` — dynamic size, resizes automatically (doubles capacity when full → amortized O(1) push_back).
- Raw arrays (`int arr[n]`) — fixed size, no bounds checking, faster in tight loops but less flexible.
- Prefer `vector` in interviews unless the problem explicitly requires fixed-size arrays.

### Common Array Techniques
1. **In-place modification** — reuse the array itself as extra storage (e.g., marking visited indices negative) to hit O(1) space.
2. **Sorting first** — many array problems become easier (two pointers, binary search) once sorted, at the cost of O(n log n).
3. **Index as a hash** — when values are bounded by array length, use indices to encode presence/absence (cyclic sort, negative marking).

---

## Hashing

### What is Hashing?
A technique to map data (keys) to array indices via a **hash function**, enabling average O(1) insert, delete, and lookup — much faster than array/list search (O(n)).

### `unordered_map` / `unordered_set` in C++
- Backed by a hash table (buckets + linked lists or open addressing internally).
- **Average case:** O(1) for insert/find/erase.
- **Worst case:** O(n) if many keys collide into the same bucket (rare with good hash functions, but possible with adversarial input or poor custom hash).
- Not ordered — iteration order is unspecified. Use `map`/`set` (Red-Black tree, O(log n) operations) when order matters.

### Collision Handling (conceptual)
- **Chaining:** each bucket holds a linked list of entries that hash to the same index.
- **Open addressing:** on collision, probe for the next open slot (linear/quadratic probing, double hashing).
- C++'s `unordered_map` uses chaining internally.

### Choosing Between Data Structures
| Need | Structure |
|---|---|
| Fast lookup, don't care about order | `unordered_map` / `unordered_set` |
| Fast lookup + sorted order | `map` / `set` |
| Small fixed domain (e.g., 26 letters) | Plain array as a "hash table" (faster, no hashing overhead) |
| Count frequencies | `unordered_map<T,int>` or array |
| Track insertion order + O(1) lookup | `unordered_map` + separate list/vector |

### Custom Hashing
For `pair<int,int>` or custom structs as keys in `unordered_map`, you must supply a custom hash function since STL doesn't provide one by default:
```cpp
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};
unordered_map<pair<int,int>, int, pair_hash> mp;
```

### Why Hashing Matters for Arrays
Most "array" interview problems that look like they need O(n²) brute force can drop to O(n) by trading space for time using a hash map — this is the single most important idea in this topic. The recurring move:
> "Have I seen this value/complement/prefix-sum before?" → store what you've seen in a hash map as you iterate once.

---

## Mental Model Summary
- **Array** = fast random access, slow insert/delete in the middle, foundation for two pointers / sliding window / prefix sum / sorting-based tricks.
- **Hashing** = fast existence/frequency checks, foundation for turning O(n²) pair/subarray problems into O(n).
- Combining both (e.g., prefix sum + hashmap, or sorted array + two pointers) is where most "medium" interview problems live.