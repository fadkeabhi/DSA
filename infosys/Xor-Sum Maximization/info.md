# Xor-Sum Maximization

## Problem Statement

Wael is well-known for how much he loves the bitwise XOR operation, while Kano is well-known for how much he loves to sum numbers. So, their friend Resli decided to make up a problem that would enjoy both of them. Resli wrote down an array A of length N, an integer K, and he defined a new function called Xor-sum as follows:

Xor-sum(x) = (x XOR A[0]) + (x XOR A[1]) + ... + (x XOR A[N-1])

Can you find the integer x in the range [0, K] with the maximum Xor-sum(N) value?

## Input Format

* The first line contains an integer N, denoting the number of elements in A.
* The next line contains an integer K, denoting the maximum value of x.
* Each line of the N subsequent lines (where 0 <= i < N) contains an integer describing A[i].

## Task

Find the integer x in the range [0, K] with the maximum Xor-sum(N) value.

## Constraints

* 1 <= N <= 10^5
* 0 <= K <= 10^9
* 0 <= A[i] <= 10^9

## Output Format

Print the maximum Xor-sum(N) value.