#
# @lc app=leetcode.cn id=3336 lang=python3
#
# [3336] 最大公约数相等的子序列数量
#

# @lc code=start
class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 1_000_000_007

        @cache
        def dfs(i: int, gcd1: int, gcd2: int) -> int:
            if i >= len(nums):
                return 1 if gcd1 == gcd2 else 0
            
            # 不选
            res1 = dfs(i + 1, gcd1, gcd2)
            # 把 nums[i] 加到第一个子序列中
            res2 = dfs(i + 1, gcd(gcd1, nums[i]), gcd2)
            # 把 nums[i] 加到第二个子序列中
            res3 = dfs(i + 1, gcd1, gcd(gcd2, nums[i]))

            return (res1 + res2 + res3) % MOD
        
        return (dfs(0, 0, 0) - 1) % MOD
# @lc code=end

