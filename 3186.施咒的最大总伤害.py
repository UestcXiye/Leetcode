#
# @lc app=leetcode.cn id=3186 lang=python3
#
# [3186] 施咒的最大总伤害
#

# @lc code=start
class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        cnt = Counter(power)
        a = sorted(cnt.keys())

        @cache
        def dfs(i: int) -> int:
            if i < 0:
                return 0
            x = a[i]
            j = i
            while j > 0 and a[j - 1] >= x - 2:
                j -= 1
            res1 = dfs(i - 1) # 不选 a[i]
            res2 = dfs(j - 1) + x * cnt[x] # 选 a[i]
            return max(res1, res2)
        
        return dfs(len(a) - 1)
# @lc code=end

