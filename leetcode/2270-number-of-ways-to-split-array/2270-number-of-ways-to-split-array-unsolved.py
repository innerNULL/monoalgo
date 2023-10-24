class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        ways: int = 0
        size: int = len(nums)
        left_sum: List[int] = [0] * size
        right_sum: List[int] = [0] * size
        all_sum: int = sum(nums)
        for i in range(size - 1):
            left_sum[i] = nums[i] if i == 0 else nums[i] + left_sum[i - 1]
            right_sum[i] = all_sum - left_sum[i]
            if left_sum[i] >= right_sum[i]:
                ways += 1
        return ways
