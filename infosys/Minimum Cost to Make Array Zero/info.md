# Minimum Cost to Make Array Zero

A subarray of array A is a segment of contiguous elements in array A. You can apply the following operations as many times as you like:

* Choosing a subarray [L, R] and subtracting 1 from each element in this subarray. The cost of this operation is X.
* Choosing an index i such that A[i] is positive, and setting A[i] = 0. The cost of this operation is Y.

Your task is to make all the elements equal to 0 and find the minimum cost to do so.

## Input Format

* The first line contains an integer N, denoting the number of elements in A.
* The next line contains an integer X, denoting the cost of the first operation.
* The next line contains an integer Y, denoting the cost of the second operation.
* Each line i of the N subsequent lines (where 1 <= i <= N) contains an integer describing A[i].

## Constraints

* 1 <= N <= 10^5
* 1 <= X <= 10
* 1 <= Y <= 10^4
* 1 <= A[i] <= 10^8

## Sample Input 1

1
1
10
1

## Sample Output 1

1

## Explanation

N = 1, X = 1, Y = 10, A = [1]. The optimal solution is to perform one operation of the first type on the subarray [1, N].

## Sample Input 2

3
1
10
1 2 3

## Sample Output 2

6

## Explanation

N = 3, X = 1, Y = 10, A = [1, 2, 3]. The optimal solution is to perform two operations of the first type on the subarrays [1, 2] and [2, 3].