#
# @lc app=leetcode.cn id=3218 lang=python3
#
# [3218] 切蛋糕的最小总开销 I
#

# @lc code=start
class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)

        m -= 1
        n -= 1
        @cache
        def dfs(i, j):
            if i == m and j == n:
                return 0
            if i == m:
                return dfs(i, j + 1) + verticalCut[j] * (i + 1)
            if j == n:
                return dfs(i + 1 , j) + horizontalCut[i] * (j + 1)
            
            return min(dfs(i, j + 1) + verticalCut[j] * (i + 1), dfs(i+ 1, j) + horizontalCut[i] * (j + 1))
        
        return dfs(0, 0)
# @lc code=end

