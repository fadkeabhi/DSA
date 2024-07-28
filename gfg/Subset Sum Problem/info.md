
# Subset Sum Problem

## Problem Description

Given an array `arr` of non-negative integers and an integer `sum`, determine if there is a subset of the given set with a sum equal to the given `sum`. 

## Examples

**Example 1:**

**Input:**

* `N = 6`
* `arr[] = {3, 34, 4, 12, 5, 2}`
* `sum = 9`

**Output:** `1`

**Explanation:**  There exists a subset `{4, 3, 2}` with a sum equal to 9.

**Example 2:**

**Input:**

* `N = 6`
* `arr[] = {3, 34, 4, 12, 5, 2}`
* `sum = 30`

**Output:** `0`

**Explanation:** There is no subset with a sum equal to 30.

## Your Task

Complete the function `isSubsetSum()` which takes the array `arr[]`, its size `N`, and an integer `sum` as input parameters. This function should return:

* `true`: If there exists a subset with the given `sum`.
* `false`: Otherwise.

**Note:** The driver code will handle input and output based on the boolean value returned by your function.

## Constraints:

* 1 <= `N` <= 100
* 1 <= `arr[i]` <= 100
* 1 <= `sum` <= 10^4

## Code Structure

```c++
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
    }
};
```

## Expected Time and Space Complexity

* **Expected Time Complexity:** O(`sum` * `N`)
* **Expected Auxiliary Space:** O(`sum` * `N`)
