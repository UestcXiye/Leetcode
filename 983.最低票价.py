#
# @lc app=leetcode.cn id=983 lang=python3
#
# [983] 最低票价
#

# @lc code=start
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:

        hashSet = set(days)
        @cache
        def dfs(i: int) -> int:
            if i <= 0:
                return 0
            
            if i not in hashSet:
                return dfs(i - 1)
            
            return min(dfs(i - 1) + costs[0], dfs(i - 7) + costs[1], dfs(i - 30) + costs[2])

        return dfs(days[-1])      
# @lc code=end

