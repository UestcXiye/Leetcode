#
# @lc app=leetcode.cn id=3332 lang=python3
#
# [3332] 旅客可以得到的最多点数
#

# @lc code=start
class Solution:
    def maxScore(self, n: int, k: int, stayScore: List[List[int]], travelScore: List[List[int]]) -> int:
        
        @cache
        def dfs(i: int, j: int) -> int:
            if i == k:
                return 0

            # 留在当前城市 j
            res1 = dfs(i + 1, j) + stayScore[i][j]
            # 前往另外一座城市 d
            res2 = max(dfs(i + 1, d) + s for d, s in enumerate(travelScore[j]))
            
            return max(res1, res2)
        
        return max(dfs(0, i) for i in range(n))  # 枚举城市 i 作为起点
# @lc code=end

