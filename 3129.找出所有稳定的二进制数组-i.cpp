/*
 * @lc app=leetcode.cn id=3129 lang=cpp
 *
 * [3129] 找出所有稳定的二进制数组 I
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        int mx = max(zero, one);
        int memo[mx + 1][mx + 1][limit + 1];
        memset(memo, -1, sizeof(memo));
        // 还剩 i 个 0，j 个 1，已经连续使用了 count 个 i 对应的数字
        function<int(int, int, int)> dfs = [&](int i, int j, int count) -> int
        {
            if (i < 0 || j < 0)
                return 0;
            if (i == 0 && j == 0)
                return 1;
            int &res = memo[i][j][count];
            if (res != -1)
                return res;
            if (count == limit)
            {
                // 换另一个数字开始计数
                res = dfs(j - 1, i, 1) % MOD;
            }
            else
            {
                // 两种都可以
                res = (dfs(i - 1, j, count + 1) + dfs(j - 1, i, 1)) % MOD;
            }
            return res;
        };
        return dfs(zero, one, 0);
    }
};
// @lc code=end
