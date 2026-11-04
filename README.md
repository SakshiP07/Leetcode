# LeetCode Solutions

A collection of LeetCode problem solutions written in C++. Each solution is a
standalone source file.

## LeetCode 307: Range Sum Query - Mutable

[`Leetcode307.cpp`](./Leetcode307.cpp) implements a mutable array with:

- `update(index, value)` to replace an array element.
- `sumRange(left, right)` to return the inclusive sum between two indices.

The solution uses a **Fenwick tree (Binary Indexed Tree)**. Each update stores
the difference from the previous value in the tree, and prefix sums are
combined to calculate a range sum.

### Complexity

| Operation | Time |
|---|---:|
| Construction | `O(n log n)` |
| Update | `O(log n)` |
| Range sum | `O(log n)` |
| Storage | `O(n)` |

### Build and run

Requires a C++ compiler with C++11 or newer support:

```sh
g++ -std=c++11 -Wall -Wextra -pedantic Leetcode307.cpp -o Leetcode307
./Leetcode307
```

The included example prints:

```text
9
8
```
