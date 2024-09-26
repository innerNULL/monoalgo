from typing import List, Optional


def partition(nums: List[int], k: int) -> int:
    pivot: int = nums[0]
    left: List[int] = []
    mid: List[int] = [pivot]
    right: List[int] = []
    for x in nums[1:]:
        if x < pivot:
            left.append(x)
        elif x > pivot:
            right.append(x)
        else:
            mid.append(x)
    if k <= len(right):
        return partition(right, k)
    elif k <= len(right) + len(mid):
        return mid[0]
    else:
        return partition(left, k - len(right) - len(mid))


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return partition(nums, k)

        
