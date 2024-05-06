/*
 * @lc app=leetcode.cn id=3130 lang=cpp
 *
 * [3130] 找出所有稳定的二进制数组 II
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        int memo[zero + 1][one + 1][2];
        memset(memo, -1, sizeof(memo));
        // 用 i 个 0，j 个 1 构造稳定数组的方案数，其中第 i+j 个位置要填 k
        function<int(int, int, int, int)> dfs = [&](int i, int j, int k, int limit) -> int
        {
            if (i == 0)
            { // 递归边界
                return k == 1 && j <= limit;
            }
            if (j == 0)
            { // 递归边界
                return k == 0 && i <= limit;
            }

            int &res = memo[i][j][k];
            if (res != -1)
                return res;
            if (k == 0)
            {
                res = ((long long)dfs(i - 1, j, 0, limit) + dfs(i - 1, j, 1, limit) +
                       (i > limit ? MOD - dfs(i - limit - 1, j, 1, limit) : 0)) %
                      MOD;
            }
            else
            {
                res = ((long long)dfs(i, j - 1, 0, limit) + dfs(i, j - 1, 1, limit) +
                       (j > limit ? MOD - dfs(i, j - limit - 1, 0, limit) : 0)) %
                      MOD;
            }
            return res;
        };
        return (dfs(zero, one, 0, limit) + dfs(zero, one, 1, limit)) % MOD;
    }
};
// @lc code=end
