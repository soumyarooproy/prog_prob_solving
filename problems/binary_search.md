# Binary Search Problems

## Problems on linear (or 1D) sequences

### Basic Problem
The simplest variant in this problem family is:

Given a linear sequence of **_distinct_** elements in sorted order and a key, determine if the key exists in the sequence; return `true` if it exists, `false` otherwise.

A recursive solution is:
```
binary_search(input_range, range_first, range_last, key)
{
    if (range_first == range_last)
        return input_range[range_first] == key
    range_mid = range_first + (range_last - range_first) / 2;
    if (input_range[range_mid] == key)
        return true
    if (input_range[range_mid] < key)
        return binary_search(input_range, range_first, range_mid - 1, key)
    return binary_search(input_range, range_mid + 1, range_last, key)
}
```

An iterative solution is:
```
binary_search(input_range, range_first, range_last, key)
{
    while (range_first < range_last) {
        range_mid = range_first + (range_last - range_first) / 2;
        if (input_range[range_mid] == key)
            return true
        if (input_range[range_mid] < key)
            range_last = range_mid - 1
        else
            range_first = range_mid + 1
    }
    return false
}
```

### Types of Sequences
The sequence ordering above need not always be in a sorted, i.e., monotonically increasing order.

They can also be among the following:
* **_Absolute Sorted sequence_** - the absolute values of the elements are in monotonically increasing order
  * E.g. `<-1,2,3,-4,5>`, where the corresponding absolute values `<1,2,3,4,5>` are in increasing order
* **_Cyclically Sorted sequence_** - monotonically increasing sequence rotated (left or right) by at least `1` and at most `(n - 1)` positions
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

### Sequence with Duplicates
The discussion so far has been restricted to sequences with all distinct elements. In the presence of duplicate elements, the term _strictly increasing_ above has to be relaxed to _non-decreasing_ and _strictly decreasing_ has to be relaxed to _non-increasing_.

Furthermore, when the sequence has duplicates, a few other variants can be added to the problems above:
* Find the smallest index (or the first occurence) of the key in the sequence
* Find the largest index (or the last occurence) of the key in the sequence
* Find the range of indices, which is just a tuple of the last two indices

### Other problems
* Given a sorted sequence of integers, find the first element that matches its position (0-indexed) in the sequence

## Summary
**Add info when the sequence has duplicates**

Ordering | Key Insight | Performance | Difficulty
--- | --- | --- | ---
Sorted | NA | O(lg n) | Easy
Abs-sorted | All the -ve keys are in sorted order and so are all the +ve keys | O(lg n) | Easy
Cyclically Sorted | Two monotonic sequences, mutually exclusive ranges | O(lg n) | Medium
Bitonic | Two monotonic sequences, potentially inclusive ranges | O(lg n) | Medium

### Binary Search Library Functions in Programming Languages
Function | C++ | Python | Java
--- | --- | --- | ---
Check if `x` is in the sorted sequence | [`binary_search()`](http://en.cppreference.com/w/cpp/algorithm/binary_search) | Use `bisect()` below | TBD
Find the largest index _not less than_ `x` | [`lower_bound()`](http://en.cppreference.com/w/cpp/algorithm/lower_bound) | [`bisect_left()`](https://docs.python.org/2/library/bisect.html) | TBD
Find the smallest index _greater than_ `x` | [`upper_bound()`](http://en.cppreference.com/w/cpp/algorithm/upper_bound) | [`bisect_right()` or `bisect()`](https://docs.python.org/2/library/bisect.html) | TBD
Find the range of indices _equal to_ `x` | [`equal_range()`](http://en.cppreference.com/w/cpp/algorithm/equal_range) | Combine `bisect_left()` and `bisect_right()` | TBD

### Links to Problems
* [Search Insertion Position](https://leetcode.com/problems/search-insert-position)
* [Search for Range of Indices](https://leetcode.com/problems/search-for-a-range)
* [Search in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array)
* [Find Minimum in Rotated Sorted Array without Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
* [Search in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
* [Find Minimum in Rotated Sorted Array with Duplicates](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)

## Problems on 2D arrays
TBD
