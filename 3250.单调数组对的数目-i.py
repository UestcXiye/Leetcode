#
# @lc app=leetcode.cn id=3250 lang=python3
#
# [3250] 单调数组对的数目 I
#

# @lc code=start

# 记忆化搜索

class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        n = len(nums)
        
        @cache
        def dfs(i, a):
            if i == n - 1:
                return 1
            
            res = 0
            b = nums[i] - a
            for na in range(nums[i + 1] + 1):
                nb = nums[i + 1] - na
                if a <= na and b >= nb:
                    res += dfs(i + 1, na)
            
            return res % MOD
        
        res = 0
        for num in range(nums[0] + 1):
            res += dfs(0, num)
            res %= MOD
        
        return res
# @lc code=end

