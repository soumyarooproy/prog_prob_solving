# Problem
* Given an array and two integers `k` and `x`, find the `k` closest elements to `x` in the array
* Variant: Given a *__sorted__* array and two integers `k` and `x`, find the `k` closest elements to `x` in the array
    * [Problem on Leetcode](https://leetcode.com/problems/find-k-closest-elements/description/)

The result should also be sorted in ascending order. If there is a tie, smaller elements are preferred.

Examples:
```
Example 1:
Input: [3,1,2,4,5], k=4, x=3
Output: [1,2,3,4], because this is smaller than the elements in [2,3,4,5], which is also a solution

Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
```

# Solution
The solution for the more generic problem is presented first. While the same solution works for the variant as well, a better solution for it is presented later.

## Generic Solution
The standard approach to the first problem (unsorted sequence) is to use a max-heap of size `k`:
* Replace the top of the heap with a new element `a` if `abs(a - x) < abs(top() - x)`
* The heap elements in sorted order is the desired solution - this can be done by extracting all the heap elements and reversing them
* Performance: `O(n lg k)` for the first step and `O(k lg k)` for extracting the heap elements in sorted order; space required is `O(k)`

### Code
* [C++ Code](../code/cpp/k_closest_in_unsorted_sequence.cc)
* [Java Code](../code/java/k_closest_in_unsorted_sequence.java)

## Solution to the Variant
The solution above also works if the input range is sorted but the drawback is that it fails to take advantage of the fact that the input is sorted.

### Solution Overview
Use binary search to find index `first` such that `a[first]` is the first value that is `>=x` (`lower_bound()` in C++ standard library) and index `last` such that `a[last]` is the first value that is `>x` (`upper_bound()` in C++ standard library). Then the candidate ranges are `k`-sized ranges starting with first as the last elem through one with `last - 1` as the first element.

For example:
```
<0, 1, 1, 3, 3, 3, 6, 7, 7, 9>, k = 4, x = 3
          ^        ^
    first = 3    last = 6

The candidate ranges and their diff sums with x = 3 are:
<0, 1, 1, 3> -> 7
<1, 1, 3, 3> -> 4
<1, 3, 3, 3> -> 2 <-- min
<3, 3, 3, 6> -> 3
<3, 3, 6, 7> -> 7
<3, 6, 7, 7> -> 11
```
### Accompanying details:
* Take care of array begin and end bounds to avoid running into out of bounds errors
* `last - first >= k` indicates that there are at least `k` occurrences of `x`. The answer in this case is `k` copies of `x`
* To compute the diff sum of `O(k)` ranges in `O(k)` time compute the sub-array diffs in rolling manner as follows:
    ```
    diff_sum([i+1, j+1]) = diff_sum([i, j]) - abs(a[i] - x) + abs(a[j + 1] - x)
    ```
* Note that diff sums for the ranges will be in decreasing-increasing order, i.e., they will decrease to the minimum and then keep increasing afterwards
* Performance: `O(lg n)` to find the `lower_bound` and `upper_bound` and `O(k)` to inspect the `O(k)` ranges. Space complexity is `O(1)`

### Code
* [C++ Code](../code/cpp/k_closest_in_sorted_sequence.cc)
* [Java Code](../code/java/k_closest_in_sorted_sequence.java)
