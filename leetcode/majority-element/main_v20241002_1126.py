import math


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums = sorted(nums)
        return nums[math.floor(len(nums) / 2)]
