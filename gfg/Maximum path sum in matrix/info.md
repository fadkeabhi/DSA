
# Maximum Path Sum in Matrix

## Problem Description

You are given a square matrix `mat` of size `n x n`, containing positive integers. Your goal is to find the path from the top row (row 0) to the bottom row (row n-1) that yields the **maximum path sum**.

**Movement Rules:**

From a cell `mat[r][c]`, you can only move to one of the following three cells in the row below:

* `mat[r+1][c]` (directly below)
* `mat[r+1][c-1]` (diagonally down-left)
* `mat[r+1][c+1]` (diagonally down-right)

You are free to start at any column in row 0 and end at any column in row n-1.

## Examples

**Example 1:**

```
Input: n = 2, mat = [[348, 391],[618, 193]]
Output: 1009
Explanation: The best path is 391 -> 618. It gives the sum = 1009.
```

**Example 2:**

```
Input: n = 2, mat = [[2, 2],[2, 2]]
Output: 4
Explanation: No matter which path is chosen, the output is 4. 
```

## Constraints

* 1 ≤ `n` ≤ 500
* 1 ≤ `mat[i][j]` ≤ 1000

## Expected Complexity

* **Time Complexity:** O(n * n)
* **Auxiliary Space:** O(n * n) 
