#
# @lc app=leetcode.cn id=3180 lang=python3
#
# [3180] 执行操作可获得的最大总奖励 I
#

# @lc code=start
class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        @cache
        def dfs(i: int) -> int:
            res = 0
            for x in rewardValues:
                if i < x:
                    res = max(res, dfs(i + x) + x)
            return res
        
        return dfs(0)
# @lc code=end

