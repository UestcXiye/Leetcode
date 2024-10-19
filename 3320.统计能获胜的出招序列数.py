#
# @lc app=leetcode.cn id=3320 lang=python3
#
# [3320] 统计能获胜的出招序列数
#

# @lc code=start
class Solution:
    def countWinningSequences(self, s: str) -> int:
        MOD = 1_000_000_007

        def getScore(a: str, b: str) -> int:
            if a == "F" and b == "W":
                return 1
            if b == "F" and a == "W":
                return -1
            if a == "W" and b == "E":
                return 1
            if b == "W" and a == "E":
                return -1
            if a == "E" and b == "F":
                return 1
            if b == "E" and a == "F":
                return -1
            
            return 0
        
        @cache
        def dfs(i: int, j: int, ban: int) -> int:
            if -j > i:  # 必败
                return 0
            if j > i + 1:  # 必胜
                return pow(2, i + 1, MOD)

            res = 0
            for cur in "FWE":
                if cur == ban:
                    continue
                score = getScore(s[i], cur)
                res += dfs(i - 1, j + score, cur)
            return res % MOD

        return dfs(len(s) - 1, 0, -1)

# @lc code=end

