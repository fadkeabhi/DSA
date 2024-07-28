# Permutation Sequence

## Problem Description

Given a set of integers `{1, 2, 3, ..., n}`, there are a total of `n!` (n factorial) unique permutations.

Your task is to write an algorithm that, given `n` and `k`, returns the **k-th permutation sequence** when you list all the permutations in lexicographical order.

## Examples

### Example 1

**Input:** `n = 3, k = 3`
**Output:** `"213"`

**Explanation:**
The list of permutations for n = 3 in order is:
1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Therefore, the 3rd permutation sequence is "213".

### Example 2

**Input:** `n = 4, k = 9`
**Output:** `"2314"`

### Example 3

**Input:** `n = 3, k = 1`
**Output:** `"123"`

## Constraints

* 1 <= `n` <= 9
* 1 <= `k` <= `n!` 