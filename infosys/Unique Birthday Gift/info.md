# Unique Birthday Gift

## Problem Description

Your friend Alex wants to give you an interesting birthday present: a list of all integer arrays with specific properties. 

He chooses two numbers, **N** and **K**.  He then generates all possible arrays of length **K** (represented as `a[1], a[2], ..., a[K]`) with the following conditions:

* Each element `a[i]` in the array is an integer between 1 and **N** (inclusive).
* For every element in the array (except the first), `a[i+1]` is divisible by `a[i]`, where 1 < i <= **K**.

Your task is to determine how many unique arrays Alex writes down. Since this number can be very large, you need to print the result modulo 10000.

## Input

The input consists of two lines:

* The first line contains an integer **N**, representing the maximum possible value in the arrays.
* The second line contains an integer **K**, representing the length of the arrays.

## Sample Cases

| Input | Output | Description |
|---|---|---|
| 2<br>1 | 2 |  The required length is 1, so there are only two possible arrays: `[1]` and `[2]`. |
| 2<br>2 | 3 |  All possible arrays are `[1, 1]`, `[1, 2]`, `[2, 2]`.<br> `[2, 1]` is invalid because 1 is not divisible by 2. |
| 3<br>2 | 5 | All possible arrays are `[1, 1]`, `[1, 2]`, `[1, 3]`, `[2, 2]`, `[3, 3]`. |

## Output

A single integer representing the number of unique arrays modulo 10000.