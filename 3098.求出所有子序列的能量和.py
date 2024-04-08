#
# @lc app=leetcode.cn id=3098 lang=python3
#
# [3098] 求出所有子序列的能量和
#

# @lc code=start
class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        nums.sort()

        # i 是当前下标
        # j 是还需要选多少个数
        # pre 是上一个选的数
        # min_diff 是目前选的数的能量（任意两数差的绝对值的最小值）
        @cache
        def dfs(i, j, pre, min_diff):
            # 即使剩下的数全选，也不足 j 个
            if j > i + 1:
                return 0
            if j == 0:
                return min_diff
            # 选
            res1 = dfs(i - 1, j - 1, nums[i], min(min_diff, pre - nums[i]))
            # 不选
            res2 = dfs(i - 1, j, pre, min_diff)
            return (res1 + res2) % MOD

        return dfs(len(nums) - 1, k, inf, inf)
# @lc code=end

