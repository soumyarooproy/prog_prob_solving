# Find missing or duplicate element from a set of elements

## Table of Contents
1. [Notes](#notes)
1. [Problem Overview](#overview)
    1. [Problem Sub-Category](#sub_category)
1. [Key Concepts](#keys)
1. [Algorithmic Performance](#performance)
1. [Solutions](#solutions)
1. [Advanced Tips: Beyond the O-notation](#advanced)

## Notes <a name="notes"></a>
1. In this text, 'set' refers to an unordered collection. This is in contrast to 'sequence', which implies some sort of ordering between the elements. Furthermore, 'set' refers to a collection which can have duplicates
1. The discussion on this page is primarily from the point-of-view of algorithmic efficiency (time and space complexity) and the logical complexity of the solutions
1. A fairly basic understanding of the underlying hardware is needed. In particular, understanding the following should suffice:
    1. binary encoding/representation of integral values
    1. most bitwise operations are extremely fast and efficient
1. Other hardware concepts such as memory hierarchy (and caching), core-microarchitecture, OS concepts, etc. are out of scope 
1. Parallel (multithreading/multiprocessing) or distributed computing environments are also out of scope

## Problem Category Overview <a name="overview"></a>
In this category of problems, usually one element (and sometimes two elements) in the set is (are) different than the rest in terms of how many times they appear in the set. The goal is to the find the unique number(s).

Examples include:
1. One element appears *__once__* and the rest appear *__twice__*
    * In `{0, 0, 2, 3, 3}`, `2` is being sought
1. One element appears *__twice__* and the rest appear *__once__*
    * In `{1, 3, 5, 3}`, `3` is being sought
1. One element appears *__once__* and the rest appear *__three times__*
    * In `{1, 7, 3, 3, 3, 7, 7}`, `1` is being sought
1. One element appears *__twice__* and the rest appear *__three times__*
    * In `{0, 2, 2, 2, 5, 0, 5, 5}`, `0` is being sought
1. Two elements appears *__once__* and the rest appear *__twice__*
    * In `{3, 4, 4, 5, 3, 6}`, `5` and `6` are being sought

### Sub-Category <a name="sub_category"></a>
A more restrictive sub-category of such problems includes the restriction that the numbers are in the range `0` to `O(n)`, where `n` is the cardinality of the input set. The goal again is to find the unique number, which in contrast to the previous set of problems, may include a missing number. However, as described later, most of these problems may be transformed into one of the ones above.

Examples are:
1. An n-element set is comprised of all distinct numbers in the range `0` and `n`, which means that one number is missing
    * `n = 4` and input set `{3, 0, 1, 4}`; `2` is missing
1. In an n-element set, which are comprised of numbers in the range `0` and `n - 1`, all but one entry appears once; one appears twice (which also means that one number between `0` and `n - 1` is missing)
    * `n = 5` and input set `{3, 0, 1, 4, 3}`; `2` is missing and `3` appears twice
1. In an n-element set, comprised of all but one distinct numbers in the range 0 and n - 2, which means that one number is duplicate
    * `n = 6` and input set `{3, 0, 1, 4, 2, 1}`; `1` is duplicate

## Key Concepts <a name="keys"></a>
1. Bitwise operations, most importantly XOR (^)
    * Recall that `x ^ x = 0` and `x ^ 0 = x`, which implies that XOR'ing a pair (or an even number) of a number will result in `0`
1. Binary representation
    * Consider counting the `1`s and `0`s at each bit position over all the numbers in the set. For instance, the binary representation of a number, say `5` is `101`. If there are two `5`s in the set, there are two `1`s in the 0th bit position and two `1`s in the 3rd bit position. If there is one `6` (`110`) along with the two `5`s, there will end up being three `1`s in the 0th bit position, one `1` in the 2nd bit position, and two `1`s in the 3rd bit position. So, `6` that exists by itself, will contribute an odd number of `1`'s to the counts of all the bit positions where it has a `1` in its binary representation
1. Arithmetic
    * The sum of the first `n` natural numbers is `n * (n + 1) / 2`. The problems in which exactly one number is missing or is duplicate in the range `[0, n]` (or anything similar) can be solved by comparing this quantity with the sum of all the numbers in the set. This approach has the caveat of an overflow, which can be mitigated by using a higher precision integer type for storing the sum, e.g. use 64-bit int if the inputs are 32-bit ints

### Sorting is an Overkill
Rearranging the elements in a sorted order solves all of these problems but is usually an overkill. For instance, `{0, 2, 2, 2, 5, 0, 5, 5}` becomes `<0, 0, 2, 2, 2, 5, 5, 5>` after sorting. A second pass on this sorted sequence looking for at least one and fewer than three occurences of an element reveals that `0` is the answer. This is true for even the more restrictive problem sub-category, where linear sorting algorithms, *__radix sort__* or *__counting sort__*, may be applicable.

## Algorithmic Performance <a name="performance"></a>
Almost all the problems in this category can be solved in *__linear time__* using *__constant space__*. Sometimes, there may be a need to perform multiple passes over the input. Very rarely, there is 

## Solutions <a name="solutions"></a>
1. **One element appears _once_ and the rest appear _twice_**
1. **One element appears _odd number of times_ and the rest appear _even number of times_**
    * Both the problems (the second is a more generic version of the first) are among the simplest of these problems and can be solved using the same approach. The unique element (appearing once in the first problem and an odd number of times in the second problem, respectively) can be obtained by just XOR'ing all the elements because all elements in pairs will zero each other out when XOR'ed.
1. **An `n`-element set is comprised of all distinct numbers in the range `0` and `n`, _which means that one number in that range is missing_**
1. **In an `n`-element set, comprised of all but one distinct numbers in the range `0` and `n - 2`, _which means that one number in that range appears twice_**
    * Both these problems can be solved using the same approach. For the first problem, if the input set is extended with all the elements in the range `[0, n]`, it turns into the first problem. The same extension turns the second problem into a very mild variant of first problem. The duplicate element appears _three times instead of once_.
    * Example, for `n = 4` and input set `{3, 0, 1, 4}`, extending the input set with the range `[0, 4]` results in `{3, 0, 1, 4, 0, 1, 2, 3, 4}`, in which all elements except `2` appear in pairs
    * For `n = 6` and input set `{3, 0, 1, 4, 2, 1}`, the same extension results `{3, 0, 1, 4, 2, 1, 0, 1, 2, 3, 4}`, which has all the elements in pairs except for `1` which appears three times
    * Note that there is no need to actually extend the input set with the ranges. Just the XOR of all the elements in the range `[0, n]` (or `[0, n - 2]`) is needed
1. **One element appears _once_ and the rest appear _three times_**
1. **One element appears _twice_ and the rest appear _three times_**
    * These problems require more work
    * Count the number of `1`'s at each bit position over all the numbers in the set to figure out which element does not appear exactly three times. For instance, consider the set `{1, 7, 3, 3, 3, 7, 7}`:
        * The three `7`'s contribute three `1`s in the 0th bit position, three `1` in the 2nd bit position, and three `1`s in the 3rd bit position
        * The three `3`'s contribute three `1`s in the 0th bit position and three `1` in the 2nd bit position bringing the total to six `1`s in the 0th bit position, six `1` in the 2nd bit position, and three `1`s in the 3rd bit position
        * Finally, the one `1` adds only one `1` in the 0th bit position bringing the total count to seven `1`s in the 0th bit position, six `1` in the 2nd bit position, and three `1`s in the 3rd bit position
        * Dividing each of these counts by `3` and taking the remainder gives the number of `1`'s contributed by the 
    * In `{0, 2, 2, 2, 5, 0, 5, 5}`, `0` is being sought
1. **One element appears _twice_ and the rest appear _once_**
    * Given the set `{1, 3, 5, 3}`, maintain two
1. **Two elements appear _once_ and the rest appear _twice_**
    * Example: In `{3, 4, 4, 5, 3, 6}`, `5` and `6` are being sought
1. **In an n-element set, which are comprised of numbers in the range 0 and n - 1, all but one entry appears once; one appears twice**
    * This is one of the harder problems in this category
    * In principal, if the input set is extended with all the elements in the range `[0, n]`, it turns into the first problem.
For `n = 5` and input set `{3, 0, 1, 4, 3}`, extending the input set with the range `[0, 4]` results in `{3, 0, 1, 4, 3, 0, 1, 2, 3}`

## Advanced Tips: Beyond the O-notation <a name="advanced"></a>
Aside from the O-notation of the solution, the following aspects of the
solution will impact performance
1. Mutability (or lack thereof) of the input set
    * If the input set is not mutable and the solution involves modifying the
      input elements or reordering them, then an O(n) auxilary space will be
      needed
1. Minimize the number of writes
    * Writes (to memory) will slow down code performance
    * Do NOT sort till you really have to
1. Write cache-friendly code
    
