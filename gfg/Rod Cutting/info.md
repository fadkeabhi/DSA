# Rod Cutting

## Problem Description

You are given a rod of length **N** inches and an array **price[]**, where **price[i]** represents the price of a piece of rod of length **i** inches. Your goal is to determine the **maximum value** you can obtain by cutting the rod into pieces and selling them.

**Note:** This problem uses 1-based indexing for the `price` array.

## Examples

**Example 1:**

```
Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output: 22 
```
**Explanation:** The maximum value is obtained by cutting the rod into two pieces: one of length 2 (price = 5) and one of length 6 (price = 17), resulting in a total price of 22.

**Example 2:**

```
Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
```
**Explanation:** The maximum value is obtained by cutting the rod into eight pieces of length 1 (price = 3 each), resulting in a total price of 24.

## Task

Your task is to complete the function `cutRod(A[], N)` which takes:

* `A[]`: The `price` array, where `A[i]` is the price of a rod of length `i`.
* `N`: The length of the rod.

The function should return the **maximum price** obtainable by cutting the rod.

## Constraints

* 1 ≤ **N** ≤ 1000
* 1 ≤ **A<sub>i</sub>** ≤ 10<sup>5</sup>

## Expected Time and Space Complexity

* **Expected Time Complexity:** O(N<sup>2</sup>)
* **Expected Auxiliary Space:** O(N)
``` 
