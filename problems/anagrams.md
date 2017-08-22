# Problems involving Anagrams

1. Determine if two string are anagrams of each other
    * [Problem on Leetcode](https://leetcode.com/problems/valid-anagram)
1. Given a set of strings, group all the anagrams together
    * [Problem on Leetcode](https://leetcode.com/problems/group-anagrams)
1. Given a dictionary `D` and a query string `q`, determine if an anagram of `q` (which includes `q` itself) exists in `D`
   1. _Variant_: find all the words in `D` that are anagrams of `q`
   1. _Variant_: several query strings are coming in a streaming fashion
1. Given a string `s` and a non-empty string `p`, find all the start indices of `p`'s anagrams in `s`
    * [Problem on Leetcode](https://leetcode.com/problems/find-all-anagrams-in-a-string)
    
# Approaching The Solutions
All the approaches discussed here are fundamentally based on the idea of creating a *__signature__* that depends *__only__* on the set of characters comprising of the string *__and not__* on the ordering of those characters in the string.

## Sorting
Sorting maps all the anagrams of a string to a unique ordering of the characters in the string. If the string length is `n`, then a comparison-based sorting takes `O(n lg n)` time and each subsequent compares take `O(n)` time. Space complexity is `O(1)`. Although, for small values of `n`, say 15 or lower, which is true for 99% of the words in the English language, insertion sort is likely to be the fastest.

## Character Count
Represent each string as a hash table of character to the number of times it appears in the string. The space complexity is `O(m)` where `m` is the number of distinct characters in the string whose size is `n`. Time complexity is `O(n)` to construct the table and `O(m)` for any subsequent compares. The character to count table may also be represented as a BST (binary search tree), in which case
the time complexity is `O(n lg m)` to construct the BST and `O(m)` for subsequent compares.

## Hash Function
Compute the signature of a string `s` as a product of `p[s_i]^f[s_i]`, where:
* `s_i` is the `i`th character in `s`
* `f[s_i]` is the frequency of character `s_i` in `s`
* `p[s_i]` is a prime number uniquely mapped to the character `s_i`

Given a signature computed by this hash function, its (the signature's) prime factorization uniquely determines the characters and their frequency.

For example, for the alphabet set `{a, b, c}`, the following may be a valid character to prime number mapping
```
a -> 2, b -> 3, c -> 5
```    
A few example strings and their signatures are:
```
sig("abc")    = 2 * 3 * 5     = 30
sig("aaa")    = 2 ^ 3         = 8
sig("ababab") = 2 ^ 3 * 3 ^ 3 = 72
sig("bac")    = 3 * 2 * 5     = 30, which is the same as sig("abc")
```    

Inversely, the prime factorization of a signature, say `360`, is `2^3 * 3^2 * 5`, which implies that the signature is for a string that has `3` `a`'s, `2` `b`'s, and `1` `c`. No other combination of character counts can produce the signature of `360`.

### Caveat
The signature may overflow primitive integer data types provided by programming languages if the strings are long and/or the character set is large. For instance, for the English lowercase alphabet set `[a, z]`, if `z` is assigned the 26th prime number, `101`, a string comprised of 10 `z`'s will overflow a 64-bit unsigned integer data type.

# Solutions
1. Determine if two string are anagrams of each other
   * Sorting [C++ Code](../code/cpp/check_anagram.cc#L1-L10), [Java Code](../code/java/check_anagram.java)
   * Character Count [C++ Code](../code/cpp/check_anagram.cc#L12-L32), [Java Code](../code/java/check_anagram.java)
   * Hash Function [C++ Code](../code/cpp/check_anagram.cc#L34-L46), [Java Code](../code/java/check_anagram.java)
1. Given a set of strings, group all the anagrams together
   * Sorting [C++ Code](../code/cpp/group_anagrams.cc#L1-L20), [Java Code](../code/java/group_anagrams.java)
   * Character Count [C++ Code](../code/cpp/group_anagrams.cc#L22-L59), [Java Code](../code/java/group_anagrams.java)
   * Hash Function [C++ Code](../code/cpp/group_anagrams.cc#L60), [Java Code](../code/java/group_anagrams.java)
1. Given a dictionary `D` and a query string `q`, determine if an anagram of `q` (which includes `q` itself) exists in `D`
   * Sorting
   * Character Count
   * Hash Function
   1. _Variant_: find all the words in `D` that are anagrams of `q`
   1. _Variant_: several query strings are coming in a streaming fashion
1. Given a string `s` and a non-empty string `p`, find all the start indices of `p`'s anagrams in `s`
   * Sorting
   * Character Count
   * Hash Function
