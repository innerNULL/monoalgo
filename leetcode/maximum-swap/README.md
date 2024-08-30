## Links
* [Problem](https://leetcode.com/problems/maximum-swap/)


## Idea
```
 Most existing are too obscure fo this simple question.
 Here's a much easy-to-understand solution.

 The basic idea is:
 1. The ideal case is in original `nums`, the digits are 
    in the decend order, in this case we do not need swap.
 2. For non-ideal case, we should find the first digit to
    swap, then swap it with maximum digit ranked at later.
 3. To find the first digit to swap, we just compare each 
    digit in origin order with each difit in decending 
    sorted order, the first non-equal one is the first 
    digit to swap
```


## Description
670. Maximum Swap
Solved
Medium
Topics
Companies
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 

