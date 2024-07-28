# Next Permutation

## Problem Description

You are given an array of integers, `nums`. Your task is to find the **next permutation** of `nums` in lexicographical order.

**What is a permutation?** 
A permutation of an array is simply a rearrangement of its elements into a different order.

**What is lexicographical order?**
Lexicographical order is similar to the way words are arranged in a dictionary.  For arrays, it means comparing elements from left to right until a difference is found:
  *  If one array has a smaller element at the differing index, it comes before the other array lexicographically.
  * If all elements are the same, the arrays are equal in lexicographical order.

**Finding the Next Permutation:**
1. **Find the First Decreasing Element:** Starting from the right end of the array, find the first element `nums[i]` that is smaller than its next element `nums[i + 1]`.
2. **Find the Element to Swap:**  If you found a decreasing element in step 1, search from the right end of the array again (from `nums.length - 1` down to `i + 1`) for the smallest element that is larger than `nums[i]`. Let's call this element `nums[j]`.
3. **Swap:** Swap the elements at indices `i` and `j`.
4. **Reverse:** Reverse the subarray from index `i + 1` to the end of the array.

**Important Notes:**

* If you cannot find a decreasing element (meaning the array is sorted in descending order), the current permutation is the largest possible. In this case, you should rearrange the array into ascending order (the smallest possible permutation).
* You must perform the replacement **in-place**, meaning you should modify the original `nums` array directly without using additional space (except for constant extra memory).

## Examples

### Example 1

**Input:** `nums = [1,2,3]`
**Output:** `[1,3,2]`

**Explanation:** The next permutation of `[1,2,3]` is `[1,3,2]`.

### Example 2

**Input:** `nums = [3,2,1]`
**Output:** `[1,2,3]`

**Explanation:**  `[3,2,1]` does not have a lexicographically larger rearrangement. So, you need to rearrange it to the smallest possible order (ascending order), which is `[1,2,3]`.

### Example 3

**Input:** `nums = [1,1,5]`
**Output:** `[1,5,1]`

## Constraints

* 1 <= `nums.length` <= 100
* 0 <= `nums[i]` <= 100