#
# @lc app=leetcode.cn id=3117 lang=python3
#
# [3117] 划分数组得到最小的值之和
#

# @lc code=start

# 划分型 DP

class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        n = len(nums)
        m = len(andValues)

        @cache
        def dfs(i: int, j: int, and_: int) -> int:
            if m - j > n - i:  # 剩余元素不足
                return inf
            if j == m:  # 分了 m 段
                return 0 if i == n else inf
            and_ &= nums[i]
            if and_ < andValues[j]:  # 剪枝：无法等于 andValues[j]
                return inf
            res = dfs(i + 1, j, and_)  # 不划分
            if and_ == andValues[j]:  # 划分，nums[i] 是这一段的最后一个数
                res = min(res, dfs(i + 1, j + 1, -1) + nums[i])
            return res
        ans = dfs(0, 0, -1)
        return ans if ans < inf else -1
# @lc code=end

