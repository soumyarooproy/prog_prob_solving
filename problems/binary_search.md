# Binary Search Problems

## Problems on linear (or 1D) sequences
The simplest variant of this family of problem is:

Given a linear sequence of **_distinct_** elements with **_an ordering_** and a key, determine if the key exists in the sequence; return `true` if it exists, `false` otherwise.

The ordering sequence may be among the following:
* **_Sorted sequence_** - monotonically increasing sequence
* **_Cyclically Sorted sequence_** - monotonically increasing sequence rotated (left or right) by `k`, `k` modulo `n` != `0`, positions
* **_Bitonic sequence_** - an increasing contiguous subsequence followed by a contiguous decreasing subsequence
* **_Abs-sorted sequence_** - the absolute values of the elements are in sorted order

Mild variants of this basic problem are ones where the goal is to determine:
* the index where the key exists
* the index of the smallest value greater than the key - this is also the **_successor_** of the key
* the index of the largest value smaller than the key - this is also the **_predecessor_** of the key
* the index in the sequence where key would have to be inserted to ensure that the resulting sequence is also sorted

In all these problems above, return -1 or n if a valid index does not exist since valid indices are in the range [0, n - 1].

When the sequence has duplicates, a few other variants can be added to the ones above:
* Find the smallest index (or the first occurence) of the key in the sequence
* Find the largest index (or the last occurence) of the key in the sequence
* Find the range of indices, which is just a tuple of the last two indices

In the non-monotonically ordered sequences above, the minimum/maximum keys may also be found in O(lg n) time if all the elements are distict.

### C++ Standard library
* [`binary_search()`](http://en.cppreference.com/w/cpp/algorithm/binary_search)
* [`lower_bound()`](http://en.cppreference.com/w/cpp/algorithm/lower_bound)
* [`upper_bound()`](http://en.cppreference.com/w/cpp/algorithm/upper_bound)
* [`equal_range()`](http://en.cppreference.com/w/cpp/algorithm/equal_range)

## Summary
**Add info when the sequence has duplicates**

Sequence Type | Property | Key Insight | Performance | Difficulty
--- | --- | --- | --- | ---
Sorted sequence | `a[i] <= a[i + 1], 0 <= i <= (n - 2)` | NA | O(lg n) | Easy
Sorted but rotated array |   |   | O(lg n) | Medium
Bitonic sequence | `a[i] <= a[i + 1], 0 <= i < j and a[i] >= a[i + 1], j <= i < n - 2, 0 < j < n - 1`  |   | O(lg n) | Medium
Abs-sorted sequence | `\|a[i]\| <= \|a[i + 1]\|, 0 <= i <= (n - 2)`  | All the -ve keys are in sorted order and so are all the +ve keys | O(lg n) | Hard

### Other problems
## Problems
* [Search Insertion Position](https://leetcode.com/problems/search-insert-position)
* [Search for Range of Indices](https://leetcode.com/problems/search-for-a-range)
* [Search in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array)
* [Search in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
* [Find Minimum in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
* [Find Minimum in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)

## Problems on 2D arrays
TBD
