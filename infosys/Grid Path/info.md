# Grid Path

## Problem Description

You are given a grid represented by a 2D integer array `a` with **N** rows and 2 columns. The value at `a[i][j]` represents the integer value in the cell at row `i` and column `j`.

Your goal is to find the path with the **maximum possible total sum** of cell values that a player can take, starting from any cell in the **first row** and moving to the **next row** under a specific condition:

* **Movement Rule:** From cell (i, j), the player can only move to a cell (i+1, j2) in the next row if the value in the destination cell is strictly greater than the value in the current cell:  `a[i+1][j2] > a[i][j]`. 

The player cannot move from the last row.

You need to print the maximum possible sum of cell values along any valid path modulo 10^9+7.

## Input

The input consists of:

* The first line: An integer **N**, representing the number of rows in the grid `a`.
* The second line: The integer **2**, representing the number of columns in the grid `a`.
* The next **N** lines: Each line `i` (0 ≤ i < N) contains 2 space-separated integers describing the values in row `a[i]`.

## Sample Cases

| Input | Output | Description |
|---|---|---|
| 2<br>2<br>1 2<br>3 4 | 6 | The optimal path is (1, 2) -> (2, 2). The answer is 2 + 4 = 6. |
| 2<br>2<br>7 8<br>5 5 | 8 | No moves are possible from the first row. Start at (1, 2) and collect just 8. |
| 3<br>2<br>1 1<br>2 2<br>3 3 | 6 | One optimal path is (1, 1) -> (2, 1) -> (3, 1). The answer is 1 + 2 + 3 = 6. |

## Output

A single integer: The maximum possible sum of values along any valid path, modulo 10^9+7.