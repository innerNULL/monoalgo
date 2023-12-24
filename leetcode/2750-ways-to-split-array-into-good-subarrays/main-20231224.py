import sys


class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return 1 if nums[0] == 1 else 0
        else:
            pass

        first_one_idx: int = 0
        while first_one_idx < len(nums):
            if nums[first_one_idx] == 1:
                break
            else:
                first_one_idx += 1

        if first_one_idx == len(nums):
            return 0
        
        final_one_idx: int = len(nums) - 1
        while final_one_idx >= 0:
            if nums[final_one_idx] == 1:
                break
            else:
                final_one_idx -= 1
        
        intervals_zero_cnt: List[int] = []
        last_one_idx: int = first_one_idx
        curr_idx: int = last_one_idx + 1
        while curr_idx <= final_one_idx:
            if nums[curr_idx] == 1:
                intervals_zero_cnt.append(curr_idx - last_one_idx)
                last_one_idx = curr_idx
            curr_idx += 1
        
        print(intervals_zero_cnt)
        
        out: int = 1
        mod: int = pow(10, 9) + 7
        for x in intervals_zero_cnt:
            out = (out * x) % mod
        return out

        
