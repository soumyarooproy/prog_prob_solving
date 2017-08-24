# Binary Search Problems

## Problems on linear (or 1D) sequences
These problems are usually worded as:

Given a linear sequence of elements with **_an ordering_** and a key, determine
* if the key exists in the sequence; return `true` if it exists, `false` otherwise (`binary_search()` in C++ Standard Library)
* the index in the sequence where **_the_** key exists, if it exists, else return `-1` or `n` (since valid indices are in the range `[0, n - 1]`). This is applicable only when the sequence has all distinct keys. In a sequence with duplicate keys, determine
  * the smallest index (`lower_bound()` in C++ Standard Library)
  * the largest index (`upper_bound()` in C++ Standard Library, although it returns the index past the largest index)
  * the range of indices (`equal_range()` in C++ Standard Library)
* the index in the sequence where key would have to be inserted to ensure that the resulting sequence is also sorted

The ordering sequence may be among the following:
* **_Sorted sequence_** - monotonically increasing sequence
* **_Sorted but rotated sequence_** - monotonically increasing sequence rotated (left or right) by `k`, `k` modulo `n` != `0`, positions
* **_Bitonic sequence_** - an increasing contiguous subsequence followed by a contiguous decreasing subsequence
* **_Abs-sorted sequence_** - the absolute values of the elements are in sorted order

In the non-monotonically ordered sequences, the minimum/maximum keys may also be found in O(lg n) time.

## Summary
**Add info when the sequence has duplicates**

Sequence Type | Property | Key Insight | Performance | Difficulty
--- | --- | --- | --- | ---
Sorted sequence | `a[i] <= a[i + 1], 0 <= i <= (n - 2)` | NA | O(lg n) | Easy
Sorted but rotated array |   |   | O(lg n) | Medium
Bitonic sequence | `a[i] <= a[i + 1], 0 <= i < j and a[i] >= a[i + 1], j <= i < n - 2, 0 < j < n - 1`  |   | O(lg n) | Medium
Abs-sorted sequence | `\|a[i]\| <= \|a[i + 1]\|, 0 <= i <= (n - 2)`  | All the -ve keys are in sorted order and so are all the +ve keys | O(lg n) | Hard

## Problems
* [Search Insertion Position](https://leetcode.com/problems/search-insert-position)
* [Search for Range of Indices](https://leetcode.com/problems/search-for-a-range)
* [Search in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array)
* [Search in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
* [Find Minimum in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
* [Find Minimum in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)

## Problems on 2D arrays
TBD
