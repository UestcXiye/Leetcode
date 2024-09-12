#
# @lc app=leetcode.cn id=375 lang=python3
#
# [375] 猜数字大小 II
#

# @lc code=start
class Solution:
    def getMoneyAmount(self, n: int) -> int:

        # dfs(i, j) 表示区间 [i, j] 内获胜的最小现金数
        @cache
        def dfs(i:int, j:int) -> int:
            if i >= j:
                return 0
            res = inf
            for k in range(i, j + 1):
                res = min(res, max(dfs(i, k - 1), dfs(k + 1, j)) + k)
            return res
        
        return dfs(0, n)
# @lc code=end

