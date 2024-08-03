#
# @lc app=leetcode.cn id=3225 lang=python3
#
# [3225] 网格图操作后的最大分数
#

# @lc code=start
class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        # 每列的前缀和（从上到下）
        col_sum = [list(accumulate(col, initial=0)) for col in zip(*grid)]

        # pre 表示第 j+1 列的黑格个数
        # dec=True 意味着第 j+1 列的黑格个数 (pre) < 第 j+2 列的黑格个数
        @cache
        def dfs(j: int, pre: int, dec: bool) -> int:
            if j < 0:
                return 0
            res = 0
            # 枚举第 j 列有 cur 个黑格
            for cur in range(n + 1):
                if cur == pre:  # 情况一：相等
                    # 没有可以计入总分的格子
                    res = max(res, dfs(j - 1, cur, False))
                elif cur < pre:  # 情况二：右边黑格多
                    # 第 j 列的第 [cur, pre) 行的格子可以计入总分
                    res = max(res, dfs(j - 1, cur, True) + col_sum[j][pre] - col_sum[j][cur])
                elif not dec:  # 情况三：cur > pre >= 第 j+2 列的黑格个数
                    # 第 j+1 列的第 [pre, cur) 行的格子可以计入总分
                    res = max(res, dfs(j - 1, cur, False) + col_sum[j + 1][cur] - col_sum[j + 1][pre])
                elif pre == 0:  # 情况四（凹形）：cur > pre < 第 j+2 列的黑格个数
                    # 此时第 j+2 列全黑最优（递归过程中一定可以枚举到这种情况）
                    # 第 j+1 列全白是最优的，所以只需考虑 pre=0 的情况
                    # 由于第 j+1 列在 dfs(j+1) 的情况二中已经统计过，这里不重复统计
                    res = max(res, dfs(j - 1, cur, False))
            return res
        # 枚举第 n-1 列有 i 个黑格
        return max(dfs(n - 2, i, False) for i in range(n + 1))
# @lc code=end

