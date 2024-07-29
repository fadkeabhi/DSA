# Minimum Segment Cost

## Problem Statement

You are given an array `a` of `N` integers and asked to split the array `a` into consecutive segments such that each element of `a` belongs to exactly one segment and the sum of the cost of all segments is minimum.

We define the cost of some segment `t` as the sum of distances between the first and last occurrence for each unique element in the segment `t`.

Your task is to find the minimum possible total sum of the cost of all segments.

## Input Format

* The first line contains an integer `N`, denoting the number of elements in `a`.
* The next line contains an integer `K`, denoting the number of required consecutive segments.
* Each line of the `N` subsequent lines (where `0 <= i < N`) contains an integer describing `a[i]`.

## Task

Find the minimum possible total sum of the cost of all segments.

## Constraints

* 1 <= `N` <= 10^5
* 1 <= `K` <= 10^3
* 1 <= `a[i]` <= 10^9

## Output Format

Print the minimum possible total sum of the cost of all segments.