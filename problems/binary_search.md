# Binary Search Problems

## Problems on linear (or 1D) sequences

### Basic Problem
The simplest variant in this problem family is:

Given a linear sequence of **_distinct_** elements with **_an ordering_** and a key, determine if the key exists in the sequence; return `true` if it exists, `false` otherwise.

### Types of Sequences
The sequence ordering may be among the following:
* **_Sorted sequence_** - monotonically increasing sequence
  * E.g. `<1,2,3,4,5>`
* **_Absolute Sorted sequence_** - the absolute values of the elements are in monotonically increasing order
  * E.g. `<-1,2,3,-4,5>`, where the corresponding absolute values `<1,2,3,4,5>` are in increasing order
* **_Cyclically Sorted sequence_** - monotonically increasing sequence rotated (left or right) by `k`, `k` modulo `n` != `0`, positions
  * E.g. `<3,4,5,1,2>`, which is obtained by rotating `<1,2,3,4,5>` left by two positions
* **_Bitonic sequence_** - an increasing contiguous subsequence followed by a contiguous decreasing subsequence
  * E.g. `<1,2,5,4,3>`, where `<1,2,5>` is increasing and `<5,4,3>` is decreasing

In the examples above, the **_less-than_** (`<`) operator is being used for ordering the elements in the sequence. This can be replaced with any [transitive](https://en.wikipedia.org/wiki/Transitive_relation) function that takes as arguments two elements and returns `true` or `false` indicating the relative ordering of those two elements in the sequence.

### Variants of the Basic Problem
Mild variants of this basic problem are ones in which the goal is to determine:
* the index where the key exists in the sequence
* the index of the smallest value greater than the key - this is also the **_successor_** of the key
* the index of the largest value smaller than the key - this is also the **_predecessor_** of the key
* the index in the sequence where key would have to be inserted to ensure that the resulting sequence is also sorted
* the index of the minimum/maximum valued key

In all these problems above, return `n` (or `-1`) if a valid index does not exist since valid indices are in the range `[0, n - 1]`.

### Sequences with Duplicates
The discussion so far has been restricted to sequences with all distinct elements. In the presence of duplicate elements, _strictly increasing_ ordering has to be relaxed to _non-decreasing_ ordering and _strictly decreasing_ ordering has to be relaxed to _non-increasing_ ordering.

Furthermore, when the sequence has duplicates, a few other variants can be added to the problems above:
* Find the smallest index (or the first occurence) of the key in the sequence
* Find the largest index (or the last occurence) of the key in the sequence
* Find the range of indices, which is just a tuple of the last two indices

### Other problems
* Given a sorted sequence of integers, find the first element that matches its position (0-indexed) in the sequence

## Summary
**Add info when the sequence has duplicates**

Sequence Type | Property | Key Insight | Performance | Difficulty
--- | --- | --- | --- | ---
Sorted | `a[i] <= a[i + 1], 0 <= i < (n - 1)` | NA | O(lg n) | Easy
Abs-sorted | `\|a[i]\| <= \|a[i + 1]\|, 0 <= i < (n - 1)`  | All the -ve keys are in sorted order and so are all the +ve keys | O(lg n) | Hard
Cyclically Sorted | `a[i] <= a[i + 1], 0 <= i < j and a[i] <= a[(i + 1) % n], j <= i < n, 0 < j < n - 1` | two monotonic sequences, mutually exclusive ranges | O(lg n) | Medium
Bitonic | `a[i] <= a[i + 1], 0 <= i < j and a[i] >= a[i + 1], j <= i < n - 2, 0 < j < n - 1` | two monotonic sequences,  inclusive ranges | O(lg n) | Medium

### C++ Standard library
* [`binary_search()`](http://en.cppreference.com/w/cpp/algorithm/binary_search)
* [`lower_bound()`](http://en.cppreference.com/w/cpp/algorithm/lower_bound)
* [`upper_bound()`](http://en.cppreference.com/w/cpp/algorithm/upper_bound)
* [`equal_range()`](http://en.cppreference.com/w/cpp/algorithm/equal_range)

### Links to Problems
* [Search Insertion Position](https://leetcode.com/problems/search-insert-position)
* [Search for Range of Indices](https://leetcode.com/problems/search-for-a-range)
* [Search in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array)
* [Search in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
* [Find Minimum in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
* [Find Minimum in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)

## Problems on 2D arrays
TBD
