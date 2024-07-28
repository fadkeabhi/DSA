# Target Sum

## Problem Description

You are given an integer array `nums` and an integer `target`. Your goal is to build mathematical expressions using the elements of `nums` and achieve the `target` sum.

To build an expression, you need to:

1. **Assign a symbol (+ or -) to each integer in `nums`.** 
2. **Concatenate all the integers (with their assigned symbols) to form the expression.**

For instance, given `nums = [2, 1]`, you could create expressions like "+2-1" or "-2+1".

Your task is to determine and return the **number of distinct expressions** that can be formed from `nums`, where each expression evaluates to the given `target`.

## Examples

### Example 1

**Input:** 
* `nums = [1, 1, 1, 1, 1]`
* `target = 3`

**Output:** 
* `5`

**Explanation:** There are 5 different ways to form expressions that sum to 3:

* -1 + 1 + 1 + 1 + 1 = 3
* +1 - 1 + 1 + 1 + 1 = 3
* +1 + 1 - 1 + 1 + 1 = 3
* +1 + 1 + 1 - 1 + 1 = 3
* +1 + 1 + 1 + 1 - 1 = 3

### Example 2

**Input:** 
* `nums = [1]`
* `target = 1`

**Output:**
* `1`

## Constraints

* 1 <= `nums.length` <= 20
* 0 <= `nums[i]` <= 1000
* 0 <= `sum(nums[i])` <= 1000
* -1000 <= `target` <= 1000 