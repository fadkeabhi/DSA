# Perfect Sum Problem

## Problem Statement

Given an array `arr` of size `n` containing non-negative integers and an integer `sum`, your task is to count the total number of subsets within the array that have a sum equal to the given `sum`.

**Important:** The answer can be very large, so you need to output the answer modulo 10^9 + 7.

## Examples

**Example 1:**

```
Input: 
n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
Output: 
3
Explanation: 
The subsets {5, 2, 3}, {2, 8}, and {10} have a sum of 10.
```

**Example 2:**

```
Input: 
n = 5, arr = [2, 5, 1, 4, 3], sum = 10
Output: 
3
Explanation: 
The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} have a sum of 10.
```

## Constraints

* 1 ≤ `n * sum` ≤ 10^6
* 0 ≤ `arr[i]` ≤ 10^6

## Expected Complexity

* **Time Complexity:** O(n * sum)
* **Auxiliary Space:** O(n * sum)
