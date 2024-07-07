#
# @lc app=leetcode.cn id=3196 lang=python3
#
# [3196] 最大化子数组的总成本
#

# @lc code=start
class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:

        @cache
        def dfs(i: int) -> int:
            if i < 0:
                return 0
            if i == 0:
                return nums[0]
            return max(dfs(i - 1) + nums[i], dfs(i - 2) + nums[i - 1] - nums[i])
        return dfs(len(nums) - 1)
# @lc code=end

