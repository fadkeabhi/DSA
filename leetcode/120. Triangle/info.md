# Triangle

## Problem Description

You are given a triangular array of integers. Your task is to find the minimum path sum from the top of the triangle to the bottom. 

**Movement Rule:** At each step, you may move to an adjacent number in the row below. Formally, if you are at index `i` in the current row, you can move to either index `i` or `i + 1` in the next row.

## Examples

### Example 1

**Input:** `triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]`

**Output:** `11`

**Explanation:**

The triangle looks like this:

```
   2
  3 4
 6 5 7
4 1 8 3 
```
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

### Example 2

**Input:** `triangle = [[-10]]`
**Output:** `-10`

## Constraints

* `1 <= triangle.length <= 200`
* `triangle[0].length == 1`
* `triangle[i].length == triangle[i - 1].length + 1`
* `-104 <= triangle[i][j] <= 104`

## Follow Up

Could you solve this problem using only O(n) extra space, where n is the total number of rows in the triangle? 

