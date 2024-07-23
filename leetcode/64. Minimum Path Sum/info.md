
# Minimum Path Sum

## Problem Description

Given a **m x n** grid filled with **non-negative numbers**, you need to find a path from the **top left corner** to the **bottom right corner** that minimizes the sum of all numbers along its path.

**Constraint:** You can only move either **down** or **right** at any point in time.

## Examples

### Example 1
![Image](image.png)


**Input:** 

grid = [[1,3,1],
        [1,5,1],
        [4,2,1]]


**Output:** 7

**Explanation:** The path `1 → 3 → 1 → 1 → 1` minimizes the sum to 7.

### Example 2

**Input:** 

grid = [[1,2,3],
        [4,5,6]]


**Output:** 12

## Constraints

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 200`
* `0 <= grid[i][j] <= 200`

