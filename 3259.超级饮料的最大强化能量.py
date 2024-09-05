#
# @lc app=leetcode.cn id=3259 lang=python3
#
# [3259] 超级饮料的最大强化能量
#

# @lc code=start
class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        n = len(energyDrinkA)
        energyDrink = (energyDrinkA, energyDrinkB)

        @cache  # 缓存装饰器，避免重复计算 dfs 的结果（记忆化）
        def dfs(i: int, j: int) -> int:
            if i < 0:
                return 0
            res1 = dfs(i - 1, j) + energyDrink[j][i]
            res2 = dfs(i - 2, j ^ 1) + energyDrink[j][i]
            return max(res1, res2)
        
        return max(dfs(n - 1, 0), dfs(n - 1, 1))
# @lc code=end

