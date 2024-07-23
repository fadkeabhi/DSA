# Block Placement Queries

## Problem Description

You are given an **infinite number line** starting at 0 and extending towards the positive x-axis. You need to process a series of queries related to placing obstacles and checking if blocks of certain sizes can fit on the line.

The queries are provided in a 2D array called `queries`. Each query `queries[i]` can be of two types:

1. **Type 1: Build an Obstacle** 
   - `queries[i] = [1, x]` 
   - This query instructs you to build an obstacle at a distance `x` from the origin (0). 
   - It's guaranteed that there won't be an existing obstacle at distance `x` when this query is encountered.

2. **Type 2: Check Block Placement**
   - `queries[i] = [2, x, sz]`
   - This query asks you to check if it's possible to place a block of size `sz` anywhere within the range `[0, x]` on the number line.
   - The block must entirely lie within the range `[0, x]`.
   - A block cannot intersect with any obstacles but is allowed to touch them.
   - **Important:** You are only checking if placement is possible; you don't actually place the block. Each query is independent.

Your task is to return a boolean array `results` where `results[i]` is:

* `true` if you can place the block specified in the i-th query of type 2.
* `false` otherwise.

## Examples

### Example 1

**Input:** 
`queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]`

**Output:** 
`[false,true,true]`

**Explanation:**

1. `[1, 2]`: Place an obstacle at `x = 2`. 
2. `[2, 3, 3]`: A block of size 3 **cannot** be placed before `x = 3` (the obstacle is in the way).
3. `[2, 3, 1]`: A block of size 1 **can** be placed before `x = 3` (e.g., between `x = 2` and `x = 3`).
4. `[2, 2, 2]`: A block of size 2 **can** be placed before `x = 2` (from `x = 0` to `x = 2`).

### Example 2

**Input:** 
`queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]`

**Output:** 
`[true,true,false]`

**Explanation:**

1. `[1, 7]`: Place an obstacle at `x = 7`.
2. `[2, 7, 6]`: A block of size 6 **can** be placed before `x = 7`.
3. `[1, 2]`: Place an obstacle at `x = 2`.
4. `[2, 7, 5]`: A block of size 5 **can** be placed before `x = 7` (e.g., between `x = 2` and `x = 7`).
5. `[2, 7, 6]`: A block of size 6 **cannot** be placed before `x = 7` (the obstacles at `x = 2` and `x = 7` prevent it).

## Constraints

* `1 <= queries.length <= 15 * 10^4`
* `2 <= queries[i].length <= 3`
* `1 <= queries[i][0] <= 2`
* `1 <= x, sz <= min(5 * 10^4, 3 * queries.length)`
* For type 1 queries, no obstacle will exist at distance `x` when the query is asked.
* There will be at least one query of type 2. 